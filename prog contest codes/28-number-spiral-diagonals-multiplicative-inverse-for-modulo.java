import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            long number1,diagonal,modulas=1000000007,x,value=0,realsolution=0,diagonal1,diagonal2,diagonal3;
            BigInteger number;
            number=in.nextBigInteger();
            //number=number.mod(BigInteger.valueOf(1000000007));
            if(number.compareTo(BigInteger.valueOf(1))==0)
            {
                System.out.println("1");
                continue;
            }
            number1=number.longValue();
            number1=number1/2;
            /*way to find multiplicative inverse of a number:(multiplicative inverse of 3 mod 1000000007)
            long a=3;
            a=a%modulas;
            for(x=1;x<modulas;x++)
            {
                if((a*x)%modulas==1)
                {
                    value=x;
                    break;
                }
            }
            System.out.println(value);*/
            value=333333336;
                        //System.out.println(value);
            /*diagonal=((8*(number1)*(number1+1)*(2*number1+1))/3)%(1000000007);
            diagonal=(diagonal+(2*(number1)*(number1+1)))%(1000000007);
            diagonal=(diagonal+(4*number1))%(1000000007);
            diagonal=(diagonal+1)%(1000000007);*/
            diagonal=(8*(number1%modulas))%modulas;
                //System.out.println(diagonal);
            diagonal=(diagonal*((number1+1)%modulas))%modulas;
                //System.out.println(diagonal);
            diagonal=(diagonal*((((2*(number1))%modulas)+1)%modulas)%modulas)%modulas;
                //System.out.println(diagonal);
            diagonal=(diagonal*value)%modulas;
            diagonal1=(2*(number1%modulas))%modulas;
            diagonal1=(diagonal1*((number1+1)%modulas))%modulas;
            diagonal2=(4*(number1%modulas))%modulas;
            diagonal3=(1%modulas);
            realsolution=(diagonal+diagonal1)%modulas;
            realsolution=(realsolution+diagonal2)%modulas;
            realsolution=(realsolution+diagonal3)%modulas;
            System.out.println(realsolution);
           /*System.out.println(diagonal);
            System.out.println(diagonal1);
            System.out.println(diagonal2);*/
            
            
        }
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}