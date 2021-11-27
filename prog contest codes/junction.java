import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;
public class Solution {
    public static void main(String[] args) {
        int source,destination;
        Scanner in=new Scanner(System.in);
        source=in.nextInt();
        destination=in.nextInt();
        int junctions,roads;
        junctions=in.nextInt();
        roads=in.nextInt();
        int[] junctiontimings=new int[junctions+1];
        for(int i=1;i<=junctions;i++)
        {
            int temp;
            temp=in.nextInt();
            junctiontimings[i]=temp;
        }
        boolean[][] roadsetter=new boolean[roads+1][roads+1];
        int[][] roadvalues=new int[roads+1][roads+1];
        for(int i=1;i<=roads;i++)
        {
            int temp1,temp2,temp3;
            temp1=in.nextInt();
            temp2=in.nextInt();
            temp3=in.nextInt();
            roadvalues[temp1][temp2]=temp3;
            roadsetter[temp1][temp2]=true;
        }
        int shortest=0;
        for(int i=source;;)
        {
            int time=0;
            for(int j=1;j<=junctions;j++)
            {
                if(j==source)
                {
                    continue;
                }
                if(j==destination)
                {
                    
                }
                else
                {
                    if(roadsetter[source][j]==true)
                    {
                        time=roadvalues[source][j];
                    }
                }
            }
        }
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}