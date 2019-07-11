/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string serializer_solution = "[";
            queue< TreeNode* > serializer_queue;
            serializer_queue.push(root);
            while(!serializer_queue.empty())
            {
                TreeNode* tree_node = serializer_queue.front();
                serializer_queue.pop();
                if(tree_node != NULL)
                {
                    serializer_queue.push(tree_node -> left);
                    serializer_queue.push(tree_node-> right);
                    serializer_solution += to_string(tree_node -> val);
                    serializer_solution += ",";
                }
                else
                {
                    serializer_solution += "null,";
                }
            }
            auto last_char_iter = serializer_solution.rbegin();
            if(*last_char_iter == ',')
            {
                serializer_solution.erase(serializer_solution.end() - 1);
            }
            serializer_solution += ']';
            // cout << serializer_solution << "\n";
            return serializer_solution;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) 
        {
            TreeNode* root_node = new TreeNode(0);
            data.erase(data.begin());
            data.erase(data.end() - 1);
            vector<string> tree_vals;
            stringstream ss(data);
            string token;
            while(getline(ss, token, ','))
            {
                tree_vals.push_back(token);
            }
            // for(auto token: tree_vals)
            // {
            //     cout << token << "\n";
            // }
            if(tree_vals.size() >= 0 and tree_vals[0] != "null")
            {
                root_node -> val = stoi(tree_vals[0]);
                root_node -> left = NULL;
                root_node -> right = NULL;
                queue< TreeNode* > bfs_tree;
                bfs_tree.push(root_node);
                int tree_vals_length = tree_vals.size();
                for(int i = 0; i < tree_vals_length;)
                {
                    TreeNode* node = bfs_tree.front();
                    bfs_tree.pop();
                    if(i + 1 < tree_vals_length and tree_vals[i + 1] != "null")
                    {
                        TreeNode* node_left = new TreeNode(stoi(tree_vals[i + 1]));
                        node -> left = node_left;
                        bfs_tree.push(node -> left);
                    }
                    if(i + 2 < tree_vals_length and tree_vals[i + 2] != "null")
                    {
                        TreeNode* node_right = new TreeNode(stoi(tree_vals[i + 2]));
                        node -> right = node_right;
                        bfs_tree.push(node -> right);
                    }
                    i += 2;
                }
            }
            else
            {
                root_node = NULL;
            }
            
            return root_node;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));