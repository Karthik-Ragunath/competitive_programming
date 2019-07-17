import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        Map<Integer,Integer> hashy=new TreeMap<Integer,Integer>();
        int maxvaluekey=0;
        int solution=0;
        for(int i=12;i<=(5*10000);i++)
        {
            int numberofsolutions=0;
            for(int a=2;a<(i/3);a++)
            {
                if((i*(i-2*a))%(2*(i-a))==0)
                {
                    numberofsolutions++;
                }
            }
            if(numberofsolutions>maxvaluekey)
            {
                maxvaluekey=numberofsolutions;
                solution=i;
            }
            hashy.put(i,solution);
        }
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            int number,realsolution=0;
            int maxvalue=0;
            number=in.nextInt();
            System.out.println(hashy.get(number));
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}