import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        long[] limiter1=new long[17];
        long[] limiter2=new long[17];
        long[] adder=new long[17];
        long range1=0,range2=0;
        for(int i=1;i<=16;i++)
        {
            String str1="";
            String str2="";
            long tempnumber1,tempnumber2;
            for(int len=1;len<=i;len++)
            {
                if(len==1)
                {
                    str1=str1+"1";
                }
                else
                {
                    str1=str1+"0";
                }
                str2=str2+"9";
            }
            tempnumber1=Long.parseLong(str1);
            tempnumber2=Long.parseLong(str2);
            adder[i]=tempnumber2;
            range1=range2+1;
            range2=tempnumber2*((long)i);
            long num=0;
            long multiplier=1;
            if(i!=1)
            {
                for(int j=1;j<i;j++)
                {
                    num=9*multiplier+num;
                    range2=range2-num;
                    multiplier=multiplier*10;
                }
            }
            limiter1[i]=range1;
            limiter2[i]=range2;
        }
        /*for(int i=1;i<=16;i++)
        {
            System.out.println(limiter1[i]+" "+limiter2[i]);
        }*/
        for(int k=0;k<testcases;k++)
        {
            long realsolution=1;
            for(int j=1;j<=7;j++)
            {
                long number;
                number=in.nextLong();
                for(int i=1;i<=17;i++)
                {
                    if(number<=limiter2[i])
                    {
                            System.out.println("we are at number "+j);
                        long temp=number-limiter2[i-1];
                            System.out.println(number);
                            System.out.println(limiter2[i-1]);
                            System.out.println(temp);
                        long temp1=(temp/i)+adder[i-1];
                            System.out.println(adder[i-1]);
                            System.out.println(temp1);
                        long moduli=temp%i;
                            System.out.println(moduli);
                        if(moduli!=0)
                        {
                            temp1=temp1+1;
                                System.out.println(temp1);
                            String tempstr=String.valueOf(temp1);
                            int modulas=((int)moduli)-1;
                            char tempchar=tempstr.charAt(modulas);
                                System.out.println(tempchar);
                            long realnumber=(long)(tempchar-'0');
                                System.out.println(realnumber);
                            realsolution=realsolution*realnumber;
                            break;
                        }
                        else
                        {
                            int modulas=((int)moduli)+(i-1);
                                System.out.println(modulas);
                                System.out.println(temp1);
                            String tempstr=String.valueOf(temp1);
                                System.out.println(tempstr);
                            char tempchar=tempstr.charAt(modulas);
                                System.out.println(tempchar);
                            long realnumber=(long)(tempchar-'0');
                                System.out.println(realnumber);
                            realsolution=realsolution*realnumber;   
                            break;
                        }
                    }
                }
            }
            System.out.println(realsolution);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}