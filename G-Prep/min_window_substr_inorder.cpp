class Solution 
{
	public:
		void min_window_compare(int t_length, int left_index, int right_index, int &min_window_length, bool &solution_found, bool &end_solution_reached, pair< int, int > &solution_pair_index)
		{
			int window_length = right_index - left_index + 1;
			if(solution_found)
			{
				solution_pair_index = window_length < min_window_length ? make_pair(left_index, right_index) : solution_pair_index;
				min_window_length = window_length < min_window_length ? window_length : min_window_length;
				end_solution_reached = min_window_length == t_length ? true : false;
			}
			else
			{
				solution_found = true;
				min_window_length = window_length;
				end_solution_reached = min_window_length == t_length ? true : false;
                solution_pair_index = make_pair(left_index, right_index);
			}
		}

	    string minWindow(string S, string T) 
	    {
	     	int s_length = S.length(), t_length = T.length(), unique_s_chars = 0, unique_t_chars = 0, unique_t_chars_in_window = 0, min_window_length = -1;;
	     	unordered_map< int, int > t_map, s_map, window_chars_map;
	     	vector< pair< char, int > > char_index_pair_vec;
            bool solution_found = false, end_solution_reached = false;
            pair< int, int > solution_pair_index;
	     	for(int i = 0; i < t_length; i++)
	     	{
	     		t_map[(int)(T[i] - 'A')] += 1;
	     		if(t_map[(int)(T[i] - 'A')] == 1)
				{
					unique_t_chars += 1;
				}
	     	}   
	     	for(int i = 0; i < s_length; i++)
	     	{
	     		int char_val = (int)(S[i] - 'A');
	     		auto find_iter = t_map.find(char_val);
	     		if(find_iter != t_map.end())
	     		{
	     			char_index_pair_vec.push_back(make_pair(S[i], i));
	     		}
	     	}
	     	int left_index = 0, right_index = -1, index_pair_vec_len = char_index_pair_vec.size();
	     	while(right_index + 1 < index_pair_vec_len and char_index_pair_vec[left_index].second + t_length - 1 < s_length)
	     	{
	     		right_index += 1;
	     		int char_val = (int)(char_index_pair_vec[right_index].first - 'A');
                window_chars_map[char_val] += 1;
                if(window_chars_map[char_val] == t_map[char_val])
                {
                    // if(char_val == T[unique_t_chars_in_window])
                    // {
                    // 	unique_t_chars_in_window++;
                    // }
                    unique_t_chars_in_window++;
                }
	     		if(unique_t_chars_in_window == unique_t_chars)
	     		{
                    // cout << "left_index: " << left_index << " right_index: " << right_index << " substr: " << S.substr(char_index_pair_vec[left_index].second, char_index_pair_vec[right_index].second - char_index_pair_vec[left_index].second + 1) << "\n";
	     			min_window_compare(t_length, char_index_pair_vec[left_index].second, char_index_pair_vec[right_index].second, min_window_length, solution_found, end_solution_reached, solution_pair_index);
	     			if(end_solution_reached)
	     			{
	     				break;
	     			}
	     			while(char_index_pair_vec[left_index].second <= char_index_pair_vec[right_index].second)
	     			{
	     				int char_val_popped = (int)(char_index_pair_vec[left_index].first - 'A');
	     				left_index += 1;
	     				window_chars_map[char_val_popped] -= 1;
	     				if(window_chars_map[char_val_popped] >= t_map[char_val_popped])
	     				{
	     					min_window_compare(t_length, char_index_pair_vec[left_index].second, char_index_pair_vec[right_index].second, min_window_length, solution_found, end_solution_reached, solution_pair_index);
	     					if(end_solution_reached)
	     					{
	     						break;
	     					}
	     				}
	     				else
	     				{
	     					unique_t_chars_in_window--;
	     					break;
	     				}
	     			}
	     		}
	     		if(end_solution_reached)
	     		{
	     			break;
	     		}
	     	}
	     	if(solution_found)
	     	{
	     		return S.substr(solution_pair_index.first, solution_pair_index.second - solution_pair_index.first + 1);
	     	}
	     	else
	     	{
	     		return "";
	     	}
	    }
};