import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        for(int i=0;i<testcases;i++)
        {
            int number;
            number=in.nextInt();
            int sequencelength,realsolution=0;
            sequencelength=0;
            for(int j=number-1;j>1;j--)
            {
                if(sequencelength>=j)
                {
                    break;
                }
                int value=1;
                int position=0;
                int[] array=new int[j];  
                while(array[value]==0 && value!=0)
                {
                    array[value]=position;
                    value=value*10;
                    value=value%j;
                    position=position+1;
                }
                if(array[value]!=0)
                {
                    if((position-array[value])>sequencelength)
                    {
                        sequencelength=position-array[value];
                        realsolution=j;
                    }
                }
            }
            System.out.println(realsolution);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}