/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    public:
        vector< int > inorder_traversal_vec;
        void generate_inorder_traversal_vec(TreeNode *root, vector< int > &inorder_traversal_vec)
        {
            if(root)
            {
                generate_inorder_traversal_vec(root -> left, inorder_traversal_vec);
                inorder_traversal_vec.push_back(root -> val);
                generate_inorder_traversal_vec(root -> right, inorder_traversal_vec);
            }
            return;
        }

        void dfs(TreeNode *root, int &ans, int L, int R)
        {
            if(root)
            {
                if(root -> val > L)
                {
                    dfs(root -> left, ans, L, R);
                }
                if(root -> val < R)
                {
                    dfs(root -> right, ans, L, R);
                }
                if(root -> val >= L and root -> val <= R)
                {
                    ans += root -> val;
                }
            }
        }
        
        int rangeSumBST(TreeNode* root, int L, int R) 
        {
        //     generate_inorder_traversal_vec(root);        
        //     int L_index = lower_bound(inorder_traversal_vec.begin(), inorder_traversal_vec.end(), L);
        //     int R_index = lower_bound(inorder_traversal_vec.begin(), inorder_traversal_vec.end(), R);
            int ans = 0;
            dfs(root, ans, L, R);
            return ans;
        }
};