// https://leetcode.com/problems/trapping-rain-water/submissions/
class Solution 
{
    public:
        int trap(vector<int>& height) 
        {
            stack< int > bars;
            int bars_count = height.size();
            int solution = 0;
            for(int i = 0; i < bars_count; i++)
            {
                while(!bars.empty() and height[i] > height[bars.top()])
                {
                    int index = bars.top();
                    bars.pop();
                    if(bars.empty())
                    {
                        break;
                    }
                    int distance = i - bars.top() - 1;
                    int value = distance * (min(height[bars.top()], height[i]) - height[index]);
                    // cout << "index: " << index << " distance: " << distance << " value: " << value << "\n";
                    solution += value;
                }
                bars.push(i);
            }
            return solution;
        }
};