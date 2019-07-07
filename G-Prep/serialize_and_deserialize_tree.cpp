/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
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
                serializer_queue.push(tree_node->right);
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
            // serializer_solution.end() - 1
            serializer_solution.erase(serializer_solution.end() - 1);
        }
        serializer_solution += ']';
        cout << serializer_solution << "\n";
        return serializer_solution;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* new_node = new TreeNode;
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
        
        return new_node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));