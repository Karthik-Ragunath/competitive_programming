// https://leetcode.com/problems/permutations-ii/submissions/
class Solution 
{
	public:
	    vector<vector<int>> permuteUnique(vector<int>& nums) 
	    {
	        vector< vector< int > > dp;
	        vector< int > temp;
            sort(nums.begin(), nums.end());
            vector< bool > visited(nums.size());
	        generate_permutations(nums, dp, temp, visited);
	        return dp;
	    }	

	    void generate_permutations(vector< int > &nums, vector< vector< int > > &dp, vector< int > &temp, vector< bool > &visited)
	    {
	    	if(temp.size() == nums.size())
	    	{
	    		dp.push_back(temp);
                return;
	    	}
            int prev;
            bool prev_set = false;
	    	for(int i = 0; i < nums.size(); i++)
	    	{
                if(visited[i] or (prev_set and nums[i] == prev))
                {
                    continue;
                }
                visited[i] = true;
                temp.push_back(nums[i]);
                generate_permutations(nums, dp, temp, visited);
                temp.pop_back();
                visited[i] = false;
                prev = nums[i];
                prev_set = true;
	    	}
	    	return;
	    }
};