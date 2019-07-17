import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int l=0;l<testcases;l++)
        {
            int numberofnodes;
            int numberofconnections;
            numberofnodes=in.nextInt();
            int copy_numberofnodes=numberofnodes;
            numberofconnections=in.nextInt();
            int[][] weights=new int[numberofnodes+1][numberofnodes+1];
            int[] distance=new int[numberofnodes+1];
            boolean[] nodechecker=new boolean[numberofnodes+1];
            Arrays.fill(nodechecker,true);
            boolean[][] connections=new boolean[numberofnodes+1][numberofnodes+1];
            boolean[] flagship1=new boolean[numberofnodes+1];
            for(int i=0;i<numberofconnections;i++)
            {
                int temp1;
                int temp2;
                temp1=in.nextInt();
                temp2=in.nextInt();
                flagship1[temp1]=true;
                flagship1[temp2]=true;
                connections[temp1][temp2]=true;
                weights[temp1][temp2]=6;
            }
            for(int i=1;i<=numberofnodes;i++)
            {
                if(flagship1[i]==false)
                {
                    copy_numberofnodes-=1;
                }
            }
            int source;
            source=in.nextInt();
            for(int i=1;i<=numberofnodes;i++)
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
            int flagship=1;
            int knownvertices=0;
            for(int i=currentdistance;;i++)
            {
                //System.out.println("Debugger");
                for(int j=1;j<=numberofnodes;j++)
                {
                    if(distance[j]==i)
                    {
                        if(nodechecker[j]==true)
                        {
                            nodechecker[j]=false;
                            knownvertices=knownvertices+1;
                            //System.out.println(knownvertices);
                            if(knownvertices==copy_numberofnodes)
                            {
                                flagship=0;
                                break;
                            }
                            for(int k=1;k<=numberofnodes;k++)
                            {
                                if(connections[j][k]==true)
                                {
                                    if(distance[k]==-1)
                                    {
                                        distance[k]=weights[j][k];
                                    }
                                    else
                                    {
                                        int temp;
                                        temp=distance[j]+weights[j][k];
                                        if(temp<distance[k])
                                        {
                                            distance[k]=temp;
                                        }
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
                if(flagship==0)
                {
                    break;
                }
            }
            for(int i=1;i<=numberofnodes;i++)
            {
                if(i==source)
                {
                    continue;
                }
                System.out.print(distance[i]+" ");
            }
            System.out.println();
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}