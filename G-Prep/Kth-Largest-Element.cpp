class Comparator
{
	public:
		bool operator()(const int val_1, const int val_2) const
		{
			if(val_1 > val_2)
			{
				return true;
			}
			return false;
		}
};

class Solution 
{
	public:
    	int findKthLargest(vector<int>& nums, int k) 
    	{
        	multiset< int, Comparator > max_bst;
        	int nums_size = nums.size();
        	for(int i = 0; i < nums_size; i++)
        	{
        		if(i + 1 > k)
        		{
        			int current_kth_element = *(max_bst.rbegin());
        			if(nums[i] > current_kth_element)
        			{
        				max_bst.erase(--max_bst.end());
                        // max_bst.erase(max_bst.rbegin()); // Doesnt work
        				max_bst.insert(nums[i]);
        			}
        		}
        		else
        		{
        			max_bst.insert(nums[i]);
        		}
        	}
            // cout << "Size: " << max_bst.size() << "\n";
        	return *(--max_bst.end());
    	}
};