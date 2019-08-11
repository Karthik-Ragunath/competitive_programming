#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class CompareNodes
{
	public:
		bool operator()(const pair< ll, ll > &pair_1, const pair< ll, ll > &pair_2) const
		{
			if(pair_1.first < pair_2.first)
			{
				return true;
			}
			else
			{
				if(pair_1.first == pair_2.first and pair_1.second > pair_2.second)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
};

bool is_clockwise_turn(pair< ll, ll > pair_1, pair< ll, ll > pair_2, pair< ll, ll > pair_3)
{
	// Both Works (slope between points {2 and 1} must be greater than slope between points {3 and 2}
	// return (pair_2.second - pair_1.second) * (pair_3.first - pair_2.first) > (pair_3.second - pair_2.second) * (pair_2.first - pair_1.first);
	return (pair_2.second - pair_1.second) * (pair_3.first - pair_1.first) > (pair_3.second - pair_1.second) * (pair_2.first - pair_1.first);
}

void print_vec_pairs(vector< pair< ll, ll > > &vector_pairs)
{
	for(auto iter = vector_pairs.begin(); iter != vector_pairs.end(); iter++)
	{
		cout << iter -> first << " " << iter -> second << "\n";
	}
}

vector< pair< ll, ll > > get_convex_hull(vector< pair< ll, ll > > &vector_pairs)
{
	if(vector_pairs.size() <= 2)
	{
		return vector_pairs;
	}
	sort(vector_pairs.begin(), vector_pairs.end(), CompareNodes());
	// print_vec_pairs(vector_pairs);
	vector< pair< ll, ll > > upper_hull;
	vector< pair< ll, ll > > lower_hull;
	for(int i = 0, k = 0; i < vector_pairs.size(); i++)
	{
		while(upper_hull.size() >= 2 and not is_clockwise_turn(upper_hull[upper_hull.size() - 2], upper_hull[upper_hull.size() - 1], vector_pairs[i]))
		{
			upper_hull.erase(upper_hull.end());
		}
		upper_hull.push_back(vector_pairs[i]);
	} 	
	// print_vec_pairs(upper_hull);
	for(int i = vector_pairs.size() - 1; i >= 0; i--)
	{
		while(lower_hull.size() >= 2 and not is_clockwise_turn(lower_hull[lower_hull.size() - 2], lower_hull[lower_hull.size() - 1], vector_pairs[i]))
		{
			lower_hull.erase(lower_hull.end());
		}
		lower_hull.push_back(vector_pairs[i]);
	}
	// print_vec_pairs(lower_hull);
	upper_hull.erase(upper_hull.end());
	lower_hull.erase(lower_hull.end());
	upper_hull.reserve(upper_hull.size() + lower_hull.size());
	upper_hull.insert(upper_hull.end(), lower_hull.begin(), lower_hull.end());
	return upper_hull;
}

int main()
{
	vector< pair< ll, ll > > convex_points{make_pair(1,4), make_pair(1, 9), make_pair(2, 4), make_pair(2,9)};
	vector< pair< ll, ll > > convex_hull_points = get_convex_hull(convex_points);
	print_vec_pairs(convex_hull_points);
	return 0;
}