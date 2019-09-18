// https://leetcode.com/problems/unique-binary-search-trees/
class Solution 
{
	public:
    	int numTrees(int n) 
    	{
        	vector< int > unique_tree(n + 1);
        	unique_tree[0] = 1;
        	unique_tree[1] = 1;
        	for(int i = 2; i <= n; i++)
        	{
        		for(int j = 1; j <= i; j++)
        		{
        			unique_tree[i] += (unique_tree[j - 1] * unique_tree[i - j]);
        		}
        	}
        	return unique_tree[n];
    	}
};