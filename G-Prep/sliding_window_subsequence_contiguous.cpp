class Solution 
{
	public:
    	string minWindow(string S, string T) 
    	{
        	int s_length = S.length();
        	int t_length = T.length();
        	bool solution_found = false;
        	pair< int, int > solution_pair_index;
            int min_length_window = -1;
        	for(int i = 0, j = 0; i < s_length; i++)
        	{
        		if(S[i] == T[j])
        		{
        			j += 1;
        		}
        		if(j == t_length)
        		{
                    // cout << "solution end index: " << i << "\n";
        			int end_point = i;
        			int k = i;
        			for(; j > 0; k--)
        			{
        				if(S[k] == T[j - 1])
        				{
                            // cout << "k: " << k << " j: " << j << "\n";
        					j -= 1;
        				}
        			}
                    // cout << "j: " << j << " k: " << k << "\n";
        			int start_point = k + 1;
                    if(not solution_found)
                    {
                        min_length_window = end_point - start_point + 1;
        			    solution_pair_index = make_pair(start_point, end_point - start_point + 1);
                        solution_found = true;
                    }
                    else
                    {
                        cout << "end_point: " << end_point << " start_point: " << start_point << "\n";
                        if(end_point - start_point + 1 < min_length_window)
                        {
                            min_length_window = end_point - start_point + 1;
                            solution_pair_index = make_pair(start_point, end_point - start_point + 1);
                        }
                    }
                    i = start_point;
        		    j = 0;
                    cout << "end_point: " << end_point << " start_point: " << start_point << "\n";
        		}
        	}
        	if(solution_found)
        	{
        		return S.substr(solution_pair_index.first, solution_pair_index.second);
        	}
        	else
        	{
        		return "";
        	}
    	}
};