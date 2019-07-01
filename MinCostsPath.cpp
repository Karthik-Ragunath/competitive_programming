#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++)
    {
        long long int x;
        long long int y;
        long long int z;
        long long int A;
        long long int B;
        long long int C;
        cin >> x;
        cin >> y;
        cin >> z;
        cin >> A;
        cin >> B;
        cin >> C;
        long long int grid[x + 1][y + 1][z + 1] = {0};
        for(long long int j = 1; j <= x; j++)
        {
            grid[j][0][0] = grid[j - 1][0][0] + A;
        }
        for(long long int j = 1; j <= y; j++)
        {
            grid[0][j][0] = grid[0][j - 1][0] + A;
        }
        for(long long int j = 1; j <= z; j++)
        {
            grid[0][0][j] = grid[0][0][j - 1] + A;
        }
        for(long long int j = 0; j <= x; j++)
        {
            for(long long int k = 0; k <= y; k++)
            {
                for(long long int l = 0; l <= z; l++)
                {
                    if((j == 0 && k == 0 && l == 0) || (j == 0 && k == 0) || (k == 0 && l == 0) || (l == 0 && j == 0))
                    {
                        continue;
                    }
                    else
                    {
                        if(j > 0 && k > 0 && l > 0)
                        {
                            grid[j][k][l] = min({(grid[j - 1][k][l] + A), (grid[j][k - 1][l] + A), (grid[j][k][l - 1] + A), (grid[j - 1][k - 1][l] + B), (grid[j][k - 1][l - 1] + B), (grid[j - 1][k][l - 1] + B), (grid[j - 1][k - 1][l - 1] + C)});
                        }
                        else if(j == 0)
                        {
                            grid[j][k][l] = min({(grid[j][k - 1][l] + A), (grid[j][k][l - 1] + A), (grid[j][k - 1][l - 1] + B)});
                        }
                        else if(k == 0)
                        {
                            grid[j][k][l] = min({(grid[j - 1][k][l] + A), (grid[j][k][l - 1] + A), (grid[j - 1][k][l - 1] + B)});
                        }
                        else if(l == 0)
                        {
                            grid[j][k][l] = min({(grid[j - 1][k][l] + A), (grid[j][k - 1][l] + A), (grid[j - 1][k - 1][l] + B)});
                        }
                    }
                }
            }
        }
        cout << grid[x][y][z] << endl;
    }
    return 0;
}
