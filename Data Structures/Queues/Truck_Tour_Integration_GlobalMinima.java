import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int number_of_stations=in.nextInt();
        int minimum_index=0;
        int resultant=0;
        for(int i=0;i<number_of_stations;i++)
        {
            int petrol_at_the_station=in.nextInt();
            int distance_to_the_next=in.nextInt();
            resultant=resultant+petrol_at_the_station-distance_to_the_next;
            if(resultant<0)
            {
                resultant=0;
                minimum_index=i+1;
            }
        }
        if(resultant>=0)//to supress the case where it is not possible to complete a circle
        {
            System.out.println(minimum_index);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}