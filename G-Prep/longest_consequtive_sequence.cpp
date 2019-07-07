// https://leetcode.com/problems/longest-consecutive-sequence/submissions/
class Solution 
{
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            unordered_set< int > hash_set(nums.begin(), nums.end());
            int hash_size = hash_set.size();
            int longest_seq_count = 0;
            for(auto num: hash_set)
            {
                auto find_iter = hash_set.find(num - 1);
                if(find_iter == hash_set.end());
                {
                    int current_seq_count = 1;
                    while(hash_set.find(num + 1) != hash_set.end())
                    {
                        current_seq_count += 1;
                        num += 1;
                    }
                    longest_seq_count = max(longest_seq_count, current_seq_count);
                }
            }
            return longest_seq_count;
        }
};