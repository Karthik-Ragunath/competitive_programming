import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            long number;
            number=in.nextLong();
            double output;
            output=(double)((((double)Math.sqrt(1+8*number))-1)/2);
            if(output==Math.floor(output))
            {
                long outputnumber=(long)output;
                System.out.println(outputnumber);
            }
            else
            {
                System.out.println("-1");
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}