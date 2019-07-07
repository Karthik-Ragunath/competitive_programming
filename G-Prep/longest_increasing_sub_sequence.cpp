class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int nums_length = nums.size();
        if(nums_length == 0)
        {
            return 0;
        }
        vector< int > longest_sub_seq;
        longest_sub_seq.append(nums[0]);
        int longest_len = 1;
        for(int i = 1; i < nums_length; i++)
        {
            if(nums[i] > longest_sub_seq[longest_len - 1]) //for strictly increasing else >= instead of >
            {
                longest_sub_seq.append(nums[i]);
                longest_len += 1;
            }
            else
            {
                int upper_bound = upper_bound(longest_sub_seq.begin(), longest_sub_seq.end(), nums[i]) - longest_sub_seq.begin();
                longest_sub_seq[upper_bound] = nums[i];
            }
        }
        return longest_len;
    }
};