// https://leetcode.com/problems/trapping-rain-water/submissions/
class Solution 
{
    public:
        int trap(vector<int>& height) 
        {
            if(height.size() == 0)
            {
                return 0;
            }
            int bars_count = height.size();
            int left_max = height[0];
            int right_max = height[bars_count - 1];
            vector< int > left_max_vec(bars_count);
            vector< int > right_max_vec(bars_count);
            left_max_vec[0] = 0;
            right_max_vec[bars_count - 1] = 0;
            for(int i = 1; i < bars_count; i++)
            {
                if(height[i] >= left_max)
                {
                    left_max = height[i];
                    left_max_vec[i] = 0;
                }
                else
                {
                    left_max_vec[i] = left_max - height[i];
                }
            }
            for(int i = bars_count - 2; i >= 0; i--)
            {
                if(height[i] >= right_max)
                {
                    right_max = height[i];
                    right_max_vec[i] = 0;
                }
                else
                {
                    right_max_vec[i] = right_max - height[i];
                }
            }
            int solution = 0;
            for(int i = 0; i < bars_count; i++)
            {
                // cout << "left_max: " << left_max_vec[i] << " " << "right_max: " << right_max_vec[i] << "\n"; 
                solution += min(left_max_vec[i], right_max_vec[i]);
            }
            return solution;
        }
};