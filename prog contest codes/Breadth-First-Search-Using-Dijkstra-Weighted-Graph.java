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
            numberofconnections=in.nextInt();
            int[][] weights=new int[numberofnodes+1][numberofnodes+1];
            int[] distance=new int[numberofnodes+1];
            boolean[][] connections=new boolean[numberofnodes+1][numberofnodes+1];
            for(int i=0;i<numberofconnections;i++)
            {
                int temp1;
                int temp2;
                temp1=in.nextInt();
                temp2=in.nextInt();
                connections[temp1][temp2]=true;
                weights[temp1][temp2]=6;
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
            int connectionchecker=0;
            for(int i=currentdistance;;i++)
            {
                for(int j=1;j<=numberofnodes;j++)
                {
                    if(distance[j]==i)
                    {
                        for(int k=1;k<=numberofnodes;k++)
                        {
                            if(connections[j][k]==true)
                            {
                                connectionchecker=connectionchecker+1;
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
                                if(connectionchecker==numberofconnections)
                                {
                                    flagship=0;
                                    break;
                                }
                            }
                        }
                        if(flagship==0)
                        {
                            break;
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