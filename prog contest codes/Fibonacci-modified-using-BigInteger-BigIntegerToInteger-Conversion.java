import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;

public class Solution {

    public static void main(String[] args) {
        BigInteger[] fibo=new BigInteger[30];
        Scanner in=new Scanner(System.in);
        BigInteger a,b,n;
        BigInteger solution;
        solution=BigInteger.valueOf(0);
        a=in.nextBigInteger();
        b=in.nextBigInteger();
        n=in.nextBigInteger();
        fibo[0]=a;
        fibo[1]=b;
        int temp;
        if(n.compareTo(BigInteger.valueOf(2))<0)
        {
            temp=n.intValue();
            System.out.println(fibo[temp-1]);
        }
        else
        {
            for(int i=2;BigInteger.valueOf(i).compareTo(n)<0;i++)
            {
                fibo[i]=fibo[i-1].pow(2).add(fibo[i-2]);
                solution=fibo[i];
            }
            System.out.println(solution);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}