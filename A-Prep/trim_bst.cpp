// https://leetcode.com/problems/trim-a-binary-search-tree/submissions/
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
    	TreeNode* trimBST(TreeNode* root, int L, int R) 
    	{
    		if(root)
    		{
	    		if(root -> val == L)
	        	{
	        		root -> left = NULL;
	        		root -> right = trimBST(root -> right, L, R);
	        	}
	        	if(root -> val == R)
	        	{
	        		root -> right = NULL;
	        		root -> left = trimBST(root -> left, L, R);
	        	}
	        	if(root -> val < L)
	        	{
	            	root = trimBST(root -> right, L, R);
	        	}
	        	else if(root -> val > R)
	        	{
	        		root = trimBST(root -> left, L, R);
	        	}
	        	else
	        	{
	        		root -> left = trimBST(root -> left, L, R);
	        		root -> right = trimBST(root -> right, L, R);
	        	}
        	}
        	return root;
        }
};