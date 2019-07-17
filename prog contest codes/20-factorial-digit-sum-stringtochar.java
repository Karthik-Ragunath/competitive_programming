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
		int testcases,inputnumber,length1,sum;
		BigInteger solution;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int a=0;a<testcases;a++)
		{
			sum=0;
			solution=BigInteger.valueOf(1);
			inputnumber=in.nextInt();
			if(inputnumber==0)
			{
				System.out.println("1");
				continue;
			}
			for(int i=1;i<=inputnumber;i++)
			{
				solution=solution.multiply(BigInteger.valueOf(i));
			}
			String str1=solution.toString();
			length1=str1.length();
			char[] chararray=str1.toCharArray();
			for(int j=0;j<length1;j++)
			{
				sum=sum+chararray[j]-'0';
			}
			System.out.println(sum);
		}
		// your code goes here
	}
}