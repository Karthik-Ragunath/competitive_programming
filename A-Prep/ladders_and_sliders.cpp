class Solution 
{
	public:
    	int snakesAndLadders(vector<vector<int>>& board) 
    	{
        	vector< int > board_flattened;
            bool reverse_row = false;
        	for(int i = board.size() - 1; i >= 0; i--)
        	{
                if(reverse_row)
                {
                    reverse(board[i].begin(), board[i].end());
                }
        		board_flattened.insert(board_flattened.end(), board[i].begin(), board[i].end());
                reverse_row = reverse_row ? false : true;
        	}
            queue< int > bfs;
            vector< int > distance(board_flattened.size(), -1);
            bfs.push(0);
            distance[0] = 0;
        	// cout << "Size: " << board_flattened.size() << "\n";
            bool solution_found = false;
            int solution = -1;
            while(not bfs.empty())
            {
                int index = bfs.front();
                bfs.pop();
                for(int i = 1; i <= 6; i++)
                {
                    if(board_flattened[index + i] == -1)
                    {
                        if(distance[index + i] == -1)
                        {
                            distance[index + i] = distance[index] + 1;
                            // cout << "Index: " << (index + i) << " Distance: " << distance[index + i] << "\n";
                            if(index + i == board_flattened.size() - 1)
                            {
                                solution_found = true;
                                solution = distance[index + i];
                                break;
                            }
                            bfs.push(index + i);
                        }
                    }
                    else if(distance[board_flattened[index + i] - 1] == -1)
                    {
                        distance[board_flattened[index + i] - 1] = distance[index] + 1;
                        // cout << "Index: " << (board_flattened[index + i] - 1) << " Distance: " << distance[board_flattened[index + i] - 1] << "\n";
                        if(board_flattened[index + i] - 1 == board_flattened.size() - 1)
                        {
                            solution_found = true;
                            solution = distance[board_flattened[index + i] - 1];
                            break;
                        }
                        bfs.push(board_flattened[index + i] - 1);
                    }
                }
                if(solution_found)
                {
                    break;
                }
            }
        	return solution;
    	}
};