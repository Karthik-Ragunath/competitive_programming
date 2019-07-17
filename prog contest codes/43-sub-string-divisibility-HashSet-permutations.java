import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;
public class Solution {
    void permute(int[] integerarray,int k,int length,HashSet<String> stringlist)
    {
       
       if(k==length)
        {
            char[] tempchararray=new char[length+1];
            for(int jo=0;jo<=length;jo++)
            {
                tempchararray[jo]=(char)(integerarray[jo]+'0');
            }
            String temp=String.valueOf(tempchararray);
            stringlist.add(temp);
        }
        else
        {
            for(int i=k;i<=length;i++)
            {
                int temp=integerarray[i];
                integerarray[i]=integerarray[k];
                integerarray[k]=temp;
                new Solution().permute(integerarray,k+1,length,stringlist);
                temp=integerarray[i];
                integerarray[i]=integerarray[k];
                integerarray[k]=temp;
            }
        }
    }

    public static void main(String[] args) {
        long realsolution=0;
        Scanner in=new Scanner(System.in);
        int number;
        number=in.nextInt();
        String s1="";
        for(int i=0;i<=number;i++)
        {
            if(i==0)
            {
                char temp=(char)(i+'0');
                String tempstr=String.valueOf(temp);
                s1=tempstr;
            }
            else
            {
                char temp=(char)(i+'0');
                s1=s1+temp;
            }
        }
        int length=s1.length();
        int count=1;
        for(int i=1;i<=length;i++)
        {
            count=count*i;
        }
        String[] stringarray=new String[count];
        char[] characterarray=s1.toCharArray();
        int[] integerarray=new int[length];
        for(int i=0;i<length;i++)
        {
            integerarray[i]=(int)(characterarray[i]-'0');
        }
        int k=0;
        HashSet<String> stringlist=new HashSet<String>();
        new Solution().permute(integerarray,k,length-1,stringlist);
        Iterator loopy=stringlist.iterator();
        int p=0;
        while(loopy.hasNext())
        {
            String temp=(String)loopy.next();
            stringarray[p]=temp;
            p++;
        }
        int[] prime={2,3,5,7,11,13,17};
        for(int i=0;i<count;i++)
        {
            int flagship=1;
            for(int j=1;j<=length-3;j++)
            {
                String temp=stringarray[i].substring(j,j+3);
                int temporary=Integer.parseInt(temp);
                if(temporary%prime[j-1]!=0)
                {
                    flagship=0;
                    break;
                }
            }
            
            if(flagship==1)
            {
                int temporaryinteger=Integer.parseInt(stringarray[i]);
                realsolution=(long)(realsolution+(long)temporaryinteger);
            }
        }
        System.out.println(realsolution);
        }
}