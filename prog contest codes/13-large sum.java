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
		BigInteger j,nooflines,input,sum;
		Scanner in=new Scanner(System.in);
		nooflines=in.nextBigInteger();
		sum=BigInteger.valueOf(0);
		for(j=BigInteger.valueOf(0);j.compareTo(nooflines)<0;j=j.add(BigInteger.ONE))
		{
			input=in.nextBigInteger();
			sum=sum.add(input);
		}
		String str=sum.toString();
		String str1=str.substring(0,10);
		System.out.println(str1);
		// your code goes here
	}
}