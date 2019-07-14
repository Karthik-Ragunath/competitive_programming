#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution 
{
	public:
    	vector<vector<int>> permute(vector<int>& nums) 
    	{
    		sort(nums.begin(), nums.end());
        	vector< vector< int > > permutes;
        	do
        	{
        		permutes.push_back(nums);
        	}while(next_permutation(nums.begin(), nums.end()));
        	return permutes;
    	}
};

int main()
{
	vector< int > nums{1,2,3};
	Solution solution;
	vector< vector< int > > solution_vec = solution.permutes(nums);
	for(auto outer_iter = solution_vec.begin(); outer_iter != solution_vec.end(); outer_iter++)
	{
		for(auto inner_iter = outer_iter -> begin(); inner_iter != outer_iter -> end(); inner_iter++)
		{
			cout << *inner_iter << " ";
		}
		cout << "------" << "\n";
	}
	return 0;
}