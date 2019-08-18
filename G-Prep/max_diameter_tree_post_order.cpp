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
    int post_order_traversal(TreeNode *root, int size, int &max_diameter)
    {
        int left_size = 0;
        int right_size = 0;
        if(root)
        {
            if(root -> left)
            {
                left_size = post_order_traversal(root -> left, size, max_diameter);
            }
            if(root -> right)
            {
                right_size = post_order_traversal(root -> right, size, max_diameter);
            }
        }
        if((left_size + right_size + 1) > max_diameter)
        {
            max_diameter = left_size + right_size + 1;
        }
        return max(left_size + 1, right_size + 1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int max_diameter = 0;
        post_order_traversal(root, 0, max_diameter);
        return max_diameter - 1;
    }
};