import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int[] factorial=new int[10];
        factorial[0]=1;
        for(int i=1;i<=9;i++)
        {
            factorial[i]=factorial[i-1]*i;
        }
        int number;
        int num,addupvalue,realsolution=0;
        int temp;
        Scanner in=new Scanner(System.in);
        number=in.nextInt();
        for(int i=10;i<=number;i++)
        {
            num=i;
            addupvalue=0;
            while(num>0)
            {
                temp=num%10;
                addupvalue=addupvalue+factorial[temp];
                num=num/10;
            }
            if(addupvalue%i==0)
            {
                realsolution=realsolution+i;
            }
        }
        System.out.println(realsolution);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}