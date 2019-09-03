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
    	void find_max_height(TreeNode* root, int height, int &max_height)
    	{
    		if(root)
    		{
    			height += 1;
    			if(height > max_height)
    			{
    				max_height = height;
    			}
    			find_max_height(root -> left, height, max_height);
    			find_max_height(root -> right, height, max_height);
    		}
    		return;
    	}

        vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
        {
            if(not root)
            {
                return vector< vector< int > >{};
            }
        	int max_height = 0;
        	find_max_height(root, 0, max_height);
        	vector< vector< int > > zig_zag_levels(max_height);
            vector< vector< TreeNode* > > zig_zag_level_nodes(max_height);
            zig_zag_levels[0].push_back(root -> val);
            zig_zag_level_nodes[0].push_back(root);
            for(int level = 1; level < max_height; level++)
            {
                vector< TreeNode* > old_levels(zig_zag_level_nodes[level - 1]);
                reverse(old_levels.begin(), old_levels.end());
                bool is_odd_level = level % 2 == 1 ? true : false;
                for(int i = 0; i < old_levels.size(); i++)
                {
                    if(is_odd_level)
                    {
                        if(old_levels[i] -> right)
                        {
                            zig_zag_level_nodes[level].push_back(old_levels[i] -> right);
                            zig_zag_levels[level].push_back(old_levels[i] -> right -> val);
                        }
                        if(old_levels[i] -> left)
                        {
                            zig_zag_level_nodes[level].push_back(old_levels[i] -> left);
                            zig_zag_levels[level].push_back(old_levels[i] -> left -> val);
                        }
                    }
                    else
                    {
                        if(old_levels[i] -> left)
                        {
                            zig_zag_level_nodes[level].push_back(old_levels[i] -> left);
                            zig_zag_levels[level].push_back(old_levels[i] -> left -> val);
                        }
                        if(old_levels[i] -> right)
                        {
                            zig_zag_level_nodes[level].push_back(old_levels[i] -> right);
                            zig_zag_levels[level].push_back(old_levels[i] -> right -> val);
                        }
                    }
                }
            }
           	return zig_zag_levels;
        }
};