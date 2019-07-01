import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class TeamFormation
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] emptyVariables = new int[m*2];
            for(int j = 1; j <= 2 * m; j++)
            {
                emptyVariables[j - 1] = in.nextInt();
            }
            if(n % 2 == 0)
            {
                System.out.println("Yes");
            }
            else
            {
                System.out.println("No");
            }
        }
    }
}
