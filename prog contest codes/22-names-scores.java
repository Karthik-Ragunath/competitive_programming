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
		//String lexicographicstring;
		int ch;//char character;
		//int charactercounter=new int[26];
        Scanner in=new Scanner(System.in);
        numberofnames=in.nextInt();
        String[] names=new String[numberofnames];
        for(int i=0;i<numberofnames;i++)
        {
        	names[i]=in.next();
        }
        queries=in.nextInt();
        Arrays.sort(names);
        for(int i=0;i<queries;i++)
        {
        	int sum=0;
        	queryname=in.next();
        	length=queryname.length();
        	//int k=0;
        	char[] querryarray=queryname.toCharArray();
        	//char[] lexicographicarray=new char[length];
        	for(int j=0;j<length;j++)
        	{
        		ch=querryarray[j]-'A';
        		sum=sum+ch+1;
        			//System.out.println(sum);
        		//charactercounter[ch]++;
        	}
        	/*for(int j=0;j<26;j++)
        	{
        		character='A'+j;
        		while(charactercounter[j]>=1)
        		{
        			lxicographicarray[k]=character;
        			k++;
        			charactercounter[i]=characetercounter[i]-1;
        		}
        	}
        	lexicographicarray[k]='\0';
        	lexicographicstring=lexicographicarray.toString();*/
        	for(int j=0;j<numberofnames;j++)
        	{
        		if(queryname.compareTo(names[j])==0)
        		{
        				//System.out.println(j);
        			sum=sum*(j+1);
        			break;
        		}
        	}
        	System.out.println(sum);
        }
        
        
		// your code goes here
	}
}