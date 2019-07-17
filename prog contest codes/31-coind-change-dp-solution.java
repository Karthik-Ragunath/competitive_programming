import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        int[] coins=new int[8];
        coins[0]=1;
        coins[1]=2;
        coins[2]=5;
        coins[3]=10;
        coins[4]=20;
        coins[5]=50;
        coins[6]=100;
        coins[7]=200;
        long[] targets=new long[100001];
        int totalamount=100000;
        BigInteger realsolution;
        BigInteger[] ways=new BigInteger[totalamount+1];
        for(int i=0;i<=totalamount;i++)
        {
            ways[i]=BigInteger.valueOf(0);
        }
        ways[0]=BigInteger.valueOf(1);
        for(int i=0;i<8;i++)
        {
            for(int j=coins[i];j<=totalamount;j++)
            {
                ways[j]=ways[j].add(ways[j-coins[i]]);
            }
        }
        for(int k=0;k<testcases;k++)
        {
            int target;
            target=in.nextInt();
            realsolution=ways[target].mod(BigInteger.valueOf(1000000007));
            System.out.println(realsolution);
        }
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}