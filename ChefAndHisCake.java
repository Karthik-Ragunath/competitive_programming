import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class ChefAndHisCake
{
	public static void main(String[] args)
	{
		int testcases;
		Scanner in = new Scanner(System.in);
		testcases = in.nextInt();
		for(int i = 0; i < testcases; i++)
		{
			int rows = in.nextInt();
			int columns = in.nextInt();
			int[][] matrix = new int[rows][columns];
			for(int j = 0; j < rows; j++)
			{
                String input = in.next();
				for(int k = 0; k < columns; k++)
				{
                    if(input.charAt(k) == 'G')
                    {
                        matrix[j][k] = 1;
                    }
                    else
                    {
                        matrix[j][k] = 0;
                    }
				}
			}
			int checker = 0;
			int redInitially = 0;
			int greenInitially = 0;
			//Replacing red with green cost = 5
			//Replacing green with red cost = 3
			//Red Initially
			for(int j = 0; j < rows; j++)
			{
                if(j % 2 == 0)
                {
                    checker = 0;
                }
                else
                {
                    checker = 1;
                }
				for(int k = 0; k < columns; k++)
				{
					if(matrix[j][k] == checker)
					{
						checker = (checker + 1) % 2;
						continue;
					}
					else
					{
						if(checker == 0)
						{
                            System.out.println("Red Initially - checker 0 - j and k : " + j + " " + k);
							redInitially += 3;
						}
						else
						{
                            System.out.println("Red Initially - checker 1 - j and k : " + j + " " + k);
							redInitially += 5;
						}
						checker = (checker + 1) % 2;
					}
				}
			}
			//Green Initially
			checker = 1;
			for(int j = 0; j < rows; j++)
			{
				if(j % 2 == 0)
				{
                    checker = 1;
				}
                else
                {
                    checker = 0;
                }
				for(int k = 0; k < columns; k++)
				{
					if(matrix[j][k] == checker)
					{
						checker = (checker + 1) % 2;
						continue;
					}
					else
					{
						if(checker == 0)
						{
                            System.out.println("Green Initially - checker 0 - j and k : " + j + " " + k);
							greenInitially += 3;
						}
						else
						{
                            System.out.println("Green Initially - checker 1 - j and k : " + j + " " + k);
							greenInitially += 5;
						}
						checker = (checker + 1) % 2;
					}
				}
			}
			if(redInitially <= greenInitially)
			{
				System.out.println(redInitially);
			}
			else
			{
				System.out.println(greenInitially);
			}
		}
	}
}
