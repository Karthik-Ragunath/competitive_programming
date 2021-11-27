import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class MaximumNode
{
    int maximum;
}

class Maximum
{
    public static boolean maxOfRowsAndColumns(int[][] matrix, int N, int currentRow, int previousRowMax, MaximumNode maxNode)
    {
        if(currentRow == (N - 1))
        {
            for(int i = N - 1; i >= 0; i--)
            {
                if(matrix[currentRow][i] > previousRowMax)
                {
                    maxNode.maximum = maxNode.maximum + matrix[currentRow][i];
                    return true;
                }
                else
                {
                    return false;
                }
            }
            return false;
        }
        else
        {
            boolean isTheSolutionFound = false;
            for(int i = N - 1; i >= 0; i--)
            {
                if(matrix[currentRow][i] > previousRowMax)
                {
                    maxNode.maximum = maxNode.maximum + matrix[currentRow][i];
                    isTheSolutionFound = maxOfRowsAndColumns(matrix, N, (currentRow + 1), matrix[currentRow][i], maxNode);
                    if(isTheSolutionFound)
                    {
                        return true;
                    }
                    maxNode.maximum = maxNode.maximum - matrix[currentRow][i];
                }
                else
                {
                    return false;
                }
            }
            return false;
        }
    }
    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int testcase = 0; testcase < testcases; testcase++)
        {
            int N;
            N = in.nextInt();
            int[][] matrix = new int[N][N];
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    matrix[i][j] = in.nextInt();
                }
                Arrays.sort(matrix[i]);
            }
            MaximumNode maxNode = new MaximumNode();
            maxNode.maximum = 0;
            boolean isMaxPossible = maxOfRowsAndColumns(matrix, N, 0, 0, maxNode);
            if(isMaxPossible)
            {
                System.out.println(maxNode.maximum);
            }
            else
            {
                System.out.println("-1");
            }
        }
    }
}
