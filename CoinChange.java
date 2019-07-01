import java.io.*;
import java.util.*;
import java.math.*;

class CoinChange
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int target = in.nextInt();
        int numberOfCoins = in.nextInt();
        int[] coinValue = new int[numberOfCoins];
        long[][] coinSolutions = new long[numberOfCoins][target + 1];
        for(int i = 0; i < numberOfCoins; i++)
        {
            coinValue[i] = in.nextInt();
            coinSolutions[i][0] = 1;
        }
        for(int i = 0; i < numberOfCoins; i++)
        {
            for(int j = 1; j <= target; j ++)
            {
                if (i == 0)
                {
                    if(coinValue[i] > j)
                    {
                        coinSolutions[i][j] = 0;
                    }
                    else
                    {
                        coinSolutions[i][j] = coinSolutions[i][j - coinValue[i]];
                    }
                }
                else
                {
                    if(coinValue[i] > j)
                    {
                        coinSolutions[i][j] = coinSolutions[i - 1][j];
                    }
                    else
                    {
                        coinSolutions[i][j] = coinSolutions[i - 1][j] + coinSolutions[i][j - coinValue[i]];
                    }
                }
            }
        }
        System.out.println(coinSolutions[numberOfCoins - 1][target]);
    }
}
