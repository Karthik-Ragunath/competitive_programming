// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
     	vector< vector< int > > mat(m, vector< int >(n));
     	for(int i = 0; i < n; i++)
     	{
     		mat[0][i] = 1;
     	}
     	for(int i = 0; i < m; i++)
     	{
     		mat[i][0] = 1;
     	}
     	for(int i = 1; i < m; i++)
     	{
     		for(int j = 1; j < n; j++)
     		{
     			mat[i][j] = mat[i][j - 1] + mat[i - 1][j];
     		}
     	}
     	return mat[m - 1][n - 1];
    }
};