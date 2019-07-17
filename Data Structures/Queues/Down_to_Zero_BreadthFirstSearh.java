import java.io.*;
import java.lang.*;
import java.util.*;
import java.text.*;
import java.math.*;

class Solution
{
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int queries;
        queries=in.nextInt();
        for(int k=0;k<queries;k++)
        {
            int query_item=in.nextInt();
            int[] distance=new int[query_item+1];
            distance[query_item]=1;
            Queue<Integer> down_to_zero=new ArrayDeque<Integer>();
            down_to_zero.add(query_item);
            while(!down_to_zero.isEmpty())
            {
                int now=down_to_zero.poll();
                if(now!=0)
                {
                    if(distance[now-1]==0)
                    {
                        distance[now-1]=distance[now]+1;
                        down_to_zero.add(now-1);
                        //int temp=now-1;
                        //System.out.println("Element: "+temp+" distance: "+distance[now-1]);
                    }
                }
                int loop_limiter=(int)Math.sqrt(now);
                for(int i=2;i<=loop_limiter;i++)
                {
                    if(now%i==0)
                    {
                        int element_to_be_added=now/i;
                        if(distance[element_to_be_added]==0)
                        {
                            distance[element_to_be_added]=distance[now]+1;
                            //System.out.println("Element: "+element_to_be_added+" distance: "+distance[element_to_be_added]);
                            down_to_zero.add(element_to_be_added);
                        }
                    }
                }
            }
            System.out.println(distance[0]-1);
            /*-1 is done because initially we take nth distance as 1 inorder to separate it remaining (non-traversed) integers*/
        }
    }
}