class LRUCache 
{
	public:
		int queue_capacity;
		list< int > least_recentlty_used_keys;
		unordered_map< int, pair< int, list< int >::iterator > > hash_table;
    	
    	LRUCache(int capacity) 
    	{
       		queue_capacity = capacity;
    	}
    
    	int get(int key) 
    	{
        	auto find_iter = hash_table.find(key);
        	if(find_iter == hash_table.end())
        	{
        		return -1;
        	}
        	update_cache(find_iter);
        	return find_iter -> second.first;	
    	}
    
    	void put(int key, int value) 
    	{
            // cout << "Capacity: " << queue_capacity << "\n";
        	auto find_iter = hash_table.find(key);
        	if(find_iter != hash_table.end())
        	{
        		find_iter -> second.first = value;
        		update_cache(find_iter);
        	}
        	else
        	{
        		if(least_recentlty_used_keys.size() >= queue_capacity)
        		{
        			int last_element_key = least_recentlty_used_keys.back();
        			least_recentlty_used_keys.pop_back();
        			hash_table.erase(last_element_key);
        			least_recentlty_used_keys.push_front(key);
        			hash_table.insert(make_pair(key, make_pair(value, least_recentlty_used_keys.begin())));
        		}
        		else
        		{
                    // cout << "Key: " << key << " Value: " << value << "\n";
        			least_recentlty_used_keys.push_front(key);
        			hash_table.insert(make_pair(key, make_pair(value, least_recentlty_used_keys.begin())));
        		}
        	}
    	}

    	void update_cache(unordered_map< int, pair< int, list< int >::iterator > >::iterator hash_iter)
    	{
    		least_recentlty_used_keys.erase(hash_iter -> second.second);
    		least_recentlty_used_keys.push_front(hash_iter -> first);
    		hash_iter -> second.second = least_recentlty_used_keys.begin();
    	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */