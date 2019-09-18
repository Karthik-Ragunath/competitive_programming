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
		TreeNode *first = NULL, *second = NULL, *pred = NULL;
		void traverse(TreeNode *root)
		{
			if(root == NULL)
    		{
    			return;
    		}
    		traverse(root -> left);
    		if(not first and pred and pred -> val > root -> val)
    		{
    			first = pred;
    			second = root;
    		}
    		else if(pred and pred -> val > root -> val)
    		{
    			second = root;
    		}
    		pred = root;
    		traverse(root -> right);
		}

    	void recoverTree(TreeNode* root) 
    	{
    		traverse(root);
    		int temp = first -> val;
    		first -> val = second -> val;
    		second -> val = temp;
    	}
};