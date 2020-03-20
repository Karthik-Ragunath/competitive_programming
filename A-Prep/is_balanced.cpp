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
		int tree_heights(TreeNode *root, int height, bool &is_balanced)
		{
			if(root)
			{
				int left_subtree_height = tree_heights(root -> left, height, is_balanced);
				if(is_balanced)
				{
					int right_subtree_height = tree_heights(root -> right, height, is_balanced);
					if(is_balanced)
					{
						int difference = right_subtree_height - left_subtree_height;
						if(difference >= 2 or difference <= -2)
						{
							is_balanced = false;
						}
						int max_height = max(left_subtree_height, right_subtree_height);
						return (max_height + 1);
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
    	bool isBalanced(TreeNode* root) 
    	{
    		bool is_balanced = true;
    		tree_heights(root, 0, is_balanced);
    		return is_balanced;
    	}
};