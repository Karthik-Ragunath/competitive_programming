import java.io.*;
import java.util.*;
import java.lang.*;
public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int k=0;k<testcases;k++)
        {
            int number_of_stones=in.nextInt();
            int a=in.nextInt();
            int b=in.nextInt();
            int answer=0;
            if(a==b)
            {
                answer=a*(number_of_stones-1);
                System.out.println(answer);
                return;
            }
            else
            {
                for(int i=0;i<number_of_stones;i++)
                {
                    int j=number_of_stones-1-i;
                    answer=j*a+i*b;
                    System.out.print(answer+" ");
                }
                System.out.println();
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}