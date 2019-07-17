/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

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
			BigInteger number;
			number=in.nextBigInteger();
		}
		// your code goes here
	}
	void compute(BigInteger number1)
	{
		String str=number1.toString();
		length=str.length();
		String[] digits={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
		String[] tens={"NULL","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
		String[] teens={"NULL","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
		
	}
}