#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct HASH
{
	size_t operator()(const pair< ll, ll > pair_val) const
	{
		return hash< ll >()(pair_val.first ^ (pair_val.second << 32));
	}
};

class Solution 
{
	public:
    	bool isBipartite(vector<vector<int>>& graph) 
    	{
        	queue< int > separator_queue;
        	vector< vector< int > > edges_vec(graph.size());
        	for(auto outer_vec: graph)
        	{
        		int outer_vec_size = outer_vec.size();
        		for(ll i = 0; i < outer_vec_size; i++)
        		{
        			for(ll j = i + 1; j < outer_vec_size; j++)
        			{
        				edges_vec[outer_vec[i]].push_back(outer_vec[j]);
        				edges_vec[outer_vec[j]].push_back(outer_vec[i]);
        			}
        		}
        	}
    	}
};

int main()
{

	return 0;
}
