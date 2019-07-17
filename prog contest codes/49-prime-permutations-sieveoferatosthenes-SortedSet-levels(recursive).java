import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    void permute(int[] integerarray,int k,int length,SortedSet<Integer> integerset)
        {
            if(k==length)
            {
                char[] tempchararray=new char[length+1];
                for(int i=0;i<=length;i++)
                {
                    tempchararray[i]=(char)(integerarray[i]+'0');
                }
                String tempstr=String.valueOf(tempchararray);
                int setpasser=Integer.parseInt(tempstr);
                integerset.add(setpasser);
            }
            else
            {
                for(int i=k;i<=length;i++)
                {
                    int temp=integerarray[i];
                    integerarray[i]=integerarray[k];
                    integerarray[k]=temp;
                    new Solution().permute(integerarray,k+1,length,integerset);
                    temp=integerarray[i];
                    integerarray[i]=integerarray[k];
                    integerarray[k]=temp;
                }
            }
        }

    public static void main(String[] args) {
        int upperbound=1000000;
        int sievebound=(int)((upperbound-1)/2);
        int uppersqrt=(((int)Math.sqrt(upperbound))-1)/2;
        boolean[] primebits=new boolean[sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=(2*i*(i+1));j<=sievebound;j+=(2*i+1))
                {
                    primebits[j]=false;
                }
            }
        }
        SortedSet<Integer> primeset=new TreeSet<Integer>();
        primeset.add(2);
        for(int i=1;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                primeset.add(2*i+1);
            }
        }
        Integer[] primearray=primeset.toArray(new Integer[primeset.size()]);
        String s1;
        Scanner in=new Scanner(System.in);
        s1=in.next();
        int length=s1.length();
        char[] characterarray=new char[length];
        int[] integerarray=new int[length];
        characterarray=s1.toCharArray();
        for(int i=0;i<length;i++)
        {
            integerarray[i]=(char)(characterarray[i]-'0');
        }
        SortedSet<Integer> integerset=new TreeSet<Integer>();
        int level=0;
        new Solution().permute(integerarray,level,length-1,integerset);
        Iterator loopy=integerset.iterator();
        int count=1;
        for(int i=1;i<=length;i++)
        {
            count=count*i;
        }
        int permutationarraylength=0;
        int[] permutedarray=new int[count];
        while(loopy.hasNext())
        {
            int temp=(int)loopy.next();
            //System.out.println(temp);
            if(primeset.contains(temp))
            {
                permutedarray[permutationarraylength]=temp;
                System.out.println(permutedarray[permutationarraylength]);
                permutationarraylength++;
            }
        }
        int consequtive;
        consequtive=in.nextInt();
        for(int i=0;i<(permutationarraylength-consequtive);i++)
        {
            int[] consequtivearray=new int[consequtive];
            int k=0,consequtivechecker=1;
            consequtivearray[k]=permutedarray[i];
            for(int j=i+1;j<permutationarraylength;j++)
            {
                int arithmeticprogression=permutedarray[j]-permutedarray[i];
                k=1;
                consequtivearray[k]=permutedarray[j];
                consequtivechecker=2;
                for(int jo=j+1;jo<permutationarraylength;jo++)
                {
                    if((permutedarray[jo]-permutedarray[j])==arithmeticprogression)
                    {
                        k=2;
                        System.out.println(k+" "+jo);
                        consequtivearray[k]=permutedarray[jo];
                        consequtivechecker=3;
                        if(consequtivechecker==consequtive)
                        {
                            for(int ma=0;ma<=k;ma++)
                            {
                                System.out.print(consequtivearray[ma]);
                            }
                            break;
                        }
                    }
                }
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}