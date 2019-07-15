struct HASH
{
	size_t operator()(const pair< int, int > pair_val) const
	{
		return hash< uint64_t >()((uint64_t)pair_val.first ^ ((uint64_t)pair_val.second << 32));
	}
};

class Solution 
{
	public:
    	bool isBipartite(vector<vector<int>>& graph) 
    	{
        	queue< int > separator_queue;
        	int graph_size = graph.size();
        	vector< vector< int > > edges_vec(graph_size);
            bool atleast_one_edge_present = false;
            unordered_set< int > nodes_with_edges;
        	for(int i = 0; i < graph_size; i++)
        	{
        		int inner_vec_size = graph[i].size();
                if(inner_vec_size != 0)
                {
                	atleast_one_edge_present = true;
                }
                if(inner_vec_size > 0)
                {
                    nodes_with_edges.insert(i);
                }
        		for(int j = 0; j < inner_vec_size; j++)
        		{
    				edges_vec[i].push_back(graph[i][j]);
        		}
        	}
            if(!atleast_one_edge_present)
            {
                return true;
            }
         	// unordered_set< pair< int, int >, HASH > visited_sets;
         	// int a = 12, b = 23;
         	// visited_sets.insert(make_pair(a, b));
         	// if(visited_sets.find(make_pair(a, b)) != visited_sets.end())
         	// {
         	// 	cout << "working" << "\n";
         	// }
         	bool is_bipartite = true;
         	// int visited_count = 0;
            while(nodes_with_edges.size() > 0 and is_bipartite)
            {
                int first_index = *(nodes_with_edges.begin());
                vector< int > color(graph.size(), -1);
         	    separator_queue.push(first_index);
         	    color[first_index] = 1;
                while(!separator_queue.empty())
                {
                    int parent_node = separator_queue.front();
                    auto find_iter = nodes_with_edges.find(parent_node);
                    if(find_iter != nodes_with_edges.end())
                    {
                        nodes_with_edges.erase(find_iter);
                    }
                    separator_queue.pop();
                    int color_index = color[parent_node];
                    // visited_count += 1;
                    for(auto iter = edges_vec[parent_node].begin(); iter != edges_vec[parent_node].end(); iter++)
                    {
                        int other_node = *iter;
                        if(color[other_node] == -1)
                        {
                            color[other_node] = color[parent_node] == 1 ? 2 : 1;
                            separator_queue.push(other_node);
                        }
                        else
                        {
                            if(color[other_node] == color[parent_node])
                            {
                                is_bipartite = false;
                                break;
                            }
                        }
                    }
                    if(!is_bipartite)
                    {
                        break;
                    }
                }
            }
         	// return (is_bipartite && (visited_count == graph.size()));
            return is_bipartite;
    	}
};