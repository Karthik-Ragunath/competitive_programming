class CompareNodes
{
	public:
		bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
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
}

class Solution 
{
	public:
    	vector<int> twoSum(vector<int>& nums, int target) 
    	{
    		unordered_map< int, int > hash_map;
    		for(int i = 0; i < nums.size(); i++)
    		{
    			int complement_val = target - nums[i];
    			auto find_iter = hash_map.find(complement_val);
    			if(find_iter != hash_map.end())
    			{
    				return vector< int >{find_iter -> second, i};
    			}
    			hash_map.insert(make_pair(nums[i], i));
    		}
    		return vector< int > {};	
    	}
};