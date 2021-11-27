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
            int[] answer=new int[number_of_stones];
            int l=0;
            if(a==b)
            {
                answer[l++]=a*(number_of_stones-1);
                System.out.println(answer[0]);
                continue;
                //System.out.println(answer);
            }
            else
            {
                for(int i=0;i<number_of_stones;i++)
                {
                    int j=number_of_stones-1-i;
                    answer[l++]=j*a+i*b;
                    //System.out.print(answer+" ");
                }
                //System.out.println();
            }
            Arrays.sort(answer);
            for(int i=0;i<number_of_stones;i++)
            {
                System.out.print(answer[i]+" ");
            }
            System.out.println();
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}