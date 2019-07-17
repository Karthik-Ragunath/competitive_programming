import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        in.nextLine();
        PriorityQueue<Integer> min_heap=new PriorityQueue<Integer>();
        for(int k=0;k<testcases;k++)
        {           
            String temp=in.nextLine();
            String[] splitter=temp.split(" ");
            int length=splitter.length;
            if(length!=1)
            {
                int operation=Integer.parseInt(splitter[0]);
                if(operation==1)
                {
                    int element_to_be_added=Integer.parseInt(splitter[1]);
                    min_heap.add(element_to_be_added);
                    continue;
                }
                else
                {
                    int element_to_be_removed=Integer.parseInt(splitter[1]);
                    min_heap.remove(element_to_be_removed);
                    continue;
                }
            }
            else
            {
                int element=min_heap.peek();
                System.out.println(element);
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}