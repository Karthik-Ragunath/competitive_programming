#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class ComparePairs
{
	public:
		bool operator()(const pair< ll, ll > &pair_1, const pair< ll, ll > &pair_2) const
		{
			if(pair_1.second < pair_2.second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

int main()
{
	int testcases;
	cin >> testcases;
	for(ll k = 0; k < testcases; k++)
	{
		ll N, M;
		cin >> N >> M;
		multiset< pair< ll, ll >, ComparePairs > bbst;
		vector< ll > feed_count(N);
		for(int i = 0; i < N; i++)
		{
			bbst.insert(make_pair(i, 0));
		}
		bool fair = true;
		// cout << "M: " << M << "\n";
		for(ll i = 0; i < M; i++)
		{
			ll cat_index;
			cin >> cat_index;
			pair< ll, ll > top_element = *(bbst.begin());
			// cout << "begin: " << top_element.first << " " << top_element.second << " feed_count: " << feed_count[cat_index - 1] << "\n";
			if(fair)
			{
				if(feed_count[cat_index - 1] == top_element.second)
				{
					auto find_iter = bbst.find(make_pair(cat_index - 1, feed_count[cat_index - 1]));
					if(find_iter != bbst.end())
					{
						bbst.erase(find_iter);
					}
					else
					{
						cout << "WTF" << " Cat Index: " << (cat_index - 1) << " feed count: " << feed_count[cat_index - 1] << "\n";
					}
					feed_count[cat_index - 1] += 1;
					bbst.insert(make_pair(cat_index - 1, feed_count[cat_index - 1]));
				}
				else
				{
					fair = false;
				}
			}
			else
			{
				continue;
			}
		}
		if(fair)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}