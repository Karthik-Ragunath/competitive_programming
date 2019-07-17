import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    int ispalindrome(int number,int base)
    {
        String num=null;
        if(base==10)
        {
            num=String.valueOf(number);
        }
        else
        {
            num=Integer.toString(number,base);
        }
        String reverse=new StringBuffer(num).reverse().toString();
        if(num.equals(reverse))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    public static void main(String[] args) {
        int limit,base;
        Scanner in=new Scanner(System.in);
        limit=in.nextInt();
        base=in.nextInt();
        long realsolution=0;
        int checker;
        int checker1;
        for(int i=1;i<=limit;i++)
        {
            checker=new Solution().ispalindrome(i,10);
            checker1=new Solution().ispalindrome(i,base);
            if((checker==1)&&(checker1==1))
            {
                realsolution=(long)(realsolution+(long)i);
            }
        }
        System.out.println(realsolution);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}