// https://leetcode.com/problems/invert-binary-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        TreeNode* new_node = new TreeNode;
        if(root)
        {
            new_node -> val = root -> val;
            if(root -> right)
            {
                new_node -> left = invertTree(root -> right);
            }
            else
            {
                new_node -> left = NULL;
            }
            if(root -> left)
            {
                new_node -> right = invertTree(root -> left);
            }
            else
            {
                new_node -> right = NULL;
            }
            return new_node;
        }
        else
        {
            return NULL;
        }
    }
};