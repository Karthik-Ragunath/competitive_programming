/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int i,length;
		
		System.out.println("enter the number of terms : ");
		Scanner in=new Scanner(System.in);
		length=in.nextInt();
		int x[]=new int[length];
		int y[]=new int[length];
		int z[]=new int[length];
		
		for(i=0;i<length;i++)
		{
		x[i]=in.nextInt();
		y[i]=in.nextInt();
		z[i]=x[i]+y[i];
		System.out.println("the addition of two numbers results in :"+z[i]);
		}
		Arrays.sort(x);
		for(int huge:x)
		{
			System.out.println(huge);	
		}
		int arr[]={78,988,45,67,53,89,65,34,23};
		Arrays.sort(arr);
		for(int number:arr)
		{
			System.out.println(number);	
		}
		
		// your code goes here
	}
}