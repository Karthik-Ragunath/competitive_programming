import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        long[] catchy=new long[5000001];
        long maxvaluekey=0;
        long solution=0;
        for(int i=12;i<=(5*1000);i++)
        {
            long numberofsolutions=0;
            for(int a=2;a<(i/3);a++)
            {
                long value1=(long)(i*(i-2*a));
                long value2=(long)(2*(-a));
                if(value1%value2==0)
                {
                    numberofsolutions++;
                }
            }
            if(numberofsolutions>maxvaluekey)
            {
                maxvaluekey=numberofsolutions;
                solution=(long)i;
            }
            catchy[i]=solution;
        }
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            int number;
            number=in.nextInt();
            System.out.println(catchy[number]);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}