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
    
	TreeNode* pre_order(TreeNode *root, int &size)
	{
		/* To get leaf nodes size alone
		if(not root -> left and not root -> right)
		{
			size += 1;
		}
		*/
		if(root)
		{
			size += 1;
            cout << root -> val << "\n";
            if(root -> left)
            {
                pre_order(root -> left, size);
            }
            if(root -> right)
            {
                pre_order(root -> right, size);
            }
		}
		return root;
	}

    int countNodes(TreeNode* root) 
    {
    	int size = 0;
  		pre_order(root, size);
  		return size;	      
    }
};