import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int value;
        int number;
        long result;
        number=in.nextInt();
        SortedSet<Long> karthik=new TreeSet<Long>();
        for(long a=2;a<=number;a++)
        {
            for(long b=2;b<=number;b++)
            {
                result=(long)Math.pow(a,b);
                karthik.add(result);
            }
        }
        value=karthik.size();
        System.out.println(value);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}