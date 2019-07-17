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
		BigInteger[] fibo=new BigInteger[3];
		int[] flagship=new int[5001];
		BigInteger[] count=new BigInteger[5001];
		int noofterms;
		int maxlimit=5000;
		BigInteger j;
		int testcases;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int k=0;k<testcases;k++)
		{
			fibo[0]=BigInteger.valueOf(0);
			fibo[2]=BigInteger.valueOf(1);
			int i=0;
			int n=0;
			j=BigInteger.valueOf(1);
			noofterms=in.nextInt();
			while(n<=noofterms)
			{
				i=((i+1)%3);
				fibo[i]=fibo[(i+1)%3].add(fibo[(i+2)%3]);
				n=String.valueOf(fibo[i]).length();
				if(flagship[n]==0)
				{
					flagship[n]=1;
					count[n]=j;
				}
				j=j.add(BigInteger.valueOf(1));
				if(n==noofterms)
				{
					break;
				}
			}
			
			System.out.println(count[noofterms]);
		}
		
		// your code goes here
	}
}