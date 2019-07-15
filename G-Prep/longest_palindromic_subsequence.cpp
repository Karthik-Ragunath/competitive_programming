#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution 
{
	public:
    	int longestPalindromeSubseq(string s) 
    	{
        	int string_length = s.length();
        	if(string_length <= 1)
        	{
        		return string_length;
        	}
        	vector< vector< int > > dp(string_length, vector< int >(string_length));
        	for(int i = 0; i < string_length; i++)
        	{
        		dp[i][i] = 1;
        	}
        	for(int l = 2; l <= string_length; l++)
        	{
        		for(int i = 0; i < string_length - l + 1; i++)
        		{
        			int j = (i + l - 1);
        			if(s[i] == s[j])
        			{
        				dp[i][j] = dp[i + 1][j - 1] + 2;
        			}
        			else
        			{
        				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        			}
        		}
        	}
        	return dp[0][string_length - 1];
    	}
};


int main()
{
	string s = "bbbab";
	Solution solution;
	int length = solution.longestPalindromeSubseq(s);
	cout << length << "\n";
	return 0;
}