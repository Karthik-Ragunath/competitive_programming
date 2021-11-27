import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution {
    int isprime(int a1,int b1,int n1,int[] prime1)
    {
        
        int flagship=0;
        int checkvalue;
        checkvalue=Math.abs(n1*n1+a1*n1+b1);
        for(int k=0;k<2000;k++)
        {
            if(prime1[k]<=checkvalue)
            {
                if(checkvalue==prime1[k])
                {
                   flagship=1;
                   break;
                }
            }
            else
            {
                break;
            }
        }
        return flagship;
    }

    public static void main(String[] args) {
        int[] prime=new int[2016];
        prime[0]=2;
        int duplicate,duplicate1,n,flagship;
        n=0;
        for(int i=3;n<2000;i=i+2)
        {
            flagship=1;
            duplicate=n;
            duplicate1=duplicate+1;
            while(duplicate1!=0)
            {
                duplicate1=duplicate1-1;
                if(i%prime[duplicate]==0)
                {
                    flagship=0;
                    break;
                }
                duplicate--;
            }
            if(flagship==1)
            {
                n++;
                prime[n]=i;
            }
        }
        int number,maxvalue=0;
        int coefficientofa=0,coefficientofb=0;
        int breakflag=0;
        Scanner in=new Scanner(System.in);
        number=in.nextInt();
        for(int a=-number;a<=number;a++)
        {
            for(int b=-number;b<=number;b++)
            {
                n=0;
                int primechecker;
                primechecker=new Solution().isprime(a,b,n,prime);
                while(primechecker==1)
                {
                    /*if((n+1)==number) //to find lowest value which produces required number of primes within a given range ..                                           //give that range in place of number in for loops 
                    {
                        coefficientofa=a;
                        coefficientofb=b;
                        breakflag=1;
                        break;
                    }*/
                    n++;
                    primechecker=new Solution().isprime(a,b,n,prime);
                }
                if(n>maxvalue)
                {
                    maxvalue=n;
                    coefficientofa=a;
                    coefficientofb=b;
                }
                /*if(breakflag==1)
                {
                    break;
                }*/
            }
            /*if(breakflag==1)
            {
                break;
            }*/
        }
        System.out.println(coefficientofa+" "+coefficientofb);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}