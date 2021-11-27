import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {

        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int k = 0; k < testcases; k++)
        {
            int numberOfTerms = in.nextInt();
            int[] input = new int[numberOfTerms + 1];
            for(int i = 1; i <= numberOfTerms; i++)
            {
                input[i] = in.nextInt();
            }
            int[][] dp = new int[2][numberOfTerms + 1];
            dp[0][1] = 0;
            dp[1][1] = 0;
            int maximumSum = 0;
            for(int i = 2; i <= numberOfTerms; i++)
            {
                dp[0][i] = dp[0][i - 1] + Math.max(Math.abs(input[i] - input[i-1]), Math.abs(input[i] - 1)) ;
                System.out.println(dp[0][i]);
                dp[1][i] = dp[1][i - 1] + Math.max(Math.abs(1 - input[i-1]),Math.abs(1 - 1));
                System.out.println(dp[1][i]);
            }
            int maximum = Math.max(dp[0][numberOfTerms], dp[1][numberOfTerms]);
            System.out.println(maximum);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}
