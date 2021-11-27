import java.lang.*;
import java.util.*;
import java.io.*;
class Solution{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		boolean flagship=false;
		String input;
		while(in.hasNext())
		{
			if(flagship==true)
			{
				System.out.print(";");
			}
            flagship=true;
			input=in.next();
			System.out.print(input);
			input=in.next();
			System.out.print(" "+input);
		}
	}
}	