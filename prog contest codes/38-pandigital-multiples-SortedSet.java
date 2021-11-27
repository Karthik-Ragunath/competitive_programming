import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        int multiplier;
        int pandigital;
        Scanner in=new Scanner(System.in);
        multiplier=in.nextInt();
        pandigital=in.nextInt();
        for(int i=2;i<multiplier;i++)
        {
            SortedSet<Integer> numbers=new TreeSet<Integer>();
            for(int j=1;j<=pandigital;j++)
            {
                numbers.add(j);
            }
            String s1=null;
            for(int j=1;j<=6;j++)
            {
                int temp=i*j;
                Integer tempo;
                int length;
                if(j==1)
                {
                    s1=String.valueOf(temp);
                    length=s1.length();
                    if(length>pandigital)
                    {
                        break;
                    }
                    while(temp>0)
                    {
                        tempo=temp%10;
                        if(numbers.contains(tempo))
                        {
                            numbers.remove(tempo);
                        }
                        temp=temp/10;
                    }
                    if(numbers.isEmpty())
                    {
                        System.out.println(i);
                    }
                }
                else
                {
                    s1=s1+String.valueOf(temp);
                    length=s1.length();
                    if(length>pandigital)
                    {
                        break;
                    }
                    while(temp>0)
                    {
                        tempo=temp%10;
                        if(numbers.remove(tempo))
                        {
                            numbers.remove(tempo);
                        }
                        temp=temp/10;
                    }
                    if(numbers.isEmpty())
                    {
                        System.out.println(i);
                    }
                }
                
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}