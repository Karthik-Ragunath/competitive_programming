import java.io.*;
import java.lang.*;
import java.util.*;
import java.text.*;
import java.math.*;
class Solution{
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int testcases;
        testcases=in.nextInt();
        in.nextLine();
        for(int k=0;k<testcases;k++)
        {
            String newstring;
            newstring=in.nextLine();
            int length=newstring.length();
            //System.out.println(length);
            char[] inputarray=newstring.toCharArray();
            Stack balance_paranthesis=new Stack();
            int flagship=1;
            int length1=0;
            for(int i=0;i<length;i++)
            {
                if((inputarray[i]=='(')||(inputarray[i]=='[')||(inputarray[i]=='{'))
                {
                    balance_paranthesis.push(inputarray[i]);
                }
                else
                {
                    if(balance_paranthesis.empty()==true)
                    {
                        flagship=0;
                        break;
                    }
                    char tester=(char)balance_paranthesis.pop();
                    if((inputarray[i]==')')&&(tester!='('))
                    {
                        flagship=0;
                        break;
                    }
                    if((inputarray[i]==']')&&(tester!='['))
                    {
                        flagship=0;
                        break;
                    }
                    if((inputarray[i]=='}')&&(tester!='{'))
                    {
                        flagship=0;
                        break;
                    }
                    
                    length1++;
                }
            }
            if((flagship==1)&&(length1==(length/2)))
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
    } 
}