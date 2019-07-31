class Solution 
{
	public:
    	int maxCoins(vector<int>& nums) 
    	{
    		int nums_size = nums.size();
    		if(nums_size == 0)
    		{
    			return 0;
    		}
        	vector< vector< int > > dp(nums_size, vector< int >(nums_size));
        	for(int len = 1; len <= nums_size; len++)
        	{
        		for(int i = 0; i < (nums_size - len + 1); i++)
        		{
        			int j = i + len - 1;
        			for(int k = i; k <= j; k++)
        			{
        				int left_after_popping_last = 1, right_after_popping_last = 1;
        				if(i != 0)
        				{
        					left_after_popping_last = nums[i - 1];
        				}
        				if(j != nums_size - 1)
        				{
        					right_after_popping_last = nums[j + 1];
        				}
        				int max_left_part = 0, max_right_part = 0;
        				if(i != k)
        				{
        					max_left_part = dp[i][k - 1];
        				}
        				if(j != k)
        				{
        					max_right_part = dp[k + 1][j];
        				}
        				dp[i][j] = max((left_after_popping_last * nums[k] * right_after_popping_last + max_left_part + max_right_part), dp[i][j]);
                        // cout << "i: " << i << " j: " << j << " dp[i][j]: " << dp[i][j] << "\n";
        			}
        		}
        	}
        	return dp[0][nums_size - 1];
    	}
};