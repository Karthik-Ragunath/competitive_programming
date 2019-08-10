// https://leetcode.com/problems/find-k-th-smadoubleest-pair-distance/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
class CompareNodes
{
	bool operator(const pair< double, double > &pair_1, const pair< double, double > &pair_2) const
	{
		return pair_1.first < pair_2.first;
	}
};

class CompareSets
{
	bool operator()(const pair< double, double > &pair_1, const pair< double, double > &pair_2) const
	{
		return pair_1.second < pair_2.second;
	}
};

class Solution {
public:
	bool cmp(double compare_value, const pair< double, double > &pair_val)
	{
		// auto upper_bound_iter = upper_bound(input_pairs.begin(), input_pairs.end(), compare_value, cmp); //Upper bound or lower bound in sorted vector
		if(pair_val.first > compare_value and pair_val.second > compare_value)
		{
			return true;
		}
	}

    double shortest_pair(vector< pair< double, double > > &input_pairs) 
    {
    	sort(input_pairs.begin(), input_pairs.end(), CompareNodes());
    	set< pair< double, double > > visited_set; // default sort by x and then sort by y
    	visited_set.insert(input_pairs[0]);
    	double min_distance = 10000000000000;
    	double left = 0;
    	for(double i = 1; i < input_pairs.size(); i++)
    	{
    		while(left < i && (input_pairs[i].first - input_pairs[left].first) > min_distance)
    		{
    			visited_set.erase(input_pairs[left]);
    			left += 1;
    		}
    		// default lower_bound -> return pair.first >= value and pair.second >= value;
    		for(auto iter = visited_set.lower_bound(make_pair(input_pairs[i].first - min_distance, input_pairs[i].second - min_distance)); iter != visited_set.end() and input_pairs[i].second + min_distance >= iter -> second; iter++) // lower_bound takes care of left and below and conditional takes care of left and above
    		{
    			min_distance = min(min_distance, sqrt(pow((input_pairs[i].first - iter -> first), 2) + pow((input_pairs[i].second - iter -> second), 2)));
    		}
    		visited_set.insert(input_pairs[i]);
    	}
    	return min_distance;
    }
};

int main()
{
	Solution solution;
	vector< pair< double, double > > input_pairs{make_pair(2, 3), make_pair(12, 30), make_pair(40, 50), make_pair(5, 1), make_pair(12, 10), make_pair(3, 4)};
	double min_distance = solution.shortest_pair(inout_pairs);
	cout << min_distance << "\n";
}