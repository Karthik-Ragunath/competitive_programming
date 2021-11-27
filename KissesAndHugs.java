import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;

class KissesAndHugs
{
    public static long power(long base, long exponent, long modulas)
    {
        long answer = 1L;
        while(exponent > 0)
        {
            if(exponent % 2 == 1)
            {
                answer = (answer * base) % modulas;
            }
            base = (base * base) % modulas;
            exponent = exponent / 2;
        }
        return answer % modulas;
    }
    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        int base = 2;
        long modulas = 1000000007L;
        for(int i = 0; i < testcases; i++)
        {
            long value = in.nextLong();
            long answer;
            if (value % 2 == 1)
            {
                long power = (value + 3) / 2;
                answer = power(base, power, modulas);
                answer = answer - 2;
            }
            else
            {
                long power = value / 2;
                answer = power(base, power, modulas);
                answer = (answer * 3) - 2;
            }
            System.out.println(answer);
        }
    }
}
