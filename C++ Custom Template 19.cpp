#include<bits/stdc++.h>
using namespace std;

class Graph_Node
{
    public:
        int val;
        vector< Graph_Node* > children;
        Graph_Node():val(0){}
        Graph_Node(int x): val(x){}
        
};

// void recurse_dfs_cycles(unordered_map< int, Graph_Node* > graph_node_map, int& cycles, unordered_set< int > &visited_nodes, int current_index)
// {
//     auto graph_node = graph_node_map[current_index];
//     for(auto iter = graph_node -> children.begin(); iter != graph_node -> children.end();)
//     {
//     	// cout << (*iter) -> val << "\n";
//     	// iter++;
//         auto find_iter = visited_nodes.find((*iter) -> val);
//         if(find_iter != visited_nodes.end())
//         {
//             iter = graph_node -> children.erase(iter);
//             cycles += 1;
//         }
//         else
//         {
//             visited_nodes.insert((*iter) -> val);
//             recurse_dfs_cycles(iter, cycles, visited_nodes);
//             ++iter;
//         }
//     }
// }

void recurse_dfs_cycles(Graph_Node* graph_node, int &cycles, unordered_set< int > &visited_nodes)
{
    for(auto iter = graph_node -> children.begin(); iter != graph_node -> children.end();)
    {
    	// cout << (*iter) -> val << "\n";
    	// iter++;
        auto find_iter = visited_nodes.find((*iter) -> val);
        if(find_iter != visited_nodes.end())
        {
            iter = graph_node -> children.erase(iter);
            cycles += 1;
        }
        else
        {
        	cout << "parent: " << graph_node -> val << " child: " << (*iter) -> val << "\n";
            visited_nodes.insert((*iter) -> val);
            recurse_dfs_cycles((*iter), cycles, visited_nodes);
            ++iter;
        }
    }
}

int main() {
	// your code goes here
	vector< pair< int, int > > node_pairs{make_pair(1,3), make_pair(1,4), make_pair(2,5), make_pair(3,8), make_pair(3,4)};
	vector< Graph_Node* > graph_nodes;
	unordered_map< int, Graph_Node* > graph_node_map;
	unordered_set< int > visited_set;
	for(auto pair: node_pairs)
	{
	    auto find_first_iter = visited_set.find(pair.first);
	    if(find_first_iter == visited_set.end())
	    {
	        Graph_Node* local_node = new Graph_Node(pair.first);
	        graph_node_map[pair.first] = local_node;
	        visited_set.insert(pair.first);
	    }
	    auto find_second_iter = visited_set.find(pair.second);
	    if(find_second_iter == visited_set.end())
	    {
	        Graph_Node* loc_node = new Graph_Node(pair.second);
	        graph_node_map[pair.second] = loc_node;
	        visited_set.insert(pair.second);
	    }
	    cout << "1:" << pair.first << " 2:" << pair.second << "\n";
	    (graph_node_map[pair.first] -> children).push_back(graph_node_map[pair.second]);
	}
	int cycles = 0;
	unordered_set< int > visited_nodes;
	int current_index = 1;
	auto graph_node = graph_node_map[current_index];
	recurse_dfs_cycles(graph_node, cycles, visited_nodes);
	cout << cycles << "\n";
	return 0;
}