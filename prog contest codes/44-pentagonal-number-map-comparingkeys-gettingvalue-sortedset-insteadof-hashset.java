import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        long noofterms,difference;
        Scanner in=new Scanner(System.in);
        noofterms=in.nextLong();
        difference=in.nextLong();
        Map<Long,Long> pentagonalmap=new TreeMap<Long,Long>();
        long[] pentagonals=new long[(int)noofterms];
        for(long i=1;i<noofterms;i++)
        {
            long temp;
            temp=(i*((3*i)-1))/2;
            pentagonals[(int)i]=temp;
            pentagonalmap.put(temp,i);
        }
        long loopender=noofterms-difference;
        SortedSet<Long> keyholder=new TreeSet<Long>();
        for(long i=(difference+1);i<noofterms;i++)
        {
            long j=i-difference;
            long temp1=pentagonals[(int)i];
            long temp2=pentagonals[(int)j];
            long temp3=pentagonals[(int)i]+pentagonals[(int)j];
            long temp4=pentagonals[(int)i]-pentagonals[(int)j];
            if(pentagonalmap.containsKey(temp3))
            {
                long temp5=(long)pentagonalmap.get(temp3);
                keyholder.add(temp1);
            }
            if(pentagonalmap.containsKey(temp4))
            {
                long temp6=(long)pentagonalmap.get(temp4);
                keyholder.add(temp1);
            }
        }
        Iterator loopy=keyholder.iterator();
        while(loopy.hasNext())
        {
            long temp=(long)(loopy.next());
            System.out.println(temp);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}