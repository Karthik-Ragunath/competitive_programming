import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class SnakeProcession
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfReports = in.nextInt();
        for (int i = 0; i < numberOfReports; i++)
        {
            int length = in.nextInt();
            in.nextLine();
            String present = in.nextLine();
            char toExist = 'H';
            boolean answer = true;
            for(int j = 0; j < length; j++)
            {
                if (present.charAt(j) == '.')
                {
                    continue;
                }
                else if (present.charAt(j) == toExist)
                {
                    if (toExist == 'T')
                    {
                        toExist = 'H';
                    }
                    else
                    {
                        toExist = 'T';
                    }
                }
                else
                {
                    answer = false;
                    break;
                }
            }
            if (answer == true && toExist == 'H')
            {
                System.out.println("Valid");
            }
            else
            {
                System.out.println("Invalid");
            }
        }
    }
}
