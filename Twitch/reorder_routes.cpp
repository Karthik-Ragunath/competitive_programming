class Solution {
public:
    void dfs(vector< bool > &visited, int &visited_count, vector< vector< int > > &source_to_dest, vector< vector< int > > &dest_to_source, int parent_index, int &inversion_count, int n)
    {
        // cout << "Source: " << parent_index << "\n";
        for(auto connection_node: source_to_dest[parent_index])
        {
            // cout << "1: " << connection_node << "\n";
            if(not visited[connection_node])
            {
                // cout << "2: " << connection_node << "\n";
                inversion_count += 1;
                visited[connection_node] = true;
                visited_count += 1;
                if(visited_count == n)
                {
                    return;
                }
                dfs(visited, visited_count, source_to_dest, dest_to_source, connection_node, inversion_count, n);
            }
        }
        for(auto connection_node: dest_to_source[parent_index])
        {
            // cout << "3: " << connection_node << "\n";
            if(not visited[connection_node])
            {
                // cout << "4: " << connection_node << "\n";
                visited[connection_node] = true;
                visited_count += 1;
                if(visited_count == n)
                {
                    return;
                }
                dfs(visited, visited_count, source_to_dest, dest_to_source, connection_node, inversion_count, n);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        // vector< vector< int > > connections(n, vector< int >(n, 0));
        vector< vector< int > > source_to_dest(n);
        vector< vector< int > > dest_to_source(n);
        int inversion_count = 0;
        for(auto vec: connections)
        {
            int source = vec[0];
            int destination = vec[1];
            // connections[source][destination] = 1;
            // connections[destination][source] = -1;
            source_to_dest[source].push_back(destination);
            dest_to_source[destination].push_back(source);
        }
        vector< bool > visited(n, false);
        int visited_count = 1;
        int source = 0;
        visited[0] = true;
        dfs(visited, visited_count, source_to_dest, dest_to_source, source, inversion_count, n);
        // cout << inversion_count << "\n";
        return inversion_count;
    }
};