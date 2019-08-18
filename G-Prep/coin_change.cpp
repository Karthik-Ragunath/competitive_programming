class Solution 
{
	public:
    	int coinChange(vector<int>& coins, int amount) 
    	{
            int max = amount + 1;
        	vector< vector< int > > dp(coins.size(), vector< int >(amount + 1, max));
        	for(int i = 0; i < coins.size(); i++)
        	{
        		dp[i][0] = 0;
        	}
        	for(int i = 0; i < coins.size(); i++)
        	{
        		for(int j = 1; j <= amount; j++)
        		{
                    if(i == 0)
                    {
                        if(j >= coins[i])
                        {
                            dp[i][j] = min(max, (dp[i][j - coins[i]] + 1));
                        }
                        else
                        {
                            dp[i][j] = max;
                        }
                    }
                    else
                    {
                        if(j >= coins[i])
                        {
        			        dp[i][j] = min(dp[i - 1][j], (dp[i][j - coins[i]] + 1));
                        }
                        else
                        {
                            dp[i][j] = dp[i - 1][j];
                        }
                    }
                    // cout << "i: " << i << " j: " << j << " : " << dp[i][j] << "\n";
        		}
        	}
            if(dp[coins.size() - 1][amount] <= amount)
            {
        	    return dp[coins.size() - 1][amount];
            }
            else
            {
                return -1;
            }
    	}
};