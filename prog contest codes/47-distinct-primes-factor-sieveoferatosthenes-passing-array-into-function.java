import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
public class Solution {
    int noofdivisors(int num,int[] primearray)
    {
        int reminder,nod=0,p;
        reminder=num;
        for(int i=0;;i++)
        {
            if(reminder==1)
            {
                return nod;
            }
            p=primearray[i]*primearray[i];
            if(p>reminder)
            {
                nod=nod+1;
                return nod;
            }
            boolean divisorfound=false;
            while(reminder%primearray[i]==0)
            {
                divisorfound=true;
                reminder=reminder/primearray[i];
            }
            if(divisorfound==true)
            {
                nod=nod+1;
            }
        }
    }

    public static void main(String[] args) {
        int inputnumber,consequtive;
        Scanner in=new Scanner(System.in);
        inputnumber=in.nextInt();
        consequtive=in.nextInt();
        int upperbound=inputnumber+consequtive-1;
        int sievebound=(int)((upperbound-1)/2);
        int uppersqrt=(((int)Math.sqrt(upperbound)-1)/2);
        boolean[] primebits=new boolean[sievebound+1];
        Arrays.fill(primebits,true);
        for(int i=1;i<=uppersqrt;i++)
        {
            if(primebits[i]==true)
            {
                for(int j=(2*i*(i+1));j<=sievebound;j+=((2*i)+1))
                {
                    primebits[j]=false;
                }
            }
        }
        ArrayList<Integer> primelist=new ArrayList<Integer>();
        primelist.add(2);
        for(int i=1;i<=sievebound;i++)
        {
            if(primebits[i]==true)
            {
                primelist.add(2*i+1);
            }
        }
        Integer[] primearray1=primelist.toArray(new Integer[primelist.size()]);
        int[] primearray=new int[primelist.size()];
        for(int i=0;i<(primelist.size());i++)
        {
            primearray[i]=(int)primearray1[i];
        }
        int[] numberofdivisors=new int[upperbound+1];
        for(int i=2;i<=upperbound;i++)
        {
            numberofdivisors[i]=new Solution().noofdivisors(i,primearray);
        }
        for(int i=2;i<=inputnumber;i++)
        {
            boolean consequtivechecker=false;
            if(numberofdivisors[i]==consequtive)
            {
                consequtivechecker=true;
                for(int j=i+1;j<=(i+consequtive-1);j++)
                {
                    if(numberofdivisors[j]!=consequtive)
                    {
                        consequtivechecker=false;
                        i=j;
                        break;
                    }
                }
                if(consequtivechecker==true)
                {
                    System.out.println(i);
                }
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}