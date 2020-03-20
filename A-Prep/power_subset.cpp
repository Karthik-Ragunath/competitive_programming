// https://leetcode.com/problems/subsets/
class Solution 
{
	public:
    	vector<vector<int>> subsets(vector<int>& nums) 
    	{
        	vector< vector< int > > dp;
        	vector< int > cur_vec;
        	power_subset(nums, cur_vec, dp, 0);
        	return dp;
    	}

    	void power_subset(vector< int > &nums, vector< int > &cur_vec, vector< vector< int > > &dp, int index)
    	{
    		dp.push_back(cur_vec);
    		for(int i = index; i < nums.size(); i++)
    		{
    			cur_vec.push_back(nums[i]);
    			power_subset(nums, cur_vec, dp, i + 1);
    			cur_vec.pop_back();
    		}
    	}
};