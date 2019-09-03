class Solution 
{
    public:
    	int max_elements_to_right(vector< int > &sorted_vec, int val)
    	{
    		auto iter = lower_bound(sorted_vec.begin(), sorted_vec.end(), val);
    		int distance_from_end = distance(sorted_vec.begin(), iter);
    		return distance_from_end;
    	}

    	void insert_into_sorted_vec(vector< int > &sorted_vec, int val)
    	{
    		sorted_vec.push_back(val);
	 		sort(sorted_vec.begin(), sorted_vec.end());
    	}

    	vector<int> countSmaller(vector<int>& nums) 
        {
        	vector< int > solution_vec(nums.size());
        	vector< int > sorted_vec;
        	for(int i = nums.size() - 1; i >= 0; i--)
        	{
        		if(not sorted_vec.empty())
        		{
        			solution_vec[i] = max_elements_to_right(sorted_vec, nums[i]);
        		}
        		else
        		{
        			solution_vec[i] = 0;
        		}
        		insert_into_sorted_vec(sorted_vec, nums[i]);
        	}
        	return solution_vec;
        }
};