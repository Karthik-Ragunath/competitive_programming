#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
	public:
		vector< ll > generate_prefix_suffix_match(string s)
		{
			ll string_length = s.length();
			vector< ll > prefix_suffix_index(string_length);
			for(ll i = 0, j = 0; j < string_length;)
			{
				cout << "J val: " << j << "\n";
				if(i == 0 and j == 0)
				{
					prefix_suffix_index[j] = 0;
					j++;
				}
				else if(s[i] == s[j])
				{
					prefix_suffix_index[j] = i + 1;
					i++;
					j++;
				}
				else
				{
					bool sol_found = false;
					ll prefix_index_at_previous_pos;
					for(ll k = i - 1; k >= 0;)
					{
						if(i == 0)
						{
							break;
						}
						prefix_index_at_previous_pos = prefix_suffix_index[k];
						// cout << prefix_index_at_previous_pos << " " << prefix_suffix_index[k] << "\n";
						// k--;
						if(s[prefix_index_at_previous_pos] == s[j])
						{
							prefix_suffix_index[j] = prefix_index_at_previous_pos + 1;
							sol_found = true;
							break;
						}
						else if(prefix_suffix_index[k] == 0)
						{
							break;
						}
						else
						{
							k = prefix_suffix_index[prefix_suffix_index[k] - 1];
						}
					}
					if(!sol_found)
					{
						prefix_suffix_index[j] = 0;
						i = 0;
						j++;
					}
					else
					{
						i = prefix_index_at_previous_pos;
						j++;
					}
				}
			}
			return prefix_suffix_index;
		}
		
		bool pattern_match(string s, string pattern, vector< ll > &prefix_suffix_index)
		{
			ll string_length = s.length();
			ll pattern_length = pattern.length();
			bool solution_found = false;
			for(ll i = 0, j = 0; i < string_length; i++)
			{
				if(s[i] == pattern[j])
				{
					j++;
				}
				else
				{
					bool solution_found_inner = false;
					ll j_index = 0;
					for(ll k = j - 1; k >= 0;)
					{
						if(pattern[prefix_suffix_index[k]] == s[i])
						{
							solution_found_inner = true;
							j_index = prefix_suffix_index[k];
							break;
						}
						else if(prefix_suffix_index[k] == 0)
						{
							break;
						}
						else
						{
							k = prefix_suffix_index[prefix_suffix_index[k] - 1];
						}
					}
					if(solution_found_inner)
					{
						j = j_index + 1;
					}
					else
					{
						j = 0;
					}
				}
				if(j == pattern_length)
				{
					cout << "solution_found at index i: " << i << " of str length: " << string_length << "\n";
					solution_found = true;
					break;
				}
			}
			return solution_found;
		}
};

void print_sol(vector< ll > &solution_vec)
{
	for(auto iter = solution_vec.begin(); iter != solution_vec.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << "\n" << "---------" << "\n";
}

int main()
{
	string s = "abcxabcdabxabcdabcdabcdabcy";
	string pattern = "abcdabcy";
	// string pattern = "aabaabaaa";
	Solution solution;
	vector< ll > prefix_suffix_index = solution.generate_prefix_suffix_match(pattern);
	print_sol(prefix_suffix_index);
	bool solution_found = solution.pattern_match(s, pattern, prefix_suffix_index);
	cout << solution_found << "\n";
	return 0;
}