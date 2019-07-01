#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll testcases;
	cin >> testcases;
	for(ll k = 0; k < testcases; k++)
	{
		ll N;
		cin >> N;
		ll solution = 0;
		unordered_map< ll, unordered_set<string> > suf_len_maps;
		unordered_map< string, ll > str_index_map;
		vector< string > str_vec(N);
		unordered_set< string > solution_set;
		for(ll i = 0; i < N; i++)
		{
			string s1;
			cin >> s1;
			str_vec[i] = s1;
			ll l_s = s1.size();
			string r_s = s1;
			for(ll j = l_s - 1, k = 0; j >= 0; j--, k++)
			{
				auto find_iter = suf_len_maps[j].find(r_s);
				auto finder = solution_set.find(r_s);
				if(find_iter != suf_len_maps[j].end() && finder == solution_set.end())
				{
					solution_set.insert(r_s);
					ll index = str_index_map[r_s];
					string old_s = str_vec[index];
					ll old_s_size = old_s.size();
					for(ll l = old_s_size - 1; l >= 0; l--)
					{
						auto new_find_iter = suf_len_maps[l].find(old_s);
						if(new_find_iter != suf_len_maps[l].end())
						{
							suf_len_maps[l].erase(new_find_iter);
							str_index_map.erase(old_s);
						}
						old_s.erase(old_s.begin());
					}

					string new_str = str_vec[i];
					ll new_str_size = new_str.size();
					for(ll l = 0, m = new_str_size - 1; l < k; l++, m--)
					{
						auto new_find_iter = suf_len_maps[m].find(new_str);
						if(new_find_iter != suf_len_maps[m].end())
						{
							suf_len_maps[m].erase(new_find_iter);
							str_index_map.erase(new_str);
						}
						new_str.erase(new_str.begin());
					}
					solution += 2;
					break;	
				}
				else
				{
					suf_len_maps[j].insert(r_s);
					str_index_map.insert(make_pair(r_s, i));
					r_s.erase(r_s.begin());
				}
			}
		}
		cout << "Case #" << (k + 1) << ": " << solution << endl;
	}
	return 0;
}