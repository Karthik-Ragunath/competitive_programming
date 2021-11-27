import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.lang.*;
public class Solution {

    public static void main(String[] args) {
        int[] prime=new int[50000];
        long realsolution=0;
        prime[0]=2;
        int n=0;
        int flagship;
        for(int i=3;i<=100000;i=i+2)
        {
            int duplicate=n;
            int duplicate1=duplicate+1;
            flagship=1;
            while(duplicate1!=0)
            {
                duplicate1--;
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
        List<Integer> primelist=new ArrayList<Integer>();
        for(int i=0;i<=n;i++)
        {
            int tempo=prime[i];
            primelist.add(tempo);
        }
        Iterator iteration=primelist.iterator();
        /*while(iteration.hasNext())
        {
            int test=(Integer)iteration.next();
            System.out.println(test);
        }*/
        Scanner in=new Scanner(System.in);
        int inputnumber=in.nextInt();
        int temp;
        for(int i=2;i<=inputnumber;i++)
        {
            int tempo1=i;
            if(primelist.contains(tempo1))
            {
                //System.out.println(i);
                String s1=String.valueOf(i);
                int length1;
                length1=s1.length();
                if(length1==1)
                {
                    //System.out.println(i);
                    realsolution=(long)(realsolution+(long)i);
                }
                else
                {
                    char[] characterarray=s1.toCharArray();
                    int[] integerarray=new int[length1];
                    for(int j=0;j<length1;j++)
                    {
                        temp=characterarray[j]-'0';
                        integerarray[j]=temp;
                    }
                    flagship=1;
                    int[] integerarray1=new int[length1];
                    for(int j=1;j<length1;j++)
                    {
                        for(int k=0;k<length1;k++)
                        {
                            temp=(j+k)%length1;
                            //System.out.println(temp);
                            integerarray1[k]=integerarray[temp];
                            //System.out.println(integerarray1[k]);
                            characterarray[k]=(char)(integerarray1[k]+'0');
                        }
                        String s2=String.valueOf(characterarray);
                        //System.out.println(s2);
                        //String s2=Arrays.toString(integerarray);
                        int value=Integer.parseInt(s2);
                        tempo1=value;
                        if(primelist.contains(tempo1))
                        {
                            flagship=1;
                        }
                        else
                        {
                            flagship=0;
                            break;
                        }
                    }
                    if(flagship==1)
                    {
                        //System.out.println(i);
                        realsolution=(long)(realsolution+(long)i);
                    }
                }
            }        
        }
        System.out.println(realsolution);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}