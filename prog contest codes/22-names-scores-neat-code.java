/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int numberofnames,queries,length;
		String queryname;
		int ch;
        Scanner in=new Scanner(System.in);
        numberofnames=in.nextInt();
        String[] names=new String[numberofnames];
        for(int i=0;i<numberofnames;i++)
        {
        	names[i]=in.next();//in.nextLine() to read entire line
        }
        queries=in.nextInt();
        Arrays.sort(names);
        for(int i=0;i<queries;i++)
        {
        	int sum=0;
        	queryname=in.next();
        	length=queryname.length();
        	char[] querryarray=queryname.toCharArray();
        	for(int j=0;j<length;j++)
        	{
        		ch=querryarray[j]-'A';
        		sum=sum+ch+1;
        			
        	}
            for(int j=0;j<numberofnames;j++)
        	{
        		if(queryname.compareTo(names[j])==0)
        		{
        		
        			sum=sum*(j+1);
        			break;
        		}
        	}
        	System.out.println(sum);
        }
        
        
		// your code goes here
	}
}