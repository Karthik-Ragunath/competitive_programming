class Solution 
{
	public:
		void dfs_islands(vector< vector< char > > &grid, vector< vector< bool > > &visited, int row_index, int column_index)
		{
			visited[row_index][column_index] = true;
			if(grid[row_index][column_index + 1] == '1' and visited[row_index][column_index + 1] == false)
			{
				dfs_islands(grid, visited, row_index, column_index + 1);
			}
			if(grid[row_index][column_index - 1] == '1' and visited[row_index][column_index - 1] == false)
			{
				dfs_islands(grid, visited, row_index, column_index - 1);
			}
			if(grid[row_index - 1][column_index] == '1' and visited[row_index - 1][column_index] == false)
			{
				dfs_islands(grid, visited, row_index - 1, column_index);
			}
			if(grid[row_index + 1][column_index] == '1' and visited[row_index + 1][column_index] == false)
			{
				dfs_islands(grid, visited, row_index + 1, column_index);
			}
		}

    	int numIslands(vector<vector<char>>& grid) 
    	{
            if(grid.size() == 0)
            {
                return 0;
            }
        	vector< char > temp_vec(grid[0].size(), '0');
        	grid.insert(grid.begin(), temp_vec);
        	grid.push_back(temp_vec);
        	for(int i = 0; i < grid.size(); i++)
        	{
        		grid[i].insert(grid[i].begin(), '0');
        		grid[i].push_back('0');
        	}
        	int island_count = 0;
        	vector< vector< bool > > visited(grid.size(), vector< bool >(grid[0].size()));
        	// cout << "grid_size: " << grid.size() << " inner vec size: " << grid[0].size() << "\n";
        	for(int i = 1; i < grid.size() - 1; i++)
        	{
        		for(int j = 1; j < grid[0].size() - 1; j++)
        		{
        			if(!visited[i][j] and grid[i][j] == '1')
        			{
        				dfs_islands(grid, visited, i, j);
        				island_count += 1;
        			}
        		}
        	}
        	return island_count;
    	}
};