/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		
		long cache[];/*long arrays are possible but arrayss are int indexed and having number of elements greater than integer size is not possible*/
		cache=new long[5000000];
		
		for(int i=0;i<5000000;i++)
		{
			cache[i]=-1l;
		}
		cache[1]=1l;
		System.out.println(cache[4999888]);
		
		// your code goes here
	}
}