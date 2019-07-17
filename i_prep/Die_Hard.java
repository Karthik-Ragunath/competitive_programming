import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int testcases;
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            int jar1=in.nextInt();
            int jar2=in.nextInt();
            int measurement=in.nextInt();
            if((measurement==jar1)||(measurement==jar2))
            {
                System.out.println("YES");
                continue;
            }
            int frac1,frac2;
            if(jar1>jar2)
            {
                frac1=jar1;
                frac2=jar2;
            }
            else
            {
                frac1=jar2;
                frac2=jar1;
            }
            while(frac2!=0)
            {
                int temp=frac2;
                frac2=frac1%frac2;
                frac1=temp;
            }
            int gcd=frac1;
            if((measurement%gcd==0)&&((measurement<=jar1)||(measurement<=jar2)))
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}