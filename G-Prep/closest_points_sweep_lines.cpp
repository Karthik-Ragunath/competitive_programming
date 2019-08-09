// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

class CompareNodes
{
	bool operator(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
	{
		return pair_1.first < pair_2.first;
	}
};

class CompareSets
{
	bool operator()(const pair< ll, ll > &pair_1, const pair< ll, ll > &pair_2) const
	{
		return pair_1.second < pair_2.second;
	}
}

class Solution {
public:
    int smallestDistancePair(vector< pair< int, int > > &input_pairs) 
    {
    	sort(input_pairs.begin(), input_pairs.end(), CompareNodes());
    	set< pair< ll, ll >, CompareSets > visited_set;
    	visited_set.insert(input_pairs[0]);
    	int max_distance = 1000000000;
    	for(int i = 1; i < input_pairs; i++)
    	{

    	}
    }

};