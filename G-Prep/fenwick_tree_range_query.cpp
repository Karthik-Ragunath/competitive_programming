#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class NumArray 
{
	public:
		vector< int > fenwick_tree;
    	NumArray(vector<int>& nums) // constructor
    	{
    		int nums_size = nums.size();
    		fenwick_tree.assign(nums_size + 1, 0);
        	for(int i = 0; i < nums_size; i++)
        	{
        		int j = i + 1;
        		while(j <= nums_size)
        		{
        			fenwick_tree[j] += nums[i];
        			j += (j & -j); 
        		}
        	}
    	}

    	int sum_to_index(int index)
    	{
    		// cout << "fenwick_tree index 0: " << fenwick_tree[1] << "\n";
    		int solution = 0;
    		while(index > 0)
    		{
    			solution += fenwick_tree[index];
    			index -= (index & -index);
    		}
    		// cout << "index: " << index << " solution: " << solution << "\n";
    		return solution;
    	}
    
    	int sumRange(int i, int j) 
    	{
        	int range_i = sum_to_index(i);
        	int range_j = sum_to_index(j + 1);
        	int difference = range_j - range_i;
        	return difference;
    	}
};

int main()
{
	vector< int > temp{-2, 0, 3, -5, 2, -1};
	NumArray* num_array = new NumArray(temp);
	int range_1 = num_array -> sumRange(0, 2);
	int range_2 = num_array -> sumRange(2, 5);
	int range_3 = num_array -> sumRange(0, 5);
	cout << range_1 << " " << range_2 << " " << range_3 << "\n";
	return 0;
}