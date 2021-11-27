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
		int testcases,number,numberofterms,numberoflines,sum1,sum2;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int k=0;k<testcases;k++)
		{
			numberoflines=in.nextInt();
			numberofterms=(numberoflines*(numberoflines+1))/2;
			int[][] inputterms=new int[numberofterms+1][numberofterms+1];
			for(int i=1;i<=numberoflines;i++)
			{
				for(int j=1;j<=numberoflines;j++)
				{
					inputterms[i][j]=0;
				}
			}
			for(int i=1;i<=numberoflines;i++)
			{
				for(int j=1;j<=i;j++)
				{
					inputterms[i][j]=in.nextInt();
				}
			}
			//int[][] duplicate=inputterms.clone()-creates a duplicate array;
				//System.out.println(duplicate[2][1]);
			for(int i=numberoflines-1;i>=1;i--)
			{
				for(int j=1;j<=i;j++)
				{
					sum1=inputterms[i+1][j]+inputterms[i][j];
					sum2=inputterms[i+1][j+1]+inputterms[i][j];
					if(sum1>=sum2)
					{
						inputterms[i][j]=sum1;
					}
					else
					{
						inputterms[i][j]=sum2;
					}
				}
			}
			System.out.println(inputterms[1][1]);
				
		}
		// your code goes here
	}
}