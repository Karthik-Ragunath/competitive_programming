// https://leetcode.com/problems/permutations/
class Solution 
{
	public:
	    vector<vector<int>> permute(vector<int>& nums) 
	    {
	        vector< vector< int > > dp;
	        vector< int > temp;
	        unordered_set< int > permute_set;
	        generate_permutations(nums, dp, temp, permute_set, 0);
	        return dp;
	    }	

	    void generate_permutations(vector< int > &nums, vector< vector< int > > &dp, vector< int > &temp, unordered_set< int > &permute_set, int index)
	    {
	    	if(temp.size() == nums.size())
	    	{
	    		dp.push_back(temp);
	    	}
	    	for(int i = 0; i < nums.size(); i++)
	    	{
	    		auto find_iter = permute_set.find(nums[i]);
	    		if(find_iter == permute_set.end())
	    		{
	    			permute_set.insert(nums[i]);
		    		temp.push_back(nums[i]);
		    		generate_permutations(nums, dp, temp, permute_set, i + 1);
		    		temp.pop_back();
		    		permute_set.erase(nums[i]);
	    		}
	    	}
	    	return;
	    }
};