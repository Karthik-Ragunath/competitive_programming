class Solution 
{
	public:
		vector< int > find_next_state(vector< int > &cells)
		{
			int cells_size = cells.size();
			vector< int > new_cells(cells_size);
			new_cells[0] = 0;
			new_cells[cells_size - 1] = 0;
			for(int i = 1; i < (cells_size - 1); i++)
			{
				if(cells[i - 1] == cells[i + 1])
				{
					new_cells[i] = 1;
				}
				else
				{
					new_cells[i] = 0;
				}
			}
			return new_cells;
		}
    
        void print_vec(vector< int > &cells)
        {
            for(int i = 0; i < cells.size(); i++)
            {
                cout << cells[i] << " ";
            }
            cout << "\n";
        }
            
    	vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    	{
            if(cells.empty())
            {
                return cells;
            }
    		unordered_map< int, int > hash_map_states;
    		unordered_map< int, int > state_hash_map;
        	for(int i = 0; i < N; i++)
        	{
    		    int state = 0;
        		for(int j = 0, k = cells.size() - 1; j < cells.size(); j++, k--)
        		{
        			if(cells[k] == 1)
        			{
        				state = state ^ (1 << j);
        			}
        		}
        		auto find_iter = hash_map_states.find(state);
        		if(find_iter != hash_map_states.end())
        		{
        			int state_mapped = find_iter -> second;
        			int number_of_days_ignored = state_mapped - 1;
        			int cycle_period = (i + 1) - state_mapped;
        			int total_cyclic_days = (N + 1) - number_of_days_ignored;
        			int cycle_at_nth_day = total_cyclic_days % cycle_period;
                    if(cycle_at_nth_day == 0)
                    {
                        cycle_at_nth_day = cycle_period;
                    }
        			int state_at_nth_day = state_hash_map[state_mapped + cycle_at_nth_day - 1];
        			vector< int > state_vec(8);
        			int current_index = 8;
        			while(state_at_nth_day > 0)
        			{
        				int value = state_at_nth_day % 2;
        				state_vec[current_index - 1] = value;
        				state_at_nth_day /= 2;
                        current_index--;
        			}
        			return state_vec;
        		}
        		else
        		{
        			hash_map_states.insert(make_pair(state, i + 1));
        			state_hash_map.insert(make_pair(i + 1, state));
        		}
        	    cells = find_next_state(cells);
        	}
        	return cells;
    	}
};