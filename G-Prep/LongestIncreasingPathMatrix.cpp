class Solution 
{
	public:
		int dfs(int row, int column, vector< vector< int > > &matrix, vector< vector< int > > &cache_matrix, vector< vector< bool > > &visited, int direction_x[], int direction_y[], int &global_maximum)
		{
			if(row >= 1 and column >= 1 and row <= matrix.size() - 2 and column <= matrix[0].size() - 2)
			{
				if(not visited[row][column])
				{
					visited[row][column] = true;
					int local_maximum = 1;
					for(int i = 0, j = 0; i < 4 and j < 4; i++, j++)
					{
						if(matrix[row + direction_x[i]][column + direction_y[i]] > matrix[row][column])
						{
							int local_direction_solution = dfs(row + direction_x[i], column + direction_y[i], matrix, cache_matrix, visited, direction_x, direction_y, global_maximum) + 1;
							if(local_direction_solution > local_maximum)
							{
								local_maximum = local_direction_solution;
							}
							if(local_direction_solution > global_maximum)
							{
								global_maximum = local_direction_solution;
							}
						}
					}
					cache_matrix[row][column] = local_maximum;
					return local_maximum;
				}
				else
				{
					return cache_matrix[row][column];
				}
			}
			else
			{
				return 0;
			}
		}

    	int longestIncreasingPath(vector<vector<int>>& matrix) 
    	{
            if(matrix.empty())
            {
                return 0;
            }
        	vector< int > temp_vec(matrix[0].size() + 2, 1000000000);
        	for(int i = 0; i < matrix.size(); i++)
        	{
        		matrix[i].insert(matrix[i].begin(), 1000000000);
        		matrix[i].push_back(1000000000);
        	}
        	matrix.insert(matrix.begin(), temp_vec);
        	matrix.push_back(temp_vec);
        	vector< vector< int > > cache_matrix(matrix.size(), vector< int >(matrix[0].size()));
        	vector< vector< bool > > visited(matrix.size(), vector< bool >(matrix[0].size()));
        	int direction_x[] = {-1, 1, 0, 0};
        	int direction_y[] = {0, 0, -1, 1};
        	int global_maximum = 0;
        	for(int i = 1; i < matrix.size() - 1; i++)
        	{
        		for(int j = 1; j < matrix[0].size() - 1; j++)
        		{
        			if(not visited[i][j])
        			{
        				dfs(i, j, matrix, cache_matrix, visited, direction_x, direction_y, global_maximum);
        			}
        		}
        	}
        	return global_maximum;
    	}
};