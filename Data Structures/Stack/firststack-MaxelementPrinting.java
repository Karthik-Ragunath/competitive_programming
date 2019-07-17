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
        for(int i=0;i<numberoflines;i++)
        {
            int input=in.nextInt();
            if(input==1)
            {
                long pushelement=in.nextLong();
                firststack.push(new Long(pushelement));
            }
            if(input==2)
            {
                firststack.pop();
            }
            if(input==3)
            {
                Iterator stacko=firststack.iterator();
                long maximum=0;
                while(stacko.hasNext())
                {
                    long value=(long)stacko.next();
                    if(value>maximum)
                    {
                        maximum=value;
                    }
                }
                System.out.println(maximum);
            }
            /*if(firststack.empty()==false)
            {
                System.out.println(firststack.peek());
            }*/
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}