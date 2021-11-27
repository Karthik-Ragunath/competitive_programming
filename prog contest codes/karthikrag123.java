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
		String[] digits={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
		String[] tens={"NULL","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
		String[] teens={"NULL","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
		String[] hundreds={"NULL","One Hundred","Two Hundred","Three Hundred","Four Hundred","Five Hundred","Six Hunderd","Seven Hundred","Eight Hunderd","Nine Hunderd"};
		int testcases;
		int length1;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int i=0;i<testcases;i++)
		{
			BigInteger number;
			BigInteger div,modu;
			int j=0;
			number=in.nextBigInteger();
			String str=number.toString();
			length1=str.length();
			div=(BigInteger.valueOf(length1)).divide(BigInteger.valueOf(3));
			modu=(BigInteger.valueOf(length1)).mod(BigInteger.valueOf(3));
			String[] parts=new String[div+2];
				//System.out.println(div);
				//System.out.println(modu);
			while(str.length()>0)
			{
				if(str.length()>3)
				{
					parts[j]=str.substring(0,3);
					str=str.substring(3,str.length());
					j++
				}
				else
				{
					parts[j]=str.substring(0,mod);
					break;
				}
			}
			
			
		}
		// your code goes here
	}
	
}