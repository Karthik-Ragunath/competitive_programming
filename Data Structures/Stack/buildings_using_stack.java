import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
import java.text.*;

class buildings
{
    int sequencenumber;
    buildings prev;
}

public class Solution {
    public static void main(String[] args) {
        int numberofbuildings;
        Scanner in=new Scanner(System.in);
        numberofbuildings=in.nextInt();
        long maximumarea=0;
        int i=0;
        int[] building_heights=new int[numberofbuildings];
        buildings build_top=new buildings();
        for(i=0;i<numberofbuildings;i++)
        {
            building_heights[i]=in.nextInt();
            if(i==0)
            {
                buildings build=new buildings();
                build.sequencenumber=i;
                build.prev=null;
                build_top=build;
            }
            else
            {
                buildings build=new buildings();
                build.sequencenumber=i;
                if(build_top!=null)
                {
                    if(building_heights[i]>=building_heights[build_top.sequencenumber])
                    {
                        build.prev=build_top;
                        build_top=build;
                    }
                    if(building_heights[i]<building_heights[build_top.sequencenumber])
                    {
                        boolean flagship=true; 
                        while(building_heights[i]<building_heights[build_top.sequencenumber])
                        {
                            if(build_top.prev!=null)
                            {
                                int top=build_top.sequencenumber;
                                build_top=build_top.prev;
                                long temp_maxarea=(long)(building_heights[top]*(i-(build_top.sequencenumber)-1));
                                if(temp_maxarea>maximumarea)
                                {
                                    maximumarea=temp_maxarea;
                                }
                            }
                            else
                            {
                                int top=build_top.sequencenumber;
                                build_top=build_top.prev;
                                long temp_maxarea=(long)(building_heights[top]*i);
                                if(temp_maxarea>maximumarea)
                                {
                                    maximumarea=temp_maxarea;
                                }
                                flagship=false;
                                break;
                            }
                        }
                        if(flagship==true)
                        {
                            build.prev=build_top;
                            build_top=build;
                        }
                        else
                        {
                            build.prev=null;
                            build_top=build;
                        }
                    }
                }
            }
        }
        while(build_top!=null)
        {
            if(build_top.prev!=null)
            {
                int top=build_top.sequencenumber;
                build_top=build_top.prev;
                long temp_maxarea=(long)(building_heights[top]*(i-(build_top.sequencenumber)-1));
                if(temp_maxarea>maximumarea)
                {
                    maximumarea=temp_maxarea;
                }
            }
            else
            {
                int top=build_top.sequencenumber;
                long temp_maxarea=(long)(building_heights[top]*i);
                if(temp_maxarea>maximumarea)
                {
                    maximumarea=temp_maxarea;
                }
                break;
            }
        }
        System.out.println(maximumarea);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}