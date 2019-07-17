import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            long number1,diagonal=9;
            BigInteger number;
            number=in.nextBigInteger();
            number=number.mod(BigInteger.valueOf(1000000007));
            number1=number.longValue();
            number1=number1/2;
            diagonal=((8*(number1)*(number1+1)*(2*number1+1))/3)%(1000000007);
            diagonal=(diagonal+(2*(number1)*(number1+1)))%(1000000007);
            diagonal=(diagonal+(4*number1))%(1000000007);
            diagonal=(diagonal+1)%(1000000007);
            System.out.println(diagonal);
            
        }
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}