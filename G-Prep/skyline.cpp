#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

class Compare_Nodes_Start
{
	public:
		bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
		{
			if(pair_1.first < pair_2.first)
			{
				return true;
			}
			else if(pair_1.first == pair_2.first)
			{
				if(pair_1.second > pair_2.second)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
};

class Compare_Nodes_End
{
	public:
		bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
		{
			if(pair_1.first < pair_2.first)
			{
				return true;
			}
			else if(pair_1.first == pair_2.first)
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
			else
			{
				return false;
			}
		}
};

class Multi_Set_Compare
{
	public:
		bool operator()(const int val_1, const int val_2) const
		{
			if(val_1 > val_2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class Solution 
{
	public:
    	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    	{
			int buildings_count = buildings.size();
			set< pair< int, int >, Compare_Nodes_Start > start_set;
			set< pair< int, int >, Compare_Nodes_End > end_set;
			for(auto iter = buildings.begin(); iter != buildings.end(); iter++)
			{
				int x_start = (*iter)[0];
				int x_end = (*iter)[1];
				int height = (*iter)[2];
				start_set.insert(make_pair(x_start, height));
				end_set.insert(make_pair(x_end, height));
			}
			auto start_iter = start_set.begin();
			auto end_iter = end_set.begin();
			multiset< int, Multi_Set_Compare > pq_with_dupes;
			vector< vector< int > > solution_vec;
			for(; start_iter != start_set.end() or end_iter != end_set.end();)
			{
				if(start_iter != start_set.end() and start_iter -> first < end_iter -> first or (start_iter -> first == end_iter -> first and start_iter -> second >= end_iter -> second))
				{
					// cout << "multiset top: " << *(pq_with_dupes.begin()) << "\n";
					// cout << start_iter -> first << " " << start_iter -> second << "\n";
					if(pq_with_dupes.empty() || (!pq_with_dupes.empty() and start_iter -> second > *(pq_with_dupes.begin())))
					{
						vector< int > inner_vec;
						inner_vec.push_back(start_iter -> first);
						inner_vec.push_back(start_iter -> second);
						solution_vec.push_back(inner_vec);
						// cout << "Insertion occured" << "\n";
					}
					pq_with_dupes.insert(start_iter -> second);
					start_iter++;
				}
				else
				{
					int top_value = *(pq_with_dupes.begin());
					auto iter = pq_with_dupes.find(end_iter -> second);
					if(iter != pq_with_dupes.end())
					{
						pq_with_dupes.erase(iter);
					}
					if(pq_with_dupes.empty() || *(pq_with_dupes.begin()) != top_value)
					{
						vector< int > inner_vec;
						inner_vec.push_back(end_iter -> first);
						inner_vec.push_back(*(pq_with_dupes.begin()));
						solution_vec.push_back(inner_vec);
					}
					end_iter++;
				}
			}
			return solution_vec;
    	}

    	void print_solutions(vector< vector< int > > &solution_vec)
    	{
    		for(auto iter = solution_vec.begin(); iter != solution_vec.end(); iter++)
    		{
    			cout << "---------" << "\n";
    			for(auto it = iter -> begin(); it != iter -> end(); it++)
    			{
    				cout << *it << "\n";
    			}
    		}
    	}
};

int main()
{
	Solution solution;
	vector< vector< int > > buildings {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
	vector< vector< int > > solution_vec;
	solution_vec = solution.getSkyline(buildings);
	// solution.print_solutions(solution_vec);
	return 0;
}