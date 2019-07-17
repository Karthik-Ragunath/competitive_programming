import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        int upperbound=500000;
        int sievebound=(upperbound-1)/2;
        int uppersqrt=((int)Math.sqrt(upperbound)-1)/2;
        boolean[] primebits=new boolean[sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=(2*i*(i+1));j<=sievebound;j=j+(2*i+1))
                {
                    primebits[j]=false;
                }
            }
        }
        Set<Integer> primeset=new HashSet<Integer>();
        primeset.add(2);
        for(int i=0;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                primeset.add(2*i+1);
            }
        }
        //Integer[] primes=primeset.toArray(new Integer[primeset.size()]);
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            int number,output=0;
            number=in.nextInt();
            int k=1;
            while(true)
            {
                int subtractor=2*(k*k);
                int temporary=number-subtractor;
                if(subtractor>=number-1)
                {
                    break;
                }
                if(primeset.contains(temporary))
                {
                    output++;
                }
                k++;
            }
            System.out.println(output);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}