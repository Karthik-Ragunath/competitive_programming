import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class SnakeVsMongoose
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int testcases;
        testcases = in.nextInt();
        in.nextLine();
        for(int i = 0; i < testcases; i++)
        {
            String input = in.nextLine();
            int length = input.length();
            int snakeLength = 0;
            int mongooseLength = 0;
            boolean[] snakeAliveChecker = new boolean[length];

            for(int j = 0; j < length; j++)
            {
                if(input.charAt(j) == 's')
                {
                    snakeLength = snakeLength + 1;
                }
                else
                {
                    mongooseLength = mongooseLength + 1;
                    if(j == 0 && j == (length - 1))
                    {
                        continue;
                    }
                    if(j != 0 && j != (length - 1))
                    {
                        if(input.charAt(j - 1) == 's' && snakeAliveChecker[j - 1] == false)
                        {
                            snakeAliveChecker[j - 1] = true;
                            snakeLength = snakeLength - 1;
                        }
                        else if(input.charAt(j + 1) == 's' && snakeAliveChecker[j + 1] == false)
                        {
                            snakeAliveChecker[j + 1] = true;
                            snakeLength = snakeLength - 1;
                        }

                    }
                    else if(j == 0 )
                    {
                        if(input.charAt(j + 1) == 's' && snakeAliveChecker[j + 1] == false)
                        {
                            snakeAliveChecker[j + 1] = true;
                            snakeLength = snakeLength - 1;
                        }
                    }
                    else if(j == (length - 1))
                    {
                        if(input.charAt(j - 1) == 's' && snakeAliveChecker[j - 1] == false)
                        {
                            snakeAliveChecker[j - 1] = true;
                            snakeLength = snakeLength - 1;
                        }
                    }
                }
            }
            //System.out.println("Snake: " + snakeLength + " MongooseLength: " + mongooseLength);
            if(snakeLength > mongooseLength)
            {
                System.out.println("snakes");
            }
            else if(mongooseLength > snakeLength)
            {
                System.out.println("mongooses");
            }
            else
            {
                System.out.println("tie");
            }
        }
    }
}
