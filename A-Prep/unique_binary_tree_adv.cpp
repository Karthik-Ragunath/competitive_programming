// https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    	vector< TreeNode* > generate_trees(int start, int end, vector< vector< vector< TreeNode* > > > &dp)
    	{
    		if(start > end)
    		{
    			return vector< TreeNode* > { NULL };
    		}
    		vector< TreeNode* > tree_nodes;
    		if((dp[start][end]).empty())
    		{
	    		for(int i = start; i <= end; i++)
	    		{
	    			vector< TreeNode* > left_sub_trees;
	    			if(i - 1 >= start and not (dp[start][i - 1]).empty())
	    			{
	    				left_sub_trees = dp[start][i - 1];
	    			}
	    			else
	    			{
	    				left_sub_trees = generate_trees(start, i - 1, dp);
	    			}
	    			vector< TreeNode* > right_sub_trees;
	    			if(i + 1 <= end and not (dp[i + 1][end]).empty())
	    			{
	    			 	right_sub_trees = dp[i + 1][end];
	    			}
	    			else
	    			{
	    				right_sub_trees = generate_trees(i + 1, end, dp);
	    			}
	    			for(auto left_sub_tree: left_sub_trees)
	    			{
                        for(auto right_sub_tree: right_sub_trees)
                        {
                            TreeNode* tree_node = new TreeNode(i);
                            tree_node -> left = left_sub_tree;
                            tree_node -> right = right_sub_tree;
                            tree_nodes.push_back(tree_node);
                        }
	    			}
                    
	    		}
	    		dp[start][end] = tree_nodes;
	    		return tree_nodes;
    		}
    		else
    		{
    			return dp[start][end];
    		}
    	}

    	vector<TreeNode*> generateTrees(int n) 
    	{
        	if(n == 0)
        	{
                // TreeNode* null_pointer = NULL;
                // vector< TreeNode* > null_vec;
                // null_vec.push_back(null_pointer);
                // return null_vec;
        		return vector< TreeNode* > {};
        	}
        	vector< vector< vector< TreeNode* > > > dp(n + 1, vector< vector< TreeNode* > >(n + 1));
       		vector< TreeNode* > tree_nodes = generate_trees(1, n, dp);
       		return tree_nodes;
    	}
};