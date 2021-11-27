import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
import java.lang.*;

public class Solution {

    public static void main(String[] args) {
        int upperbound=1000000;
        int sievebound=(int)((upperbound-1)/2);
        int uppersqrt=(int)((((int)Math.sqrt(upperbound))-1)/2);
        boolean[] primebits=new boolean[sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=(2*i*(i+1));j<=sievebound;j+=(2*i+1))
                {
                    primebits[j]=false;
                }
            }
        }
        SortedSet<Integer> primeset=new TreeSet<Integer>();
        primeset.add(2);
        for(int i=1;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                primeset.add(2*i+1);
            }
        }
        Integer[] primearray=primeset.toArray(new Integer[primeset.size()]);
        //System.out.println(primearray[primeset.size()-1]);
        int arraysize=primeset.size();
        int[] numberofsteps=new int[1000001];
        numberofsteps[0]=0;
        numberofsteps[1]=1;
        numberofsteps[2]=2;
        numberofsteps[3]=3;
        for(int i=4;i<=1000000;i++)
        {
            if(primeset.contains(i))
            {
                numberofsteps[i]=numberofsteps[i-1]+1;
                continue;
            }
            else
            {
                int minimum=numberofsteps[i-1]+1;
                int squareroot_limiter=(int)Math.sqrt(i);
                for(int j=2;j<=squareroot_limiter;j++)
                {
                    if(i%j==0)
                    {
                        int other_factor=i/j;
                        int temp=numberofsteps[other_factor]+1;
                        if(temp<minimum)
                        {
                            minimum=temp;
                        }
                    }
                }
                numberofsteps[i]=minimum;
            }
        }
        
        Scanner in=new Scanner(System.in);
        int number_of_queries=in.nextInt();
        for(int i=0;i<number_of_queries;i++)
        {
            int query_value=in.nextInt();
            System.out.println(numberofsteps[query_value]);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}