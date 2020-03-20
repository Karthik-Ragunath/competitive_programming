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
    bool lca_binary_tree(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&solution)
    {
    	bool found_left = false, cur_node = false, found_right = false;
        if(root)
        {
            found_left = lca_binary_tree(root -> left, p, q, solution);
            if(not solution)
            {
	            if(root -> val == p -> val or root -> val == q -> val)
	            {
	            	cur_node = true;
	            }
	            if(found_left and cur_node)
	            {
	            	solution = root;
	            }
	            else
	            {
	            	found_right = lca_binary_tree(root -> right, p, q, solution);
	            	if(not solution)
	            	{
		            	if((found_right and found_left) or (found_right and cur_node))
		            	{
		            		solution = root;
		            	}
	            	}
	            }
        	}
        }
        return (found_left or cur_node or found_right);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
    	TreeNode *solution = NULL;
        lca_binary_tree(root, p, q, solution);
        return solution;
    }
};