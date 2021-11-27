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
			String ans="";
			int div1,mod1,convert,duplicate,m,n;
			int[] tester=new int[3];
			int j=0;
			number=in.nextBigInteger();
			String str=number.toString();
			length1=str.length();
			div=(BigInteger.valueOf(length1)).divide(BigInteger.valueOf(3));
			modu=(BigInteger.valueOf(length1)).mod(BigInteger.valueOf(3));
			div1=div.intValue();//coverts BigInteger into integer
			mod1=modu.intValue();
			String[] parts=new String[div1+2];
			int divisor=3;
				//System.out.println(div);
				//System.out.println(modu);
			while(str.length()>0)
			{
				if(str.length()>3)
				{
					parts[j]=str.substring(str.length()-divisor,str.length());
					str=str.substring(0,str.length()-divisor);
					j++;
				}
				else if(str.length()==3)
				{
					parts[j]=str.substring(str.length()-divisor,str.length());
					str=str.substring(0,str.length()-divisor);
					break;
				}
				else
				{
					parts[j]=str.substring(0,mod1);
					break;
				}
				
				/*	if(str.length()>3)
					{
						parts[j]=str.substring(0,divisor);
						str=str.substring(divisor,str.length());
						j++;
					}
					else
					{
						parts[j]=str.substring(0,mod1);
						break;
					}	*///to split the string from the front
			}
				for(int k=0;k<=j;k++)
				{
					System.out.println(parts[k]);
				}
			for(int l=0;l<=j;l++)
			{
				convert=Integer.valueOf(parts[l]);
				duplicate=convert;
					//System.out.println(convert);
				switch(l)
				{
					case 0:
						m=0;
						n=0;
						while(duplicate>0)
						{
							tester[m]=duplicate%10;
							duplicate=duplicate/10;
							m++;
						}
						while(m!=0)
						{
							m=m-1;
							if(m==2)
							{
								if((tester[m-1]==0)&&(tester[m-2]==0))
								{
									ans=hundreds[tester[m]];
									break;
								}
								else
								{
									ans=hundreds[tester[m]];
									n++;
								}
							}
							else if(m==1)
							{
								if(n==0)
								{
									if(tester[m-1]==0)
									{
										ans=tens[tester[m]];
										break;
									}
									else
									{
										if(tester[m]==1)
										{
											ans=teens[tester[m-1]];
											break;
										}
										else
										{
											ans=tens[tester[m]];
											n++;
										}
									}
								}
								else if(n!=0)
								{
									if(tester[m]==0)
									{
										n++;
										continue;
									}
									else 
									{
										if(tester[m-1]==0)
										{
											ans=ans+" "+tens[tester[m]];
											break;
										}
										else
										{
											if(tester[m]==1)
											{
												ans=ans+" "+teens[tester[m-1]];
												break;
											}
											else
											{
												ans=ans+" "+tens[tester[m]];
												n++;
											}
										}
									}
								}
							}
							if(m==0)
							{
								if(n==0)
								{
									ans=digits[tester[m]];
								}
								else
								{
									if(tester[m]==0)
									{
										continue;
									}
									else
									{
										ans=ans+" "+digits[tester[m]];
									}
								}
							}
						}
				}
			}
			System.out.println(ans);
			
			
		}
		// your code goes here
	}
	
}