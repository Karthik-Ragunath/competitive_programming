import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;

class plants
{
    int value;
    int serialnumber;
    boolean flagship;
    plants next;
    plants prev;
}
public class Solution {
    public static void main(String[] args) {
        int numberofflowers;
        int count=0;
        Scanner in=new Scanner(System.in);
        numberofflowers=in.nextInt();
        int maximum=0;
        plants poisonous_plants=new plants();
        plants prev_node=new plants();
        plants looper=new plants();
        poisonous_plants.value=in.nextInt();
        poisonous_plants.serialnumber=count++;
        poisonous_plants.flagship=true;
        poisonous_plants.next=new plants();
        poisonous_plants.prev=null;
        prev_node=poisonous_plants;
        poisonous_plants=poisonous_plants.next;
        for(int i=1;i<numberofflowers;i++)
        {
            int temp=0;
            int loopmaintainer=0;
            if(i==numberofflowers-1)
            {
                poisonous_plants.value=in.nextInt();
                poisonous_plants.serialnumber=count++;
                poisonous_plants.prev=prev_node;
                looper=prev_node;
                poisonous_plants.next=null;
            }
            else
            {
                poisonous_plants.value=in.nextInt();
                poisonous_plants.serialnumber=count++;
                poisonous_plants.prev=prev_node;
                looper=prev_node;
                prev_node=poisonous_plants;
                poisonous_plants.next=new plants();
            }
            
            while(poisonous_plants.value<looper.value)
            {
                if(looper.flagship==true)
                {
                    poisonous_plants.flagship=true;
                    loopmaintainer=1;
                    break;
                }
                else
                {
                    temp=temp+1;
                    looper=looper.prev;
                }
            }
            if(loopmaintainer==0)
            {
                poisonous_plants.flagship=false;
            }
            if(temp>maximum)
            {
                maximum=temp;
            }
            if(i!=numberofflowers-1)
            {
                poisonous_plants=poisonous_plants.next;
            }
        }
        System.out.println(maximum);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}