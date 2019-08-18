class Solution 
{
    public:
        int maxArea(vector<int>& height) 
        {
            int left_pointer = 0;
            int right_pointer = height.size() - 1;
            int max_area = 0;
            while(left_pointer < right_pointer)
            {
                // cout << "debug1: " << left_pointer << " " << right_pointer << "\n";
                if(height[left_pointer] <= height[right_pointer])
                {
                    int local_max_area = height[left_pointer] * (right_pointer - left_pointer);
                    if(local_max_area > max_area)
                    {
                        max_area = local_max_area;
                    }
                    left_pointer += 1;
                }
                else
                {
                    int local_max_area = height[right_pointer] * (right_pointer - left_pointer);
                    if(local_max_area > max_area)
                    {
                        max_area = local_max_area;
                    }
                    right_pointer -= 1;
                }
            }
            // cout << max_area << "\n";
            return max_area;
        }
};
// [1,8,6,2,5,4,8,3,7]