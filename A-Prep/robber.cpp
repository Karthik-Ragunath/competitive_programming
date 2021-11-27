// https://leetcode.com/problems/house-robber/submissions/
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return 0;
        }
        int nums_count = nums.size();
        vector< int > max_vals(nums_count);
        for(int i = 0; i < nums_count; i++)
        {
        	if(i == 0)
        	{
        		max_vals[i] = nums[i];
        	}
        	else if(i == 1)
        	{
        		max_vals[i] = max(nums[i - 1], nums[i]);
        	}
        	else
        	{
        		max_vals[i] = max((max_vals[i - 2] + nums[i]), max_vals[i - 1]);
        	}
        }
        return max_vals[nums_count - 1];
    }
};