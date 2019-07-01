import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Solution
{   
    int stepCounter(int input)
    {
        int temp = 0;
        if(input >= 5)
        {
            temp = temp + (input / 5);
            input = input % 5;
        }
        if(input >= 2)
        {
            temp = temp + (input / 2);
            input = input % 2;
        }
        temp = temp + input;
        return temp;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        for(int k = 0; k < testcases; k++)
        {
            int numberOfColleagues = in.nextInt();
            int[] numberOfChocolates = new int[numberOfColleagues];
            int minimum = 0;
            for(int i = 0; i < numberOfColleagues; i++)
            {
                numberOfChocolates[i] = in.nextInt();
                if(i == 0)
                {
                    minimum = numberOfChocolates[i];
                }
                else
                {
                    if(numberOfChocolates[i] < minimum)
                    {
                        minimum = numberOfChocolates[i];
                    }
                }
            }
            int solution = 0;
            for(int j = 0; j < 5; j++)
            {
                int totalSteps = 0;
                for(int i = 0; i < numberOfColleagues; i++)
                {
                    int numberOfReductionsToBeMade = numberOfChocolates[i] - minimum + j;
                    int countOfStepsToReachTheMinimum = new Solution().stepCounter(numberOfReductionsToBeMade);
                    totalSteps = totalSteps + countOfStepsToReachTheMinimum;
                }
                if(j == 0)
                {
                    solution = totalSteps;
                }
                else
                {
                    if(totalSteps < solution)
                    {
                        solution = totalSteps;
                    }
                }
            }
            System.out.println(solution);
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}
