#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll testcases;
	cin >> testcases;
	for(ll i = 0; i < testcases; i++)
	{
		ll N;
		cin >> N;
		ll path_length = 2 * N - 2;
		string path;
		cin >> path;
		vector< ll > path_followed;
		ll cur_loc = 1;
		for(auto iter = path.begin(); iter != path.end(); iter++)
		{
			if(*iter == 'S')
			{
				cur_loc += N;
				path_followed.push_back(cur_loc);
			}
			else
			{
				cur_loc += 1;
				path_followed.push_back(cur_loc);
			}
		}
		ll start = 1;
		bool prv_s = false;
		string solution = "";
		for(ll i = 0; i < path_length; i++)
		{
			if(i % 2 == 0)
			{
				if(start + N == path_followed[i])
				{
					start += 1;
					prv_s = false;
					solution += "E";
				}
				else
				{
					start += N;
					prv_s = true;
					solution += "S";
				}
			}
			else
			{
				if(prv_s)
				{
					start += 1;
					solution += "E";
				}
				else
				{
					start += N;
					solution += "S";
				}
			}
		}
		cout << "Case #" << (i + 1) << ": " << solution << endl;
	}
	return 0;
}