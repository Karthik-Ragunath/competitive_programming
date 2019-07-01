import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class TotalDiamonds
{
    public static long[] dynmaicSolution(int length)
    {
        long[] dp = new long[length + 1];
        for(int i = 1; i <= length; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(i == j)
                {
                    dp[i] += (long)(i * 2);
                }
                else
                {
                    dp[i] += (long)((i + j) * 2);
                }
            }
            dp[i] = dp[i] + dp[i - 1];
        }
        return dp;
    }

    public static void main(String[] args)
    {
        int testcases;
        long[] dp = dynmaicSolution(1000000);
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int gridSize = in.nextInt();
            System.out.println(dp[gridSize]);
        }
    }
}
