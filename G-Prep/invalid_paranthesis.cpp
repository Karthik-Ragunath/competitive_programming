class Solution 
{
	public:  
		void process_strings(string s, int starting_index_i, int starting_index_j, vector< string > &solutions, char start_brace, char end_brace)
		{
            // cout << "======" << "\n";
			int string_length = s.length();
			int counter = 0;
			for(int i = starting_index_i; i < string_length; i++)
			{
                // cout << "debug 3: " << s[i] << "\n";
				if(s[i] == end_brace)
				{
					counter -= 1;
				}
				else if(s[i] == start_brace)
				{
					counter += 1;
				}
				if(counter < 0)
				{
					for(int j = starting_index_j; j <= i; j++)
					{
						if(s[j] == end_brace and (j == starting_index_j or s[j - 1] != end_brace))
						{
                            // cout << "debug s: " << s << "\n";
							process_strings((s.substr(0, j) + s.substr(j + 1, string_length - 1 - j)), i, j,  solutions, start_brace, end_brace);
						}
					}
					return;
				}
			}
			solutions.push_back(s);
		}

		void print_string_vec(vector< string > &reversed_solutions)
		{
			int vec_len = reversed_solutions.size();
			for(int i = 0; i < vec_len; i++)
			{
				cout << reversed_solutions[i] << "\n";
			}
		}

    	vector<string> removeInvalidParentheses(string s) 
    	{
    		vector< string > forward_pass_solutions;
    		process_strings(s, 0, 0, forward_pass_solutions, '(', ')');
            print_string_vec(forward_pass_solutions);
    		int forward_pass_solutions_length = forward_pass_solutions.size();
    		vector< string > reverse_pass_solutions;
    		for(int i = 0; i < forward_pass_solutions_length; i++)
    		{
                string fwd_pass_copy = forward_pass_solutions[i];
    			reverse(fwd_pass_copy.begin(), fwd_pass_copy.end());
    			process_strings(fwd_pass_copy, 0, 0, reverse_pass_solutions, ')', '(');
    		}
    		vector< string > actual_solutions;
    		for(int i = 0; i < reverse_pass_solutions.size(); i++)
    		{
                reverse(reverse_pass_solutions[i].begin(), reverse_pass_solutions[i].end());
    			actual_solutions.push_back(reverse_pass_solutions[i]);
    		}
    		// print_string_vec(actual_solutions);
    		return actual_solutions;
    	}
};