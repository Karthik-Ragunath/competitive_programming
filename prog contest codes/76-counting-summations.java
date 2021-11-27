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
		int testcases;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int i=0;i<testcases;i++)
		{
			int number;
			number=in.nextInt();
			BigInteger[] solution=new BigInteger[number+1];
			for(int j=1;j<=number;j++)
			{
				solution[j]=BigInteger.valueOf(0);
			}
			solution[0]=BigInteger.valueOf(1);
			for(int k=1;k<number;k++)
			{
				for(int l=k;l<=number;l++)
				{
					solution[l]=solution[l].add(solution[l-k]);
				}
			}
			BigInteger sol,realsolution;
			sol=solution[number];
			realsolution=sol.mod(BigInteger.valueOf(1000000007));
			System.out.println(realsolution);
		}
		// your code goes here
	}
}