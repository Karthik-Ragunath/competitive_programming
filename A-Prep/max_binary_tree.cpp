// https://leetcode.com/problems/maximum-binary-tree/
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
    	TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    	{
        	TreeNode *root = construct_tree(nums, 0, nums.size() - 1);
        	return root; 
    	}

    	TreeNode* construct_tree(vector< int > &nums, int left, int right)
    	{
    		if(left == right)
    		{
    			TreeNode *new_node = new TreeNode(nums[left]);
    			return new_node;
    		}
    		int max_index = find_max(nums, left, right);
    		TreeNode *new_node = new TreeNode(nums[max_index]);
    		if(max_index - 1 >= left)
    		{
    			new_node -> left = construct_tree(nums, left, max_index - 1);
    		}
    		if(max_index + 1 <= right)
    		{
    			new_node -> right = construct_tree(nums, max_index + 1, right);
    		}
    		return new_node;
    	}

    	int find_max(vector< int > &nums, int left, int right)
    	{
    		int max_index = left;
    		int max = nums[left];
    		for(int i = left + 1; i <= right; i++)
    		{
    			if(nums[i] > max)
    			{
    				max = nums[i];
    				max_index = i;
    			}
    		}
    		return max_index;
    	}
};