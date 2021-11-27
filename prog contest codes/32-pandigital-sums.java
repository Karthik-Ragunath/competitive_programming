import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
public class Solution {

    public static void main(String[] args) {
        int length;
        int realsolution=0;
        Scanner in=new Scanner(System.in);
        length=in.nextInt();
        Set<Integer> distinctvalues=new HashSet<Integer>();
        int flag;
        for(int i=1;i<=4999;i++)
        {
            flag=1;
            for(int j=1;j<=4999;j++)
            {
                int product=i*j;
                String s1=String.valueOf(product);
                String s2=String.valueOf(j);
                String s3=String.valueOf(i);
                String s4=s1+s2+s3;
                int duplicate;
                duplicate=s4.length();
                if((duplicate>length)&&(j==1))
                {
                    flag=0;
                    break;
                }
                if(duplicate>length)
                {
                    break;
                }
                if(length==duplicate)
                {
                    Set<Integer> distinctterms=new HashSet<Integer>();
                    int duplicatenumber=Integer.parseInt(s4);
                    while(duplicatenumber>0)
                    {
                        int temp=duplicatenumber%10;
                        distinctterms.add(temp);
                        duplicatenumber=duplicatenumber/10;
                    }
                    
                    if(distinctterms.size()==length)
                    {
                        Iterator loopy=distinctterms.iterator();
                        int tester=1;
                        int testerflag=1;
                        while(loopy.hasNext())
                        {
                            int duplicate2=(int)loopy.next();
                            if(tester!=duplicate2)
                            {
                                testerflag=0;
                                break;
                            }
                            tester++;
                        }
                        if(testerflag==1)
                        {
                            distinctvalues.add(product);
                        }
                        
                        
                    }
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        Iterator amazed=distinctvalues.iterator();
        while(amazed.hasNext())
        {
            realsolution=realsolution+(int)amazed.next();
        }
        System.out.println(realsolution);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}