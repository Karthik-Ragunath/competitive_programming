import java.io.*;
import java.lang.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class Solution {
    public static void main(String args[] ) throws java.lang.Exception {
        Stack st=new Stack();
        Scanner in=new Scanner(System.in);
        int nooflines=in.nextInt();
        Long temp;
        String condition;
        long value=0;
        long adder=0;
        long bottomelements=0;
        in.nextLine();
        for(int i=0;i<nooflines;i++)
        {
            String line;
            line=in.nextLine();
            //System.out.println(line);
            if(line.contains(" "))
            {
                String[] arr=line.split(" ");
                condition=arr[0];
                if(condition.equals("push")==true)
                {
                    value=Long.parseLong(arr[1]);
                }
                else
                {
                    
                }
            }
            else
            {
                condition=line;
            }
            //System.out.println(condition);
            //System.out.println(value);
            if(condition.equals("push")==true)
            {
                st.push((Long)value);
                temp=(Long)st.peek();
                System.out.println(temp);
            }
            if(condition.equals("pop")==true)
            {
                st.pop();
                if(st.empty()==true)
                {
                    System.out.println("EMPTY");
                }
                else
                {
                    temp=(Long)st.peek();
                    System.out.println(temp);
                }
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    }
}