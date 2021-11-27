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
		TreeNode* inverse_post_order(TreeNode* root, int &val_added)
		{
        	if(root)
        	{
        		if(root -> right)
        		{
        			inverse_post_order(root -> right, val_added);
        		}
        		root -> val = root -> val + val_added;
        		val_added = root -> val;
        		if(root -> left)
        		{
        			inverse_post_order(root -> left, val_added);
        		}
        	}
        	return root;
		}

    	TreeNode* bstToGst(TreeNode* root) 
    	{
    		int val_added = 0;
    		root = inverse_post_order(root, val_added);
    		return root;
    	}
};