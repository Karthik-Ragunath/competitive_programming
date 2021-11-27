// https://leetcode.com/problems/lfu-cache/
class Comparator
{
	public:
		bool operator()(const pair< int, pair< int, int > > pair_1, const pair< int, pair< int, int > > pair_2) const
		{
			if(pair_1.second.second > pair_2.second.second)
			{
				return true;
			}
			return false;
		}
};

class LFUCache 
{
	public:
	    int capacity;
	    unordered_map< int, pair< int, pair< int, set< pair< int, pair< int, int > > > >::iterator > > key_hash;
	    set< pair< int, pair< int, int > >, Comparator > set_comparator;
	    LFUCache(int capacity) 
	    {
	        capacity = capacity;
	    }
	    
	    int get(int key) 
	    {
	    	auto set_find_iter = key_hash.find(key);
	   		if(set_find_iter == key_hash.end())
	   		{
	   			return -1;
	   		}
	   		update_cache(key);
	   		return set_find_iter -> second.first;
	    }
	    
	    void put(int key, int value) 
	    {
	    	auto find_iter = key_hash.find(key);
	    	if(find_iter != key_hash.end())
	    	{
	    		pointer_set = find_iter -> second.second.second;
	    		int new_frequency = find_iter -> second.second.first + 1;
	    		set_comparator.erase(pointer_set);
	    		set_comparator.insert(make_pair(find_iter -> first, make_pair(find_iter -> second.first, new_frequency)));
	    		auto set_find_iter = set_comparator.find(find_iter -> first, make_pair(value, new_frequency));
	    		if(set_find_iter != set_comparator.end())
	    		{
	    			key_hash.erase(key);
	    			key_hash.insert(make_pair(key, make_pair(value, make_pair(new_frequency, set_find_iter))));
	    		}
	    	}
	    	else
	    	{
	    		if(set_comparator.size() == capacity)
	    		{
	    			auto last_element_iter = (set_comparator.rbegin());
	    			set_comparator.erase((set_comparator.end() - 1));
	    		}
    			set_comparator.insert(make_pair(key, make_pair(value, 1)));
    			auto set_find_iter = set_comparator.find(make_pair(key, make_pair(value, 1)));
    			if(set_find_iter != set_comparator.end())
    			{
    				key_hash.insert(make_pair, make_pair(value, make_pair(1, set_find_iter)));
    			}
	    	}
	    }

	    void update_cache(int key)
	    {
	    	auto find_iter = key_hash.find(key);
	    	auto pointer_set = find_iter -> second.second.second;
	    	set_comparator.erase(pointer_set);
	    	int new_frequency = find_iter -> second.second.first + 1;
	    	int value = find_iter -> second.first;
	    	set_comparator.insert(make_pair(key, make_pair(makenew_value, new_frequency)));
	    	auto set_find_iter = set_comparator.find(make_pair(key, new_value));
	    	if(set_find_iter != set_comparator.end())
	    	{
	    		key_hash.erase(key);
	    		key_hash.insert(make_pair(key, make_pair(value, make_pair(new_frequency, set_find_iter))));
	    	}
	    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */