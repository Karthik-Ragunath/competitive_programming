import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Solution{
    public static void main(String[] args){
        int upperbound=10000000;
        int sievebound=(int)((upperbound-1)/2);
        int uppersqrt=(int)((((int)Math.sqrt(upperbound))-1)/2);
        boolean[] primebits=new boolean[sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=2*i*(i+1);j<=sievebound;j+=(2*i+1))
                {
                    primebits[j]=false;
                }
            }
        }
        SortedSet<Integer> primelist=new TreeSet<Integer>();
        long sum=2;
        SortedSet<Long> cumulation_list=new TreeSet<Long>();
        primelist.add(0);
        primelist.add(2);
        cumulation_list.add(0L);
        cumulation_list.add(2L);
        for(int i=1;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                long temp=(long)(2*i+1);
                primelist.add(2*i+1);
                sum=sum+temp;
                cumulation_list.add(sum);
            }
        }
        Integer[] primearray=primelist.toArray(new Integer[primelist.size()]);
        Long[] cumulationarray=cumulation_list.toArray(new Long[cumulation_list.size()]);
        //System.out.print("Outside :");
        //System.out.println(cumulationarray[6]-cumulationarray[0]);
        int arraysizes=primelist.size();
        //System.out.println(primearray[primelist.size()-1]);
        //System.out.println(cumulationarray[cumulation_list.size()-1]);
        Scanner in=new Scanner(System.in);
        int testcases=in.nextInt();
        for(int k=0;k<testcases;k++)
        {
            int numberofterms=0;
            long maxsum=0;
            long number;
            number=in.nextLong();
            for(int i=0;i<arraysizes;i++)
            {
                if(primearray[i]>number)
                {
                    break;
                }
                for(int j=arraysizes-1;j>i;j--)
                {
                    if((long)primearray[j]>number)
                    {
                        continue;
                    }
                    long difference=cumulationarray[j]-cumulationarray[i];
                    if(difference<number)
                    {
                        if(primelist.contains((int)difference))
                        {
                            /*System.out.println("Index: "+j+" "+i);
                            System.out.println("Cumulate: "+cumulationarray[j]+" "+cumulationarray[i]);*/
                            int temp_numberofterms=j-i;
                            if(temp_numberofterms>numberofterms)
                            {
                                numberofterms=temp_numberofterms;
                                maxsum=difference;
                            }
                            else if(temp_numberofterms==numberofterms)
                            {
                                if(maxsum>difference)
                                {
                                    numberofterms=temp_numberofterms;
                                    maxsum=difference;
                                }
                            }
                        }
                    }
                }
            }
            System.out.println(maxsum+" "+numberofterms);    
        }
    }
}