import java.io.*;
import java.lang.*;
import java.util.*;
import java.text.*;
import java.math.*;

class plants
{
    int value;
    int day;
    int priority;
    boolean flagship;
    plants prev;
}
public class Solution {
    public static void main(String[] args) {
        int numberofflowers;
        int maximum=0;
        Scanner in=new Scanner(System.in);
        numberofflowers=in.nextInt();
        plants poisonous=new plants();
        poisonous.value=in.nextInt();
        poisonous.flagship=true;
        poisonous.day=0;
        poisonous.priority=0;
        poisonous.prev=null;
        for(int i=1;i<numberofflowers;i++)
        {
            plants new_poisonous=new plants();
            new_poisonous.value=in.nextInt();
            new_poisonous.day=i;
            new_poisonous.priority=0;
            while((poisonous!=null)&&(new_poisonous.value<=poisonous.value))
            {
                if(new_poisonous.priority<=poisonous.priority)
                {
                    new_poisonous.priority=poisonous.priority;
                }
                poisonous=poisonous.prev;
            }
            if(poisonous==null)
            {
                new_poisonous.prev=poisonous;
                poisonous=new_poisonous;
            }
            else
            {
                new_poisonous.priority=new_poisonous.priority+1;
                new_poisonous.prev=poisonous;
                poisonous=new_poisonous;
            }
            if(new_poisonous.priority>maximum)
            {
                maximum=new_poisonous.priority;
            }
        }
        System.out.println(maximum);
    }
}