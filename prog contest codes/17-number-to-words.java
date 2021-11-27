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
			String ans0="";
			String ans1="";
			String ans2="";
			String ans3="";
			String ans4="";
			String ans5="";
			String realanswer="";
			int div1,mod1,convert,duplicate,m,n;
			int[] tester=new int[3];
			int j=0;
			number=in.nextBigInteger();
			if(number.compareTo(BigInteger.valueOf(0))==0)
			{
				System.out.println("Zero");
				continue;
			}
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
				/*for(int k=0;k<=j;k++)
				{
					System.out.println(parts[k]);
				}*/
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
						ans0=ans;
						if(!ans0.equals(""))
						{
							realanswer=ans0;
						}
							
					case 1:
						m=0;
						n=0;
						ans="";
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
						ans1=ans;
						if(!ans1.equals(""))
						{
							if(!realanswer.equals(""))
							{
								realanswer=ans1+" Thousand "+realanswer;
							}
							else
							{
								realanswer=ans1+" Thousand ";
							}
						}
					case 2:
						m=0;
						n=0;
						ans="";
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
						ans2=ans;
						if(!ans2.equals(""))
						{
							if(!realanswer.equals(""))
							{
								realanswer=ans2+" Million "+realanswer;
							}
							else
							{
								realanswer=ans2+" Million ";
							}
						}
					case 3:
						m=0;
						n=0;
						ans="";
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
						ans3=ans;
						if(!ans3.equals(""))
						{
							if(!realanswer.equals(""))
							{
								realanswer=ans3+" Billion "+realanswer;
							}
							else
							{
								realanswer=ans3+" Billion ";
							}
						}
					case 4:
						m=0;
						n=0;
						ans="";
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
						ans4=ans;
						if(!ans4.equals(""))
						{
							if(!realanswer.equals(""))
							{
								realanswer=ans4+" Trillion "+realanswer;
							}
							else
							{
								realanswer=ans4+" Trillion ";
							}
						}
					case 5:
						m=0;
						n=0;
						ans="";
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
						ans5=ans;
						if(!ans5.equals(""))
						{
							if(!realanswer.equals(""))
							{
								realanswer=ans5+" Zillion "+realanswer;
							}
							else
							{
								realanswer=ans5+" Zillion ";
							}
						}
				}
			}
			System.out.println(realanswer);
			
			
		}
		// your code goes here
	}
	
}