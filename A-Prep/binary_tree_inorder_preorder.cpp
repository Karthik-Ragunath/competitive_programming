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
		TreeNode* build_tree(vector< int > &preorder, vector< int >& inorder, int &preorder_cur_index, int inorder_cur_start_index, int inorder_cur_end_index, unordered_map< int, int > &inorder_hash)
		{
			TreeNode* local_root = new TreeNode(preorder[preorder_cur_index]);
			int inorder_local_root_index = inorder_hash[preorder[preorder_cur_index]];
			if(inorder_cur_start_index == inorder_local_root_index)
			{
				local_root -> left = NULL;
			}
			else
			{
				preorder_cur_index += 1;
				local_root -> left = build_tree(preorder, inorder, preorder_cur_index, inorder_cur_start_index, inorder_local_root_index - 1, inorder_hash);
			}
			if(inorder_cur_end_index == inorder_local_root_index)
			{
				local_root -> right = NULL;
			}
			else
			{
				preorder_cur_index += 1;
				local_root -> right = build_tree(preorder, inorder, preorder_cur_index, inorder_local_root_index + 1, inorder_cur_end_index, inorder_hash);
			}
			return local_root;
		}

    	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    	{
            if(preorder.empty())
            {
                return NULL;
            }
            unordered_map< int, int > inorder_hash;
            for(int i = 0; i < inorder.size(); i++)
            {
            	inorder_hash[inorder[i]] = i;
            }
            int preorder_cur_index = 0;
            TreeNode *root = build_tree(preorder, inorder, preorder_cur_index, 0, inorder.size() - 1, inorder_hash);
            return root;
    	}
};