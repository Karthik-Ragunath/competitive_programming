import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution{
    public static void main(String[] args){
    
        int input;
        int output;
        Scanner in=new Scanner(System.in);
        input=in.nextInt();
        LinkedList firstjavalink=new LinkedList();
        for(int i=0;i<input;i++)
        {
            firstjavalink.add(i);
        }
        firstjavalink.addFirst(456);
        firstjavalink.addLast(123);
        Iterator firstlink=firstjavalink.iterator();
        while(firstlink.hasNext())
        {
            output=(int)firstlink.next();
            System.out.println(output);
        }
    }
}
