#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution 
{
	public:
    	int subarraySum(vector<int>& nums, int k) 
    	{
        	int vector_size = nums.size();
        	unordered_map< ll, ll > already_found;
        	already_found.insert(make_pair(0, 1));
        	int sum = 0;
        	int count = 0;
        	for(int i = 0; i < vector_size; i++)
        	{
        		sum += nums[i];
        		auto find_iter = already_found.find(sum - k);
        		if(find_iter != already_found.end())
        		{
        			count += find_iter -> second;
        		}
        		already_found[sum] += 1;
        	}
        	return count;
    	}
};

int main()
{
	vector< int > nums {1,1,1};
	Solution solution;
	int value = solution.subarraySum(nums);
	cout << value;
	return 0;
}