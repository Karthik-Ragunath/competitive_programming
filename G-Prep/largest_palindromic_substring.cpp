#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution 
{
	public:
    	string longestPalindrome(string s) 
    	{
        	int string_length = s.length();
        	int starting_position = 0;
        	int max_length = 0;
        	for(int i = 0; i < string_length; i++)
        	{
        		int length_considering_odd = compute_palindrome_length(s, i, i);
        		int length_considering_even = compute_palindrome_length(s, i, i + 1);
        		int max_palindromic_length = max(length_considering_odd, length_considering_even);
        		int left = i - (max_palindromic_length + 1) / 2 + 1;
        		// cout << "index: " << i << " left: " << left << " max_length: " << max_palindromic_length << "\n";
        		if(max_palindromic_length > max_length)
        		{
        			starting_position = left;
        			max_length = max_palindromic_length;
        		}
        	}
        	if(max_length > 0)
        	{
        		// cout << "starting position: " << starting_position << " max_length: " << max_length << "\n";
        		return s.substr(starting_position, max_length);
        	}
        	else
        	{
        		return s;
        	}
    	}

    	int compute_palindrome_length(string s, int left, int right)
    	{
    		while(left >= 0 and right < s.length() and s[left] == s[right])
    		{
    			left -= 1;
    			right += 1;
    		}
    		int length_val = right - left - 1;
    		return length_val;
    	}
};

int main()
{
	string s = "babad";
	// cin >> s;
	Solution solution;
	string solution_string = solution.longestPalindrome(s);
	cout << solution_string << "\n";
	return 0;
}