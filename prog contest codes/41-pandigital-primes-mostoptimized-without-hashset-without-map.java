import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        int upperbound=7652413;
        int sievebound=(upperbound-1)/2;
        int uppersqrt=((int)Math.sqrt(upperbound)-1)/2;
        boolean[] primebits=new boolean[(int)sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=2*i*(i+1);j<=sievebound;j+=(2*i+1))
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
        int solutions=-1;
        int[] realsolution=new int[7652414];
        for(int i=10;i<=7652413;i++)
        {
            String s1=String.valueOf(i);
            int length1=s1.length();
            int duplicatenumber=Integer.parseInt(s1);
            boolean[] distinctterms=new boolean[length1+1];
            Arrays.fill(distinctterms,true);
            int flag=1;
            while(duplicatenumber>0)
            {
                int temp=duplicatenumber%10;
                if(temp>length1)
                {
                    flag=0;
                    break;
                }
                distinctterms[temp]=false;
                duplicatenumber=duplicatenumber/10;
            }
            if(flag==0)
            {
                realsolution[i]=solutions;
                continue;
            }
            int flagship=1;
            for(int j=1;j<=length1;j++)
            {
                if(distinctterms[j]==true)
                {
                    flagship=0;
                    break;
                }
            }
            if(flagship==1)
            {
                if(primeset.contains(i))
                {
                    if(i>solutions)
                    {
                        solutions=i;
                    }
                }
            }
            realsolution[i]=solutions;
        }
        Scanner in=new Scanner(System.in);
        int testcases;
        testcases=in.nextInt();
        for(int k=0;k<testcases;k++)
        {
            long number;
            number=in.nextLong();
            if(number>7652413L)
            {
                System.out.println("7652413");
                continue;
            }
            int integernumber=(int)number;
            System.out.println(realsolution[integernumber]);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}