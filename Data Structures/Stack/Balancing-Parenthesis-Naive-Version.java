import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
public class Solution {

    public static void main(String[] args) {
        String input;
        Scanner in=new Scanner(System.in);
        int testcases;
        testcases=in.nextInt();
        in.nextLine();
        for(int k=0;k<testcases;k++)
        {
            input=in.next();
            //System.out.println(input);
            int length;
            length=input.length();
            if(length%2!=0)
            {
                System.out.println("NO");
                continue;
            }
            char[] characterinput=input.toCharArray();
            int flagship=1;
            int j=length-1;
            for(int i=0;i<length/2;i++)
            {
                //System.out.println(i+" "+j);
                //System.out.println(characterinput[i]+" "+characterinput[j]);
                if(characterinput[i]=='{')
                {
                    if(characterinput[j]!='}')
                    {
                        flagship=0;
                        break;
                    }
                }
                if(characterinput[i]=='[')
                {
                    if(characterinput[j]!=']')
                    {
                        flagship=0;
                        break;
                    }
                }
                if(characterinput[i]=='(')
                {
                    if(characterinput[j]!=')')
                    {
                        flagship=0;
                        break;
                    }
                }
                j--;
            }
            if(flagship==1)
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}