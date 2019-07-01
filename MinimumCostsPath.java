import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MinimumCostsPath
{
    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int x = in.nextInt();
            int y = in.nextInt();
            int z = in.nextInt();
            int A = in.nextInt();
            int B = in.nextInt();
            int C = in.nextInt();
            int[][][] grid = new int[x + 1][y + 1][z + 1];
            for(int j = 1; j <= x; j++)
            {
                grid[j][0][0] = grid[j - 1][0][0] + A;
            }
            for(int j = 1; j <= y; j++)
            {
                grid[0][j][0] = grid[0][j - 1][0] + A;
            }
            for(int j = 1; j <= z; j++)
            {
                grid[0][0][j] = grid[0][0][j - 1] + A;
            }
            for(int j = 0; j <= x; j++)
            {
                for(int k = 0; k <= y; k++)
                {
                    for(int l = 0; l <= z; l++)
                    {
                        //If two coordinates are not zero, then they dont belong to base case.
                        if((j == 0 && k == 0 && l == 0) || (j == 0 && k == 0) || (j == 0 && l == 0) || (k == 0 && l == 0))
                        {
                            continue;
                        }
                        else
                        {
                            int minimum = 0;
                            if(j > 0 && k > 0 && l > 0)
                            {
                                minimum = Math.min((grid[j][k][l - 1] + A), Math.min((grid[j][k - 1][l] + A), Math.min((grid[j - 1][k][l] + A), Math.min((grid[j][k - 1][l - 1] + B), Math.min((grid[j - 1][k][l - 1] + B), Math.min((grid[j - 1][k - 1][l] + B), (grid[j - 1][k - 1][l - 1] + C)))))));
                            }
                            else if (j == 0)
                            {
                                minimum = Math.min((grid[j][k][l - 1] + A), Math.min((grid[j][k - 1][l] + A), (grid[j][k - 1][l - 1] + B)));
                            }
                            else if (k == 0)
                            {
                                minimum = Math.min((grid[j - 1][k][l] + A), Math.min((grid[j][k][l - 1] + A), (grid[j - 1][k][l - 1] + B)));
                            }
                            else if(l == 0)
                            {
                                minimum = Math.min((grid[j - 1][k][l] + A), Math.min((grid[j][k - 1][l] + A), (grid[j - 1][k - 1][l] + B)));
                            }
                            grid[j][k][l] = minimum;
                        }
                    }
                }
            }
            System.out.println(grid[x][y][z]);
        }
    }
}
