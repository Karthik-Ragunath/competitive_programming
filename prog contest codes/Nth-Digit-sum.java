import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int number;
        Scanner in=new Scanner(System.in);
        number=in.nextInt();
        long upperbound;
        long realsolution=0;
        upperbound=(long)Math.pow(9,number);
        upperbound=upperbound*number;
        for(long i=2;i<=upperbound;i++)
        {
            long duplicate=i;
            long sumofpowers=0;
            while(duplicate>0)
            {
                long duplicate1=duplicate%10;
                sumofpowers=sumofpowers+(long)Math.pow(duplicate1,number);
                duplicate=duplicate/10;
            }
            if(sumofpowers==i)
            {
                realsolution=realsolution+sumofpowers;
            }
        }
        System.out.println(realsolution);
        
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}