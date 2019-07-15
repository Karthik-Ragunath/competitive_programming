#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Compare_Vecs
{
	public: 
		bool operator()(const vector< int > &vec_1, const vector< int > &vec_2) const
		{
			if(vec_1[0] < vec_2[0])
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
    	vector<vector<int>> merge(vector<vector<int>>& intervals) 
    	{	
        	sort(intervals.begin(), intervals.end(), Compare_Vecs());
        	vector< vector< int > > solution_vec;
        	int intervals_size = intervals.size();
        	for(int i = 0; i < intervals_size; i++)
        	{
        		if(solution_vec.empty() || solution_vec[solution_vec.size() - 1][1] < intervals[i][0])
        		{
        			solution_vec.push_back(intervals[i]);
        		}
        		else
        		{
        			solution_vec[solution_vec.size() - 1][1] = max(intervals[i][1], solution_vec[solution_vec.size() - 1][1]);
        		}
        	}
        	return solution_vec;
    	}

    	void print_the_sol(auto solution_vec)
    	{
    		for(auto iter = solution_vec.begin(); iter != solution_vec.end(); iter++)
    		{
    			for(auto it = iter -> begin(); it != iter -> end(); it++)
    			{
    				cout << *it << " ";
    			}
    			cout << "\n" << "---------" << "\n";
    		}
    	}
};


int main()
{
	vector< vector< int > > intervals{{1,3},{2,6},{8,10},{15,18}};
	Solution solution;
	vector< vector< int > > solution_vec;
	solution_vec = solution.merge(intervals);
	solution.print_the_sol(solution_vec);
	return 0;
}