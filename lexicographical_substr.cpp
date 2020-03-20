#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll testcases;
	cin >> testcases;
	for(ll k = 0; k < testcases; k++)
	{
		map< char, ll > char_map_s;
		map< char, ll > char_map_r;
		string s, r;
		cin >> s >> r;
		ll s_len = s.length();
		ll r_len = r.length();
		for(ll i = 0; i < s_len; i++)
		{
			char_map_s[s[i]] += 1;
		}
		for(ll i = 0; i < r_len; i++)
		{
			char_map_r[r[i]] += 1;
		}
		bool valid = true;
		for(auto iter = char_map_s.begin(); iter != char_map_s.end(); iter++)
		{
			char s_key = iter -> first;
			ll s_count = iter -> second;
			auto find_iter = char_map_r.find(s_key);
			if(find_iter != char_map_r.end())
			{
				char r_key = find_iter -> first;
				int r_count = find_iter -> second;
				if(r_count >= s_count)
				{
					if(r_count == s_count)
					{
						char_map_r.erase(find_iter);
					}
					else
					{
						find_iter -> second = find_iter -> second - s_count;
					}
				}
				else
				{
					valid = false;
					break;
				}
			}
			else
			{
				valid = false;
				break;
			}
		}
		if(valid)
		{
			string solution = "";
			bool greater_found = false;
			int ascii_s_ini = (int)(s[0] - 'a');
			for(auto iter = char_map_r.begin(); iter != char_map_r.end(); iter++)
			{
				string left_over = "";
				char key = iter -> first;
				ll val = iter -> second;
				for(ll i = 0; i < val; i++)
				{
					left_over += key;
				}
				int ascii_key = (int)(key - 'a');
				if(not greater_found and ascii_key > ascii_s_ini)
				{
					solution = solution + s + left_over;
					greater_found = true;
				}
				else
				{
					solution += left_over;
				}
			}
			if(not greater_found)
			{
				solution += s;
				greater_found = true;
			}
			cout << solution << "\n";
		}
		else
		{
			cout << "Impossible" << "\n";
		}
	}
	return 0;
}