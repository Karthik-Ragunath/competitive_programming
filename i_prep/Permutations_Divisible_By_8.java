import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;
class Solution{
    int permute(char[] number_array,int length,int k)
    {
        if(k==length)
        {
            String number_string=String.valueOf(number_array);
            BigInteger number=new BigInteger(number_string);
            if(((number.mod(BigInteger.valueOf(8))).compareTo(BigInteger.valueOf(0)))==0)
            {
                return 1;
            }
        }
        else
        {
            for(int i=k;i<=length;i++)
            {
                char temp=number_array[k];
                number_array[k]=number_array[i];
                number_array[i]=temp;
                if(new Solution().permute(number_array,length,k+1)==1)
                {
                    return 1;
                }
                temp=number_array[k];
                number_array[k]=number_array[i];
                number_array[i]=temp;
            }
        }
        return 0;
    }
    void permutesfunc(String input)
    {
        int length=input.length()-1;
        int k=0;
        char[] input_array=input.toCharArray();
        int returner=new Solution().permute(input_array,length,k);
        if(returner==1)
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }
    public static void main(String[] args){
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        in.nextLine();
        for(int j=0;j<testcases;j++)
        {
            String input;
            input=in.nextLine();
            new Solution().permutesfunc(input);
        }
    }
}