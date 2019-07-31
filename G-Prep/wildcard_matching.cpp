class Solution 
{
	public:
    	bool isMatch(string s, string p) 
    	{
    		int s_length = s.length();
    		int p_length = p.length();
    		vector< vector< bool > >  dp(s_length + 1, vector< bool >(p_length + 1));
    		for(int i = 0; i <= p_length; i++)
    		{
    			if(i == 0)
    			{
    				dp[0][i] = true;
    			}
    			else
    			{
    				if(p[i - 1] == '*')
    				{
    					dp[0][i] = dp[0][i - 1];
    				}
    				else
    				{
    					dp[0][i] = false;
    				}
    			}
    		}
    		for(int i = 1; i <= s_length; i++)
    		{
    			for(int j = 0; j <= p_length; j++)
    			{
    				if(j == 0)
    				{
    					dp[i][0] = false;
    				}
    				else
    				{
    					if(s[i - 1] == p[j - 1] or p[j - 1] == '?')
    					{
    						dp[i][j] = dp[i - 1][j - 1];
    					}
    					else if(p[j - 1] == '*')
    					{
    						dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
    					}
    					else
    					{
    						dp[i][j] = false;
    					}
    				}
    			}
    		}
        	return dp[s_length][p_length];   
    	}
};