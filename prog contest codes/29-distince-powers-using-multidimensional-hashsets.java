import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

public class Solution {
    public static int[] factorize(int num,int[] primelist)
    {
        int expo,expochecker,value1;
        int[] arr=new int[2];
        int flagship,flag;
        int[] evenflag=new int[6];
        int[] oddflag=new int[6];
        int evenchecker=0,oddchecker=0;
        for(int k=0;k<6;k++)
        {
            evenflag[k]=2*(k+1);
            oddflag[k]=2*(k+1)+1;
        }
        int valuetobereturned=1;
        int[] exponent=new int[15];
        int[] factors=new int[100];
        int m=0;
        for(int j=0;j<1500;j++)
        {
            expo=0;
            flagship=0;
            while(num%primelist[j]==0)
            {
                flagship=1;
                expo=expo+1;
                exponent[m]=expo;
                factors[m]=primelist[j];
                num=num/primelist[j];
            }
            if(flagship==1)
            {
                m=m+1;
            }
            if(num==1)
            {
                break;
            }
        }
        int[] duplicate=exponent.clone();
        expochecker=exponent[0];
        flag=0;
        for(int n=1;n<m;n++)
        {
            if(exponent[n]!=expochecker)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int n=0;n<m;n++)
            {
                valuetobereturned=valuetobereturned*factors[n];
            }
            arr[0]=valuetobereturned;
            arr[1]=exponent[0];
            return arr;
        }
        if(flag==1)
        {
            for(int k=0;k<6;k++)
            {
                for(int n=0;n<m;n++)
                {
                    if(exponent[n]%evenflag[k]!=0)
                    {
                        break;
                    }
                    if(n==(m-1))
                    {   
                        evenchecker=evenflag[k];
                    }
                }
            }
        }
        if(flag==1)
        {
            for(int k=0;k<6;k++)
            {
                for(int n=0;n<m;n++)
                {
                    if(exponent[n]%oddflag[k]!=0)
                    {
                        break;
                    }
                    if(n==(m-1))
                    {   
                        oddchecker=oddflag[k];
                    }
                }
            }
        }
        if((flag==1)&&(evenchecker==0)&&(oddchecker==0))
        {
            for(int n=0;n<m;n++)
            {
                value1=(int)Math.pow(factors[n],exponent[n]);
                valuetobereturned=valuetobereturned*value1;
            }
            arr[0]=valuetobereturned;
            arr[1]=1;
            return arr;
        }
        else
        {
            if(oddchecker>evenchecker)
            {
                for(int n=0;n<m;n++)
                {
                    exponent[n]=exponent[n]/oddchecker;
                    value1=(int)Math.pow(factors[n],exponent[n]);
                    valuetobereturned=valuetobereturned*value1;
                }
                arr[0]=valuetobereturned;
                arr[1]=oddchecker;
                return arr;
            }
            else
            {
                for(int n=0;n<m;n++)
                {
                    exponent[n]=exponent[n]/evenchecker;
                    value1=(int)Math.pow(factors[n],exponent[n]);
                    valuetobereturned=valuetobereturned*value1;
                }
                arr[0]=valuetobereturned;
                arr[1]=evenchecker;
                return arr;
            }
        }
        
        
    }

    public static void main(String[] args) {
        int[] prime=new int[2000];
        prime[0]=2;
        int n=0,duplicate,duplicate1,flagship;
        long realsolution=0;
        long exponent,longnumber;
        int factor;
        for(int i=3;i<=10000;i=i+2)
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
        //System.out.println(prime[n]);
        int number;
        Scanner in=new Scanner(System.in);
        number=in.nextInt();
        longnumber=(long)number;
        Set<Long>[] k=new HashSet[10001];
        for(int i=0;i<=10000;i++)
        {
            k[i]=new HashSet<Long>();
        }
        //Set<Long>[] k=(Set<Long>[])new HashSet[10000];
        for(int i=2;i<=number;i++)
        {
            int[] value=new Solution().factorize(i,prime);
            /*for(int l=0;l<2;l++)
            {
                System.out.println(value[l]);
            }*/
            factor=value[0];
            exponent=(long)value[1];
            if(exponent==1)
            {
                for(long j=2;j<=longnumber;j++)
                {
                    k[factor].add(j);
                }
                realsolution=realsolution+k[factor].size();
                  
            }
            else
            {
                long temp=k[factor].size();
                long temp1;
                long temp2;
                for(long j=2;j<=longnumber;j++)
                {
                    temp1=exponent*j;
                    k[factor].add(temp1);
                }
                temp2=k[factor].size();
                realsolution=realsolution+temp2-temp;
            }
               
        }
        System.out.println(realsolution);
        
        
        
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}