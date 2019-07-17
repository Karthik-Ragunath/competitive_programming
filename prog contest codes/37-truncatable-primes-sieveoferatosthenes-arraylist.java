import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        int upperbound,realsolution=0;
        Scanner in=new Scanner(System.in);
        upperbound=in.nextInt();
        int sievebound=(upperbound-1)/2;
        int uppersqrt=(int)((Math.sqrt(upperbound)-1)/2);
        boolean[] primebits=new boolean[sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=(2*i*(i+1));j<=sievebound;j=j+(2*i+1))
                {
                    primebits[j]=false;
                }
            }
        }
        List<Integer> numbers=new ArrayList<Integer>();
        numbers.add(2);
        for(int i=1;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                numbers.add(2*i+1);
            }
        }
        Integer[] number=numbers.toArray(new Integer[numbers.size()]);
        //System.out.println(number[numbers.size()-1]);
        //System.out.println(number[4]);
        int length=numbers.size()-1;
        for(int i=4;i<=length;i++)
        {
            boolean checker=true;
            int multiplier=1;
            int length1=String.valueOf(number[i]).length();
            int lefttrunk=number[i];
            int righttrunk=0;
            for(int j=0;j<length1;j++)
            {
                righttrunk=multiplier*(lefttrunk%10)+righttrunk;
                if(numbers.contains(lefttrunk)&&numbers.contains(righttrunk))
                {
                    lefttrunk=lefttrunk/10;
                    multiplier=multiplier*10;
                }
                else
                {
                    checker=false;
                    break;
                }
            }
            if(checker==true)
            {
                realsolution=realsolution+number[i];
            }
        }
        System.out.println(realsolution);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}