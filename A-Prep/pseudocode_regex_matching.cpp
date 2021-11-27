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