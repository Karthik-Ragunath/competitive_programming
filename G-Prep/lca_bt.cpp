/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recurseAndFindLCA(TreeNode *root, int smaller_val, int larger_val, bool &solution_found, TreeNode*& lca_node)
    {
        if(root)
        {
            if(root -> val > smaller_val and root -> val < larger_val)
            {
                // cout << "Sol found: " << root -> val << "\n";
                solution_found = true;
                lca_node = root;
                return;
            }
            else if(root -> val == smaller_val)
            {
                // cout << "Sol found: " << root -> val << "\n";
                solution_found = true;
                lca_node = root;
                return;
            }
            else if (root -> val == larger_val)
            {
                // cout << "Sol found: " << root -> val << "\n";
                solution_found = true;
                lca_node = root;
                return;
            }
            else
            {
                if(root -> left)
                {
                    recurseAndFindLCA(root -> left, smaller_val, larger_val, solution_found, lca_node);          
                }
                if(not solution_found)
                {
                    if(root -> right)
                    {
                        recurseAndFindLCA(root -> right, smaller_val, larger_val, solution_found, lca_node);
                    }
                }
                return;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int p_val = p -> val;
        int q_val = q -> val;
        if(p_val > q_val)
        {
            int t = p_val;
            p_val = q_val;
            q_val = t;
        }
        TreeNode *lca_node = new TreeNode(-1);
        bool solution_found = false;
        recurseAndFindLCA(root, p_val, q_val, solution_found, lca_node);
        if(solution_found)
        {
            return lca_node;
        }
        else
        {
            // cout << "No sol found" << "\n";
            return lca_node;
        }
    }
};