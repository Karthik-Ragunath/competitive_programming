/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeNodeModified
{
    public:
        int val;
        TreeNodeModified *left;
        TreeNodeModified *right;
        int sum;
        TreeNodeModified(int x): val(x), left(NULL), right(NULL), sum(0) {}
};

class Solution 
{
    public:
        int global_max = 0;
        bool global_max_set = false;
        
        int max_sum_path_finder(TreeNode *root)
        {
            if(root != NULL)
            {
                if(root -> left != NULL or root -> right != NULL)
                {
                    int sum_left = max_sum_path_finder(root ->left);
                    int sum_right = max_sum_path_finder(root -> right);
                    // cout << "sum_left: " << sum_left << " sum_right: " << sum_right << " val: " << root -> val << " global_max: " << global_max << "\n";
                    int max_val = max(root -> val, max(root -> val + sum_left + sum_right, max(root -> val + sum_left, root -> val + sum_right)));
                    if(global_max < max_val)
                    {
                        global_max = max_val;
                        // cout << "global max setting: " << global_max << "\n";
                    }
                    int max_path_val = max(root -> val, max(root -> val + sum_left, root -> val + sum_right));
                    return max_path_val;
                }
                else
                {
                    if(global_max_set)
                    {
                        if(global_max < root -> val)
                        {
                            global_max = root -> val;
                            // cout << "global max setting: " << global_max << "\n";
                        }
                    }
                    else
                    {
                        global_max = root -> val;
                        // cout << "global max setting: " << global_max << "\n";
                        global_max_set = true;
                    }
                    return root -> val;
                }
            }
            else
            {
                return -1000000000;
            }
        }

        int maxPathSum(TreeNode* root) 
        {
            global_max = 0;
            global_max_set = false;
            if(root != NULL)
            {
                int max_val_at_root = max_sum_path_finder(root);
            }
            return global_max;
        }
};