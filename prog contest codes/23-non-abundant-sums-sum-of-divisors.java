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
		int squareroot,n,number=0,duplicate,duplicate1,flagship,i;
		int[] prime=new int[10000];
		int[] abundant=new int[30000];
		squareroot=(int)Math.sqrt(28123);
		prime[0]=2;
		n=0;
		number=0;
                    //System.out.println("hi");
		for(i=3;i<=28123;i++)
		{
			duplicate=n;
			duplicate1=duplicate+1;
			flagship=1;
			while(duplicate1!=0)
			{
				duplicate1=duplicate1-1;
				if(i%prime[duplicate]==0)
				{
					flagship=0;
					break;
				}
				duplicate--;
			}
			if(flagship==1)
			{
				n++;
				prime[n]=i;
			}
		}
                /*System.out.println(prime[0]);
                System.out.println(prime[1]);
                System.out.println(prime[2]);
                System.out.println(prime[3]);
                System.out.println(n);
                System.out.println(prime[n]);*/
                
		for(int m=4;m<=28123;m++)
		{
			int num=m;
			int sum=1;
			int p=prime[0];
			int j;
			i=0;
			int realsum=0;
			while(p*p<=num && (num>1))
			{
				p=prime[i];
				i++;
				if(num%p==0)
				{
					j=p*p;
					num=num/p;
					while(num%p==0)
					{
						j=j*p;
						num=num/p;
					}
					sum=(sum*(j-1))/(p-1);
				}
			}
			if(num>1)
			{
				sum*=num+1;
			}
			realsum=sum-m;
			if(realsum>m)
			{
				abundant[number]=m;
				number++;
				
			}
			
		}
		             // System.out.println(abundant[61]);
		int testcases;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int k=0;k<testcases;k++)
		{
			int input;
			input=in.nextInt();
            if(input>28123)
            {
                System.out.println("YES");
                continue;
            }
			int flagship1=0;
			for(int jo=0;abundant[jo]<input;jo++)
			{
				for(int kar=jo;abundant[kar]<input;kar++)
				{
					if(abundant[jo]+abundant[kar]==input)
					{
						flagship1=1;
						break;
					}
				}
				if(flagship1==1)
				{
					break;
				}
			}
			if(flagship1==1)
			{
				System.out.println("YES");
			}
			else
			{
				System.out.println("NO");
			}
		}
		// your code goes here
	}
}