import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String line1;
        line1=in.nextLine();
        String[] arr=line1.split(" ");
        long N=Long.parseLong(arr[0]);
        String[] arr1=new String[(int)N];
        long Q=Long.parseLong(arr[1]);
        long lastans=0;
        for(long i=0;i<Q;i++)
        {
            String line2=in.nextLine();
            String[] arr2=line2.split(" ");
            int decider=Integer.parseInt(arr2[0]);
            if(decider==1)
            {
                long x=Long.parseLong(arr2[1]);
                long y=Long.parseLong(arr2[2]);
                int sequence=(int)((x^lastans)%N);
                arr1[sequence]=arr1[sequence]+" "+String.valueOf(y);
            }
            else
            {
                long x=Long.parseLong(arr2[1]);
                long y=Long.parseLong(arr2[2]);
                int sequence=(int)((x^lastans)%N);
                String[] arr3=arr1[sequence].split(" ");
                long length1=(long)(arr3.length);
                long index=(long)(y%(length1-1));
                lastans=Long.parseLong(arr3[(int)(index+1)]);
                System.out.println(lastans);
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}