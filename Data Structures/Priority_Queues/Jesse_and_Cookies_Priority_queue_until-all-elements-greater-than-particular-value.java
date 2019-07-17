import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        PriorityQueue<Integer> firstminqueue=new PriorityQueue<Integer>();
        int number_of_elements;
        int required_sweetness;
        Scanner in=new Scanner(System.in);
        number_of_elements=in.nextInt();
        required_sweetness=in.nextInt();
        boolean solution=false;
        int count=0;
        for(int i=0;i<number_of_elements;i++)
        {
            int temp=in.nextInt();
            firstminqueue.add(temp);
        }
        while(true)
        {
            int element_one=firstminqueue.poll();
            if(element_one>=required_sweetness)
            {
                solution=true;
                break;
            }
            if(firstminqueue.isEmpty())
            {
                solution=false;
                break;
            }
            int element_two=firstminqueue.poll();
            int new_element=element_one+2*element_two;
            firstminqueue.add(new_element);
            count=count+1;
        }
        if(solution==true)
        {
            System.out.println(count);
        }
        else
        {
            System.out.println("-1");
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}