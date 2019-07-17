import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        long number;
        long query1;
        long query2;
        Scanner in=new Scanner(System.in);
        number=in.nextLong();
        query1=in.nextLong();
        query2=in.nextLong();
        SortedSet<Long> solutionset=new TreeSet<Long>();
        if((query1==3)&&(query2==5))
        {        
            for(long i=1;i<number;i++)
            {
                double output1=(double)((((double)Math.sqrt(i*8+1))-1.0)/2.0);
                double output2=(double)((((double)Math.sqrt(24*i+1))+1.0)/6.0);
                if((output1==Math.floor(output1)))
                {
                    if((output2==Math.floor(output2)))
                    {
                        solutionset.add(i);
                    }
                }
            }
        }
        else if((query1==5)&&(query2==6))
        {
            for(long i=1;i<number;i++)
            {
                double output1=(double)((((double)Math.sqrt(24*i+1))+1.0)/6.0);
                double output2=(double)((((double)Math.sqrt(8*i+1))+1.0)/4.0);
                if((output1==Math.floor(output1)))
                {
                    if((output2==Math.floor(output2)))
                    {
                        solutionset.add(i);
                    }
                }
            }
        }
        else if((query1==3)&&(query2==6))
        {
            for(long i=1;i<number;i++)
            {
                double output1=(double)((((double)Math.sqrt(i*8+1))-1.0)/2.0);
                double output2=(double)((((double)Math.sqrt(8*i+1))+1.0)/4.0);
                if((output1==Math.floor(output1)))
                {
                    if((output2==Math.floor(output2)))
                    {
                        solutionset.add(i);
                    }
                }
            }
        }
        Iterator loopy=solutionset.iterator();
        while(loopy.hasNext())
        {
            long temp=(long)(loopy.next());
            System.out.println(temp);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}