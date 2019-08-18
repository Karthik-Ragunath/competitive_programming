class PriorityQueueComparator
{
	bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
	{
		if(pair_1.second > pair_2.second)
		{
			return true;
		}
		else
		{
			if(pair_1.second == pair_2.second and pair_1.first > pair_2.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};

class SetComparator
{
	bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
	{
		if(pair_1.second < pair_2.second)
		{
			return true;
		}
		else
		{
			if(pair_1.second == pair_2.second and pair_1.first < pair_2.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};

class LRUCache 
{
	public:
		int queue_capacity = 0;
		priority_queue< pair< int, int >, Comparator > lru_cache_queue;
		unordered_map< int, int > cache;
    	LRUCache(int capacity) 
    	{
        	queue_capacity = capacity;
    	}
    
    	int get(int key) 
    	{
    		auto find_iter = cache.find(key);
        	if(find_iter != cache.end())
        	{
        		return find_iter -> second;
        	}
        	else
        	{
        		return -1;
        	}
    	}
    
    	void put(int key, int value) 
    	{
        	auto find_iter = cache.find(key);
        	if(find_iter != cache.end())
        	{
        		cache.erase(find_iter);
        		cache.insert(make_pair(key, value));
        	}
        	else
        	{
        		if(lru_cache_queue.size() >= queue_capacity)
        		{

        		}
        	}
    	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */