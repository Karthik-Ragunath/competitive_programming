/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		SortedSet<Integer> distinctterms=new TreeSet<Integer>();
		String s4="237666";
		int duplicatenumber=Integer.parseInt(s4);
		while(duplicatenumber>0)
     		{
        		int temp=duplicatenumber%10;
            		distinctterms.add(temp);
           		duplicatenumber=duplicatenumber/10;
        	}
        	Iterator loopy=distinctterms.iterator();
        	while(loopy.hasNext())
        	{
        		System.out.println(loopy.next());
        	}
		// your code goes here
	}
}