// https://www.hackerrank.com/challenges/castle-on-the-grid/problem
import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;

public class Solution {

    public static void main(String[] args) {
        int gridsize;
        int x1,y1,x2,y2;
        Scanner in=new Scanner(System.in);
        gridsize=in.nextInt();
        String[] input_string=new String[gridsize];
        char[][] input=new char[gridsize][gridsize];
        for(int i=0;i<gridsize;i++)
        {
            input_string[i]=in.next();
        }
        x1=in.nextInt();
        y1=in.nextInt();
        x2=in.nextInt();
        y2=in.nextInt();
        for(int i=0;i<gridsize;i++)
        {
            input[i]=input_string[i].toCharArray();
        }
        /*1D-String to 2D-CharArray conversion
        for(int i=0;i<gridsize;i++)
        {
            for(int j=0;j<gridsize;j++)
            {
                System.out.print(input[i][j]+" ");
            }
            System.out.println();
        }*/
        //ArrayList<Integer>[] vector=(ArrayList<Integer>[])new ArrayList[gridsize*gridsize]; Doesn't work
        //ArrayDeque<Integer>[] vectr=new ArrayDeque[gridsize*gridsize] doesn't allow indexed access of elements though it is faster than ArrayList
	ArrayList<Integer>[] vector=new ArrayList[gridsize*gridsize];
        for(int i=0;i<gridsize*gridsize;i++)
        {
            vector[i]=new ArrayList<Integer>();
        }
        for(int i=0;i<gridsize;i++)
        {
            for(int j=0;j<gridsize;j++)
            {
                if(input[i][j]=='.')
                {
                    int current=i*gridsize+j;
                    for(int k=i-1;k>=0;k--)
                    {
                        if(input[k][j]=='.')
                        {
                            int tobeadded=k*gridsize+j;
                            vector[current].add(tobeadded);
                        }
                        else
                        {
                            break;
                        }
                    }
                    for(int k=i+1;k<gridsize;k++)
                    {
                        if(input[k][j]=='.')
                        {
                            int tobeadded=k*gridsize+j;
                            vector[current].add(tobeadded);
                        }
                        else
                        {
                            break;
                        }
                    }
                    for(int k=j-1;k>=0;k--)
                    {
                        if(input[i][k]=='.')
                        {
                            int tobeadded=i*gridsize+k;
                            vector[current].add(tobeadded);
                        }
                        else
                        {
                            break;
                        }
                    }
                    for(int k=j+1;k<gridsize;k++)
                    {
                        if(input[i][k]=='.')
                        {
                            int tobeadded=i*gridsize+k;
                            vector[current].add(tobeadded);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        int starting_position=x1*gridsize+y1;
        Queue<Integer> breadth_first_search=new ArrayDeque<Integer>();
        breadth_first_search.add(starting_position);
        int[] distance=new int[gridsize*gridsize];
        boolean[] visited=new boolean[gridsize*gridsize];
        visited[starting_position]=true;
        while(!(breadth_first_search.isEmpty()))
        {
            int now=breadth_first_search.poll();
            for(int i=0;i<vector[now].size();i++)
            {
                int next=vector[now].get(i);
                if(!(visited[next]))
                {
                    visited[next]=true;
                    breadth_first_search.add(next);
                    distance[next]=distance[now]+1;
                }
            }
        }
        int ending_position=x2*gridsize+y2;
        System.out.println(distance[ending_position]);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}