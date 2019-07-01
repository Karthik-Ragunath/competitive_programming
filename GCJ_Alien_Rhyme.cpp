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
		vector< vector< string >::iterator > iter_vec(N);
		unordered_map< string, ll > str_index_map;
		for(ll i = 0; i < N; i++)
		{
			string s1;
			cin >> s1;
			ll l_s = s1.size();
			string r_s = s1;
			for(ll j = l_s - 1, k = 0; j >= 0; j--, k++)
			{
				auto find_iter = suf_len_maps[j].find(r_s);
				if(find_iter != suf_len_maps[j].end())
				{
					//suf_len_maps[j].erase(find_iter);
					for(auto iter = iter_vec[str_index_map[r_s]].begin(); iter != iter_vec[str_index_map[r_s]].end(); iter++)
					{
						suf_len_maps.erase(*iter);
					}
					for(auto iter = iter_vec[i].begin(); iter != iter_vec[i].end(); iter++)
					{
						suf_len_maps.erase(*iter);
					}
					str_index_map.erase(r_s);
					solution += 2;
					break;
				}
				else
				{
					suf_len_maps[j].insert(r_s);
					iter_vec[i].append(suf_len_maps[j].find(r_s));
					str_index_map.insert(make_pair(r_s, i));
					r_s.erase(r_s.begin());
				}
			}
		}
		cout << solution << endl;
	}
	return 0;
}