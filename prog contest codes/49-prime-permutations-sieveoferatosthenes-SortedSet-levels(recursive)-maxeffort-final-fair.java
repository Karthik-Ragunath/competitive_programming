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

    public static void main(String[] args) throws java.lang.Exception
    {
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
        Scanner in=new Scanner(System.in);
        int input;
        input=in.nextInt();
        int consequtive;
        int flagship1;
        consequtive=in.nextInt();
        int solution3_count=0;
        int solution4_count=0;
        int[][] solutions=new int[1000][consequtive];
        for(int h=1000;h<input;h++)
        {
            if(primeset.contains(h))
            {
                String s1;
                s1=String.valueOf(h);
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
                        //System.out.println(permutedarray[permutationarraylength]);
                        permutationarraylength++;
                    }
                }
                    /*if(permutedarray[0]==1487)
                    {
                        for(int i=0;i<permutationarraylength;i++)
                        {
                           System.out.println(permutedarray[i]); 
                        }
                        System.out.println("hi "+h);
                    }*/
                int flagship=1;
                for(int i=0;i<(permutationarraylength-consequtive+1);i++)
                {
                    int[] consequtivearray=new int[consequtive];
                    int length1=(String.valueOf(permutedarray[i])).length();
                    int temp1;
                    int k=0,consequtivechecker=1;
                    consequtivearray[k]=permutedarray[i];
                    for(int j=i+1;j<permutationarraylength+1;j++)
                    {
                        int arithmeticprogression=permutedarray[j]-permutedarray[i];
                        temp1=(String.valueOf(permutedarray[j])).length();
                        if(length1!=temp1)
                        {
                            continue;
                        }
                        k=1;
                        consequtivearray[k]=permutedarray[j];
                        consequtivechecker=2;
                        for(int jo=j+1;jo<permutationarraylength+1;jo++)
                        {
                            if((permutedarray[jo]-permutedarray[j])==arithmeticprogression)
                            {
                                k=2;
                                temp1=(String.valueOf(permutedarray[jo])).length();
                                if(temp1!=length1)
                                {
                                    continue;
                                }
                                //System.out.println(k+" "+jo);
                                consequtivearray[k]=permutedarray[jo];
                                consequtivechecker=3;
                                if(consequtivechecker==consequtive)
                                {
                                    flagship1=0;
                                    if(consequtivearray[0]>=input)
                                    {
                                        break;
                                    }
                                    //System.out.println(solution3_count);
                                    if(solution3_count==0)
                                    {
                                        for(int ma=0;ma<=k;ma++)
                                        {
                                            solutions[solution3_count][ma]=consequtivearray[ma];
                                            System.out.print(consequtivearray[ma]);
                                        }
                                        System.out.println();
                                        solution3_count=solution3_count+1;
                                        break;
                                    }
                                    else
                                    {
                                        for(int me=0;me<solution3_count;me++)
                                        {
                                            flagship=1;
                                            for(int ma=0;ma<=k;ma++)
                                            {
                                                if(solutions[me][ma]!=consequtivearray[ma])
                                                {
                                                    flagship=0;
                                                    break;
                                                }
                                            }
                                            if(flagship==1)
                                            {
                                                break;
                                            }
                                        }
                                        if(flagship==0)
                                        {
                                            for(int ma=0;ma<=k;ma++)
                                            {
                                                solutions[solution3_count][ma]=consequtivearray[ma];
                                                System.out.print(consequtivearray[ma]);
                                            }
                                            solution3_count++;
                                            System.out.println();
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    for(int ko=jo+1;ko<permutationarraylength+1;ko++)
                                    {
                                        if((permutedarray[ko]-permutedarray[jo])==arithmeticprogression)
                                        {
                                            k=3;
                                            temp1=(String.valueOf(permutedarray[ko])).length();
                                            if(temp1!=length1)
                                            {
                                                continue;
                                            }
                                            consequtivearray[k]=permutedarray[ko];
                                            consequtivechecker=4;
                                            if(consequtivechecker==consequtive)
                                            {
                                                flagship1=0;
                                                if(consequtivearray[0]>=input)
                                                {
                                                    break;
                                                }
                                                if(solution4_count==0)
                                                {
                                                    if(consequtivearray[k]>=0)
                                                    for(int ma=0;ma<=k;ma++)
                                                    {
                                                        solutions[solution4_count][ma]=consequtivearray[ma];
                                                        System.out.print(consequtivearray[ma]);
                                                    }
                                                    System.out.println();
                                                    solution4_count++;
                                                    break;
                                                }
                                                else
                                                {
                                                    for(int me=0;me<solution4_count;me++)
                                                    {
                                                        flagship=1;
                                                        for(int ma=0;ma<=k;ma++)
                                                        {
                                                            if(solutions[me][ma]!=consequtivearray[ma])
                                                            {
                                                                flagship=0;
                                                                break;
                                                            }
                                                        }
                                                        if(flagship==1)
                                                        {
                                                            break;
                                                        }
                                                    }
                                                    if(flagship==0)
                                                    {
                                                        for(int ma=0;ma<=k;ma++)
                                                        {
                                                            solutions[solution4_count][ma]=consequtivearray[ma];
                                                            System.out.print(consequtivearray[ma]);
                                                        }
                                                        System.out.println();
                                                        solution4_count++;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}