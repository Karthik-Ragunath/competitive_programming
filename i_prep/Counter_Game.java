import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        BigInteger[] input_array=new BigInteger[65];
        input_array[0]=BigInteger.valueOf(1);
        for(int i=1;i<65;i++)
        {
            input_array[i]=input_array[i-1].multiply(BigInteger.valueOf(2));
        }
        //System.out.println(input_array[64]);
        int user;
        for(int i=0;i<testcases;i++)
        {
            BigInteger input=in.nextBigInteger();
            for(user=1;;user++)
            {
                int Low=0;
                int High=64;
                boolean flagship=false;
                while(Low<=High)
                {
                    int Mid=((Low+High)/2);
                    //System.out.println(Mid);
                    if(input_array[Mid].compareTo(input)==0)
                    {
                        flagship=true;
                        break;
                    }
                    if(input_array[Mid].compareTo(input)>0)
                    {
                        High=Mid-1;
                        continue;
                    }
                    if(input_array[Mid].compareTo(input)<0)
                    {
                        Low=Mid+1;
                        continue;
                    }
                }
                if(flagship==false)
                {
                    //System.out.println(High+" "+Low);
                    input=input.subtract(input_array[High]);
                    //System.out.println("falser: "+input);
                }
                else
                {
                    input=input.divide(BigInteger.valueOf(2));
                }
                if(input.compareTo(BigInteger.valueOf(1))==0)
                {
                    break;
                }
            }
            if(user%2==1)
            {
                System.out.println("Louise");
            }
            else
            {
                System.out.println("Richard");
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}