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
		int x[]=new int[100];
		int y[]=new int[100];
		int z[]=new int[100];
		System.out.println("enter the number of terms : ");
		Scanner in=new Scanner(System.in);
		length=in.nextInt();
		
		for(i=0;i<length;i++)
		{
		x[i]=in.nextInt();
		y[i]=in.nextInt();
		z[i]=x[i]+y[i];
		System.out.println("the addition of two numbers results in :"+z[i]);
		}
		Arrays.sort(x);
		for(i=0;i<length;i++)
		{
			System.out.println("the sorted array of numbers is :"+x[i]);	
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