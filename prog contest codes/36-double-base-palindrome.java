import java.io.*;
import java.util.*;

public class Solution {
    int palindromecreator(int number,int base,int isodd)
    {
        int n=number;
        int palin=number;
        if(isodd==1)
        {
            n=n/base;   
        }
        while(n>0)
        {
            palin=palin*base+(n%base);
            n=n/base;
        }
        return palin;
    }
    int ispalindrome(int number,int base)
    {
        int reverse=0;
        int k=number;
        while(k>0)
        {
            reverse=reverse*base+(k%base);
            k=k/base;
        }
        if(reverse==number)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    public static void main(String[] args) {
        long realsolution=0;
        int limit,base,number,isodd;
        Scanner in=new Scanner(System.in);
        limit=in.nextInt();
        base=in.nextInt();
        for(int j=0;j<2;j++)
        {
            if(j%2==0)
            {
                isodd=1;
            }
            else
            {
                isodd=0;
            }
            int i=1;
            number=new Solution().palindromecreator(i,10,isodd);
            while(number<=limit)
            {
                int checker=new Solution().ispalindrome(number,base);
                if(checker==1)
                {
                    realsolution=(long)(realsolution+(long)number);
                }
                i++;
                number=new Solution().palindromecreator(i,10,isodd);
            }
        }
        System.out.println(realsolution);
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}