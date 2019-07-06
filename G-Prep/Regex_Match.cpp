class Solution 
{
    public:
        bool isMatch(string s, string p) 
        {
  			int string_length = s.length();
  			int prefix_length = p.length();
            // cout << string_length << " " << prefix_length << "\n";
  			vector< vector< bool > > dp(string_length + 1, vector< bool >(prefix_length + 1));
  			// cout << dp.size() << " " << dp[0].size() << endl;
  			for(int j = 0; j <= prefix_length; j++)
  			{                
  				if(j == 0)
  				{
  					dp[0][j] = true;
  				}
  				else
  				{
                    if(p[j-1] == '*')
                    {
                        if(j > 1)
                        {
                            dp[0][j] = dp[0][j - 2];
                        }
                        else
                        {
                            dp[0][j] = false;
                        }
                    }
                    else
                    {
                        dp[0][j] = false;
                    }
  					// dp[0][j] = (p[j - 1] == '.') ? true : (p[j - 1] == '*' ? (j > 1 ? dp[0][j - 2] : false ) : false); 
  				}
  			}
            
 			for(int i = 1; i <= string_length; i++)
 			{
 				for(int j = 0; j <= prefix_length; j++)
 				{
 					if(j == 0)
 					{
 						dp[i][j] = false;
 					}
 					else
 					{
 						if(p[j - 1] == s[i - 1] || p[j - 1] == '.')
 						{
 							dp[i][j] = dp[i - 1][j - 1];
 						}
 						else if(p[j - 1] == '*')
 						{
 							if(j > 1)
 							{
 								dp[i][j] = dp[i][j - 2]; // Removal of previous word and check match of string with prefix at that point
 							}
 							if(j > 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j])
 							{
 								// dp[i - 1][j] considers x(aaaaaaa) to part of x(a*) 
 								dp[i][j] = dp[i][j] || dp[i - 1][j];
 							}
 						}
 						else
 						{
 							dp[i][j] = false; 
 						}
 					}	
 				}
 			}
 			// cout << "solution: " << dp[string_length][prefix_length] << "\n";
            return dp[string_length][prefix_length];
        }
};