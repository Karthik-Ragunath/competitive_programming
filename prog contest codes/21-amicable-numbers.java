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
		int testcases,sum;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int j=0;j<testcases;j++)
		{
			int number,intermediate;
			sum=0;
			int squareroot;
			number=in.nextInt();
			int[] amicable=new int[number+1];
			for(int k=1;k<=number;k++)
			{
				
				squareroot=(int)Math.sqrt(k);
					//System.out.println(squareroot);
				if(squareroot<=1)
				{
						//System.out.println("i am here");
					amicable[k]=1;
				}
				else
				{
						//System.out.println("hi");
					amicable[k]=1;
					for(int i=2;i<=squareroot;i++)
					{
							//System.out.println("hi");
						if(i<squareroot)
						{
								//System.out.println("i am also here");
							if(k%i==0)
							{
								amicable[k]=amicable[k]+i;
								intermediate=k/i;
								amicable[k]=amicable[k]+intermediate;
							}
						}
						else if(i==squareroot)
						{
							if(k%i==0)
							{
									//System.out.println("i am here too");
								amicable[k]=amicable[k]+i;	
							}
						}
					}
				}
				
			}
			for(int jo=2;jo<=number;jo++)
			{
					//System.out.println("hi");
				int kar,jos;
				kar=amicable[jo];
				if(kar>300)
				{
					continue;
				}
				jos=amicable[kar];
				if((jos==jo)&&(kar!=jo)&&kar!=1)
				{
					sum=sum+jo;
					//System.out.println(jo);
					//System.out.println(sum);
				}
			}
			System.out.println(sum);
			/*System.out.println(amicable[220]);
			System.out.println(amicable[284]);
			System.out.println(amicable[300]);*/
		}
		// your code goes here
	}
}