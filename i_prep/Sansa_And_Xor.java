import java.io.*;
import java.lang.*;
import java.util.*;
public class Solution {
    public static void main(String args[] ) throws Exception {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int k=0;k<testcases;k++)
        {
            int number_of_elements=in.nextInt();
            int[] input=new int[number_of_elements];
            for(int i=0;i<number_of_elements;i++)
            {
                input[i]=in.nextInt();
            }
            if(number_of_elements%2==0)
            {
                System.out.println("0");
                continue;
            }
            int answer=input[0];
            for(int i=2;i<number_of_elements;i=i+2)
            {
                answer=answer^input[i];
            }
            System.out.println(answer);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    }
}