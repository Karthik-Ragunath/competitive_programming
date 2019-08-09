// Perfect Rectangle
class ComparePairs
{
	public:
		bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
		{
			if(pair_1.first < pair_2.first)
			{
				return true;
			}
			else
			{
				if(pair_1.first == pair_2.first and pair_1.second < pair_2.second)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
};

class Solution
{
	public:
		bool merge(vector< pair< int, int > > &line_edges, vector< pair< int, int > > &merged_line_edges)
		{
			sort(line_edges.begin(), line_edges.end(), ComparePairs());
			int min_over_all = line_edges[0].first;
			for(int i = 1; i < line_edges.size(); i++)
			{
				if(line_edges[i - 1].second > line_edges[i].first)
				{
					return false;
				}
				else if(line_edges[i].first > line_edges[i - 1].second)
				{
					merged_line_edges.emplace_back(min_over_all, line_edges[i - 1].second);
					min_over_all = line_edges[i].first;
				}
			}
			merged_line_edges.emplace_back(min_over_all, line_edges[line_edges.size() - 1].second);
			return true;
		}

		bool isRectangleCover(vector<vector<int>>& rectangles) 
		{
			if(rectangles.empty())
			{
				return true;
			}

			map< int, vector< pair< int, int > > > start_lines;
			map< int, vector< pair< int, int > > > end_lines;
			
			for(int i = 0; i < rectangles.size(); i++)
			{
				int x_left_bottom = rectangles[i][0];
				int x_right_top = rectangles[i][2];
				int y_bottom = rectangles[i][1];
				int y_top = rectangles[i][3];
				start_lines[x_left_bottom].emplace_back(y_bottom, y_top);
				end_lines[x_right_top].emplace_back(y_bottom, y_top);
			}

			auto start_line_iter = start_lines.begin();
			vector< pair< int, int > > merged_start_line;
			bool is_valid = merge(start_line_iter -> second, merged_start_line);
			if(not is_valid)
			{
				return false;
			}
			start_lines.erase(start_line_iter);
			int j = 0, end_lines_size = end_lines.size();
			for(auto end_line_iter = end_lines.begin(); end_line_iter != end_lines.end(); end_line_iter++, j++)
			{
				vector< pair< int, int > > merged_end_line;
				bool is_valid_end_line = merge(end_line_iter -> second, merged_end_line);
				if(not is_valid_end_line)
				{
					return false;
				}
				if(j == end_lines_size - 1)
				{
					continue;
				}
				auto find_iter = start_lines.find(end_line_iter -> first);
				if(find_iter != start_lines.end())
				{
					vector< pair< int, int > > local_merged_start_line;
					bool valid_start_line = merge(find_iter -> second, local_merged_start_line);
					if(not valid_start_line)
					{
						return false;
					}
					if(local_merged_start_line != merged_end_line)
					{
						return false;
					}
					start_lines.erase(find_iter);
				}
				else
				{
					return false;
				}
			}
			return start_lines.empty();
		}
};