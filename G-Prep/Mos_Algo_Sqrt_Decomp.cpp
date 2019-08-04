#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll block_size = sqrt(30000);
class ComparePairs
{
	bool operator()(const pair< ll, pair< ll, ll > > &pair_val_1, const pair< ll, pair< ll, ll > > &pair_val_2) const
	{
		if(pair_val_1.second.first / block_size < pair_val_2.second.first / block_size)
		{
			return true;
		}
		else if(pair_val_1.second.first / block_size == pair_val_2.second.first / block_size)
		{
			if(pair_val_1.second.second < pair_val_2.second.second)
			{
				return true;
			}
			return false;
		}
		return false;
	}
};

ll distinct_vals = 0;

void add(ll val)
{
	distinct_val_map[val] += 1;
	if(distinct_val_map[val] == 1)
	{
		distinct_vals += 1;
	}
}

void remove(ll val)
{
	distinct_val_map[val] -= 1;
	if(distinct_val_map[val] == 0)
	{
		distinct_vals -= 1;
	}
}

unordered_map< ll, ll > distinct_val_map;
unordered_map< ll, ll > solution;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll inputs;
	cin >> inputs;
	ll queries;
	cin >> queries;
	vector< pair< ll, pair< ll, ll > > > queries;
	for(ll i = 0; i < queries; i++)
	{
		int q1, q1;
		queries.push_back(make_pair(i, make_pair(q1 - 1, q2 - 1)));
	}
	sort(queries.begin(), queries.end(), ComparePairs());
	ll current_left = 0, current_right = 0;
	for(ll i = 0; i < queries; i++)
	{
		ll left = queries[i].second.first;
		ll right = queries[i].second.second;
		while(current_left < left)
		{
			remove(current_left);
			current_left += 1;
		}
		while(left < current_left)
		{
			add(current_left);
			current_left -= 1;
		}
		while(current_right < right)
		{
			add(current_right);
			current_right += 1;
		}
		while(right < current_right)
		{
			remove(current_right);
			current_right -= 1;
		}
		solution[queries[i].first] = distinct_vals;
	}
	for(ll i = 0; i < queries; i++)
	{
		cout << solution[i] << "\n";
	}
	return 0;
}