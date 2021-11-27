/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    int source;
	    System.out.println("Enter the source:");
	    Scanner in=new Scanner(System.in);
	    source=in.nextInt();
	    System.out.println("Enter the number of nodes: ");
	    int numberofnodes=in.nextInt();
	    boolean[] nodes=new boolean[numberofnodes+1];
	    int numberofconnections=in.nextInt();
	    boolean[][] nodeconnections=new boolean[numberofnodes+1][numberofnodes+1];
	    System.out.println("Enter the node connections:");
	    for(int i=0;i<numberofconnections;i++)
	    {
	        int temp1,temp2;
	        temp1=in.nextInt();
	        temp2=in.nextInt();
	        nodeconnections[temp1][temp2]=true;
	    }
	    int[] distance=new int[numberofconnections+1];
	    for(int i=1;i<=numberofconnections;i++)
	    {
	        if(i==source)
	        {
	            distance[i]=0;
	        }
	        else
	        {
	            distance[i]=-1;
	        }
	    }
	    int currentdistance=0;
	    int knownvertices=0;
        int flagship=1;
	    for(int i=currentdistance;;i++)
	    {
                System.out.println("debugger");
	        for(int j=1;j<=numberofnodes;j++)
	        {
	            if(distance[j]==i)
	            {
                            System.out.println("The present node is "+j);
	                nodes[j]=true;
                    knownvertices=knownvertices+1;
                    if(knownvertices==numberofnodes)
                    {
                       flagship=0;
                       break;
                    }
	                for(int k=1;k<=numberofnodes;k++)
	                {
	                    if(nodeconnections[j][k]==true)
	                    {
	                        if(nodes[k]==false)
	                        {
                                int temp=distance[j]+1;
                                if(distance[k]==-1)
                                {
                                    distance[k]=distance[j]+1;
                                }
                                    System.out.println("Distance of node "+k+" is "+distance[k]); 
                            }
	                    }
	                }
	            }
	        }
            if(flagship==0)
            {
                break;
            }
	    }
        for(int i=1;i<=numberofnodes;i++)
        {
            System.out.println("The Distance from source of node "+i+" "+distance[i]);
        }
		// your code goes here
	}
}
