import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        int upperbound=1000000;
        int sievebound=(upperbound-1)/2;
        int uppersqrt=(int)((Math.sqrt(upperbound)-1)/2);
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
        List<Integer> numbers=new ArrayList<Integer>();
        numbers.add(2);
        for(int i=1;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                numbers.add(2*i+1);
            }
        }
        Integer[] number=numbers.toArray(new Integer[numbers.size()]);
        System.out.println(number[numbers.size()-1]);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}