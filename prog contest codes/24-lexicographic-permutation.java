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
		int[] permutations=new int[]{0,1,2,3,4,5,6,7,8,9,10,11,12};
		char[] perms=new char[15];
		char character;
		int temp;
        int i;
		long numberofpermutations=6227020800L;
		long count;
		int testcases;
		Scanner in=new Scanner(System.in);
		testcases=in.nextInt();
		for(int k=0;k<testcases;k++)
		{
			numberofpermutations=in.nextLong();
			count=numberofpermutations-1;
			if(numberofpermutations==1)
			{
				System.out.println("abcdefghijklm");
			}
			else
			{
				while(count<numberofpermutations)
				{
					int n=13;
					i=n-1;
					while(permutations[i-1]>=permutations[i])
					{
						i=i-1;
					}
					int j=n;
					while(permutations[j-1]<=permutations[i-1])
					{
						j=j-1;
					}
					temp=permutations[j-1];
					permutations[j-1]=permutations[i-1];
					permutations[i-1]=temp;
					i=i+1;
					j=n;
					while(i<j)
					{
						temp=permutations[i-1];
						permutations[i-1]=permutations[j-1];
						permutations[j-1]=temp;
						i=i+1;
						j=j-1;
					}
					count=count+1;
				}
				for(i=0;i<13;i++)
				{
                    int temporary;
                    temporary=permutations[i];
					character=(char)('a'+temporary);
					//perms[i]=character;
                    System.out.print(character);
				}
				/*String solution=String.valueOf(perms);
				System.out.println(solution);*/
                System.out.print("\n");
    
            }    
		}
		// your code goes here
	}
}