import java.io.*;
import java.util.*;

public class Solution {
    /*int factorize(int num,int[] prime)
    {
        int expo=0;
        for(int i=0;i<=1000;i++)
        {
            while(num%prime[i]==0)
            {
                expo=expo+1;
                num=num/prime[i];
            }
            if(num==1)
            {
                break;
            }
            if(i==1000)
            {
                expo=expo+1;
                break;
            }
        }
        return expo;
    }*/
    int factorize(int num,int[] prime)
    {
        int expo=0;
        for(int i=0;prime[i]<=num;i++)
        {
            int n=2;
            expo=expo+1;
            int temp=prime[i];
            int tempvalue=temp*n;
            while(tempvalue<=num)
            {
                expo=expo+1;
                n++;
                tempvalue=temp*n;
            }
            int m=1;
            tempvalue=prime[i]*m;
            while(tempvalue<=(num/2))
            {
                expo=expo+m;
                m++;
                tempvalue=tempvalue*m;
            }
        }
        return expo;
    }
    /*int factorial(int num)
    {
        int value=1;
        for(int i=1;i<=num;i++)
        {
            value=value*i;
        }
        return value;
    }*/

    public static void main(String[] args) {
        int numberofterms;
        Scanner in=new Scanner(System.in);
        numberofterms=in.nextInt();
        int[] prime=new int[100000];
        prime[0]=2;
        int n=0,duplicate,duplicate1,flagship;
        for(int i=3;n<=1500;i=i+2)
        {
            duplicate=n;
            duplicate1=duplicate+1;
            flagship=1;
            while(duplicate1!=0)
            {
                duplicate1=duplicate1-1;
                if(i%prime[duplicate]==0)
                {
                    flagship=0;
                    break;
                }
                duplicate--;
            }
            if(flagship==1)
            {
                n++;
                prime[n]=i;
            }
        }
        int[] inputterms=new int[numberofterms];
        int[] value=new int[numberofterms];
        for(int i=0;i<numberofterms;i++)
        {
            int temp=in.nextInt();
            inputterms[i]=temp;
            //int value2=new Solution().factorial(temp);
            value[i]=new Solution().factorize(temp,prime);
            //System.out.println(value[i]);
        }
        int count=(int)Math.pow(2,numberofterms);
        int[][] a=new int[count][numberofterms];
        for(int i=0;i<count;i++)
        {
            int temp=i;
            int j;
            if(temp<2)
            {
                j=0;
                a[i][j]=temp;
            }
            else
            {
                j=0;
                while(temp>1)
                {
                    a[i][j]=temp%2;
                    j++;
                    temp=temp/2;
                }
                a[i][j]=temp;
            }
        }
        for(int i=0;i<count;i++)
        {
            int value1=0;
            for(int j=0;j<numberofterms;j++)
            {
                if(a[i][j]==1)
                {
                    value1=value1+value[j];
                }
            }
            if((value1%2==0)&&(value1!=0))
            {
                System.out.println(value1);
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}