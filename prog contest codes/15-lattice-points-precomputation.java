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
		int testcases,rows,columns,rows1,columns1;
		BigInteger[][] grid1=new BigInteger[501][501];
		for(rows=1;rows<=100;rows++)
		{
			for(columns=1;columns<=100;columns++)
			{
				BigInteger[][] grid=new BigInteger[rows+1][columns+1];
				for(int j=0;j<=rows;j++)
				{
					grid[j][columns]=BigInteger.valueOf(1);
				}
				for(int k=0;k<=columns;k++)
				{
					grid[rows][k]=BigInteger.valueOf(1);
				}
				for(int m=rows-1;m>=0;m--)
				{
					for(int n=columns-1;n>=0;n--)
					{
						grid[m][n]=grid[m][n+1].add(grid[m+1][n]);
					}
				}
				grid1[rows][columns]=(grid[0][0]).mod(BigInteger.valueOf(1000000009));
			}
		}
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int l=0;l<testcases;l++)
		{
			rows1=in.nextInt();
			columns1=in.nextInt();
			System.out.println(grid1[rows1][columns1]);
			
		}
		// your code goes here
	}
}