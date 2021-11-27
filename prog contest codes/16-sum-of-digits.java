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
		int number;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int i=0;i<testcases;i++)
		{
			number=in.nextInt();
			BigInteger num,num1,sum;
			sum=BigInteger.valueOf(0);
			num1=BigInteger.valueOf(2);
			num=num1.pow(number);//pow(biginteger) wont work
				//System.out.println(num);
			while(num.compareTo(BigInteger.valueOf(0))>0)
			{
				sum=sum.add(num.mod(BigInteger.valueOf(10)));
				num=num.divide(BigInteger.valueOf(10));
			}
			System.out.println(sum);
		}
		
		// your code goes here
	}
}