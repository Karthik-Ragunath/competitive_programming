class Solution 
{
	public:
		void print_vec_tuples(vector< tuple< int, int, int > > vec_tuples)
		{
			for(auto iter = vec_tuples.begin(); iter != vec_tuples.end(); iter++)
			{
				cout << get< 0 >(*iter) << " " << get< 1 >(*iter) << " " << get< 2 >(*iter) << "\n";
			}
			cout << "\n";
		}

    	vector<vector<int>> threeSum(vector<int>& nums) 
    	{
        	int nums_size = nums.size();
        	vector< vector< int > > solution_vec;
        	// vector< tuple< int, int , int > > solution_vec_tups;
            sort(nums.begin(), nums.end());
        	for(int i = 0; i < nums_size - 2; i++)
        	{
                if(i != 0)
                {
                    if(nums[i] == nums[i - 1])
                    {
                        continue;
                    }
                }
        		int pivot_pointer = i;
        		int left_pointer = i + 1;
        		int right_pointer = nums_size - 1;
        		while(left_pointer < right_pointer)
        		{
                    int current_value = nums[pivot_pointer] + nums[left_pointer] + nums[right_pointer];
                    // cout << "Left Pointer: " << left_pointer << " Right Pointer: " << right_pointer << "\n";
	        		if(current_value < 0)
	        		{
	        			while(left_pointer < right_pointer and nums[left_pointer + 1] == nums[left_pointer])
	        			{
	        				left_pointer += 1;
	        			}
	        			left_pointer += 1;
	        		}
	        		else if(current_value > 0)
	        		{
	        			while(left_pointer < right_pointer and nums[right_pointer - 1] == nums[right_pointer])
	        			{
	        				right_pointer -= 1;
	        			}
	        			right_pointer -= 1;
	        		}
	        		else
	        		{
	        			solution_vec.push_back(vector< int >{nums[pivot_pointer], nums[left_pointer], nums[right_pointer]});
	        			// solution_vec_tups.push_back(make_tuple(nums[pivot_pointer], nums[left_pointer], nums[right_pointer]));
	        			while(left_pointer < right_pointer and nums[left_pointer + 1] == nums[left_pointer])
	        			{
	        				left_pointer += 1;
	        			}
	        			left_pointer += 1;
	        			while(left_pointer < right_pointer and nums[right_pointer - 1] == nums[right_pointer])
	        			{
	        				right_pointer -= 1;
	        			}
	        			right_pointer -= 1;
	        		}
        		}
        	}
        	// print_vec_tuples(solution_vec_tups);
        	return solution_vec;
    	}
};