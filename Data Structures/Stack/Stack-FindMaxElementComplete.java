import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int numberoflines=in.nextInt();
        Stack firststack=new Stack();
        long maximum=0;
        long count_maintainer=1;
        Map<Long,Long> maxforeachelement=new TreeMap<Long,Long>();
        for(int i=0;i<numberoflines;i++)
        {
            int input=in.nextInt();
            if(input==1)
            {
                long pushelement=in.nextLong();
                firststack.push(new Long(pushelement));
                if(pushelement>maximum)
                {
                    maxforeachelement.put(count_maintainer,pushelement);
                    maximum=maxforeachelement.get(count_maintainer);
                }
                else
                {
                    maxforeachelement.put(count_maintainer,maximum);
                    maximum=maxforeachelement.get(count_maintainer);
                }
                count_maintainer++;
                //System.out.println(count_maintainer);
            }
            if(input==2)
            {
                firststack.pop();
                count_maintainer=count_maintainer-1;
                maxforeachelement.remove(count_maintainer);
                if(count_maintainer==1)
                {
                    maximum=0;
                }
                else
                {
                    maximum=(long)maxforeachelement.get(count_maintainer-1);
                }
            }
            if(input==3)
            {
                long value=(long)maxforeachelement.get(count_maintainer-1);
                System.out.println(value);
            }
            /*if(firststack.empty()==false)
            {
                System.out.println(firststack.peek());
            }*/
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}