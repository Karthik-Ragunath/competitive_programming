// https://leetcode.com/problems/trapping-rain-water/submissions/
class Solution 
{
    public:
        int trap(vector<int>& height) 
        {
            if(height.empty())
            {
                return 0;
            }
            int bars_count = height.size();
            int left_max = height[0];
            int right_max = height[bars_count - 1];
            int left_index = 0;
            int right_index = height.size() - 1;
            int solution = 0;
            while(left_index < right_index)
            {
                if(height[left_index] < height[right_index]) // < or <= doesnt matter signifies that this could be max
                {
                    if(height[left_index] >= left_max) // > or >= doesnt matter since == will any way result in zero
                    {
                        left_max = height[left_index];
                    }
                    else
                    {
                        solution += (left_max - height[left_index]);
                    }
                    left_index += 1;
                }
                else
                {
                    if(height[right_index] >= right_max)
                    {
                        right_max = height[right_index];
                    }
                    else
                    {
                        solution += (right_max - height[right_index]);
                    }
                    right_index -= 1;
                }
            }
            return solution;
        }
};