import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        Map<Integer,Integer> hashy=new TreeMap<Integer,Integer>();
        for(int i=12;i<=(5*10000);i++)
        {
            int numberofsolutions=0;
            for(int a=2;a<(i/3);a++)
            {
                if((i*(i-2*a))%(2*(i-a))==0)
                {
                    numberofsolutions++;
                    hashy.put(i,numberofsolutions);
                }
            }
        }
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            int number,realsolution=0;
            int maxvalue=0;
            number=in.nextInt();
            for(int j=12;j<=number;j++)
            {
                    if(hashy.containsKey(j))
                    {
                        int value=hashy.get(j);
                        if(value>maxvalue)
                        {
                            maxvalue=value;
                            realsolution=j;
                        }
                    }
            }
            System.out.println(realsolution);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}