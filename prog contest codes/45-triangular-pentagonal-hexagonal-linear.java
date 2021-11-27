import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        long number;
        long query1;
        long query2;
        Scanner in=new Scanner(System.in);
        number=in.nextLong();
        query1=in.nextLong();
        query2=in.nextLong();
        long[] temp1=new long[2];//pentagonal
        long temp2=0;//triangular
        long temp3;//temporary
        long[] temp4=new long[2];//hexagonal
        SortedSet<Long> solutionset=new TreeSet<Long>();
        if((query1==3)&&(query2==5))
        {        
            for(long i=1;;i++)
            {
                if(i==1)
                {
                    System.out.println("1");
                    temp1[0]=1;
                    temp2=1;
                    continue;
                }
                if(i==2)
                {
                    temp3=temp1[0]+4;
                    if(temp3<number)
                    {
                        temp1[1]=5;
                    }
                    else
                    {
                        break;
                    }
                    temp3=temp2+i;
                    if(temp3<number)
                    {
                        temp2=temp2+i;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                else
                {
                    if(temp1[1]<number)
                    {
                        temp3=temp1[1];
                        temp1[1]=temp1[1]+(temp1[1]-temp1[0])+3;
                        temp1[0]=temp3;
                        if(temp1[1]<number)
                        {
                            solutionset.add(temp1[1]);
                        }
                    }
                    temp2=temp2+i;
                    if(temp2<number)
                    {
                        if(solutionset.contains(temp2))
                        {
                            System.out.println(temp2);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                
            }
        }
        if((query1==5)&&(query2==6))
        {
            for(long i=1;;i++)
            {
                if(i==1)
                {
                    System.out.println("1");
                    temp4[0]=1;
                    temp1[0]=1;
                    continue;
                }
                if(i==2)
                {
                    temp3=temp4[0]+5;
                    if(temp3<number)
                    {
                        temp4[1]=6;
                    }
                    else
                    {
                        break;
                    }
                    temp3=temp1[0]+4;
                    if(temp3<number)
                    {
                        temp1[1]=5;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(temp4[1]<number)
                    {
                        temp3=temp4[1];
                        temp4[1]=temp4[1]+(temp4[1]-temp4[0])+4;
                        temp4[0]=temp3;
                        if(temp4[1]<number)
                        {
                            solutionset.add(temp4[1]);
                        }
                    }
                    temp3=temp1[1];
                    temp1[1]=temp1[1]+(temp1[1]-temp1[0])+3;
                    temp1[0]=temp3;
                    if(temp1[1]<number)
                    {
                        if(solutionset.contains(temp1[1]))
                        {
                            System.out.println(temp1[1]);
                        }
                    }
                    else
                    {
                        break;
                    }
                        
                }
            }
        }
        if((query1==3)&&(query2==6))
        {
            for(long i=1;;i++)
            {
                temp3=i*(2*i-1);
                if(temp3<number)
                {
                    System.out.println(temp3);
                }
                else
                {
                    break;
                }
            }
        }

        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}