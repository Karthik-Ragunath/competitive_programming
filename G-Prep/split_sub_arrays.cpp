#define ll long long int
class Solution 
{
	public:
    	int splitArray(vector<int>& nums, int m) 
    	{
    		ll sum = 0, max = 0;
        	for(ll i = 0; i < nums.size(); i++)
        	{
        		sum += nums[i];
        		if(nums[i] > max)
        		{
        			max = nums[i];
        		}
        	}
        	ll high = sum, low = max, solution = sum + 1;
        	while(low <= high)
        	{
        		ll mid = (low + high) / 2;
                // cout << "Mid: " << mid << "\n";
        		ll local_solution_sum = 0;
        		ll cut_count = 1;
        		for(ll i = 0; i < nums.size(); i++)
        		{
        			if(local_solution_sum + nums[i] > mid)
        			{
        				cut_count += 1;
        				local_solution_sum = nums[i];
        			}
        			else
        			{
        				local_solution_sum += nums[i];
        			}
        		}
        		if(cut_count <= m)
        		{
        			solution = min(solution, mid);
        			high = mid - 1;
        		}
        		else
        		{
        			low = mid + 1;
        		}
        	}
        	return solution;
    	}
};