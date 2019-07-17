/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int testcases,rows,columns;
		BigInteger result;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
			//System.out.println(testcases);
		for(int i=0;i<testcases;i++)
		{
			rows=in.nextInt();
			columns=in.nextInt();
			BigInteger[][] grid=new BigInteger[rows+1][columns+1];
			for(int j=0;j<=rows;j++)
			{
				grid[j][columns]=BigInteger.valueOf(1);
					//System.out.println("i am in");
			}
			for(int k=0;k<=columns;k++)
			{
				grid[rows][k]=BigInteger.valueOf(1);
					//System.out.println("i am in");
			}
			for(int m=rows-1;m>=0;m--)
			{
				for(int n=columns-1;n>=0;n--)
				{
					grid[m][n]=grid[m][n+1].add(grid[m+1][n]);
				}
			}
				//System.out.println(grid[0][0]);
			result=(grid[0][0]).mod(BigInteger.valueOf(1000000007));
			System.out.println(result);
		}
		// your code goes here
	}
}