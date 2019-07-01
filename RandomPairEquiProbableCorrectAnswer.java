import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class RandomPairEquiProbableCorrectAnswer
{
    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int l = 0; l < testcases; l++)
        {
            int numberOfTerms;
            numberOfTerms = in.nextInt();
            ArrayList<Integer> hashSet = new ArrayList<Integer>();
            int maxValue = 0;
            int maxValueCount = 0;
            for(int i = 0; i < numberOfTerms; i++)
            {
                int temp = in.nextInt();
                hashSet.add(temp);
                if(temp > maxValue)
                {
                    maxValue = temp;
                    maxValueCount = 1;
                }
                else if(temp == maxValue)
                {
                    maxValueCount++;
                }
            }
            double size = (double)hashSet.size();
            if(size == 1)
            {
                System.out.println("1.0000000");
            }
            else
            {
                if(maxValueCount != 1)
                {
                    double numberOfMax = maxValueCount - 1;
                    double combo = (numberOfMax * (numberOfMax + 1)) / 2;
                    double numberOfElements = size - 1;
                    double combinationsPossible = (numberOfElements * (numberOfElements + 1)) / 2;
                    double probability = combo / combinationsPossible;
                    probability = Double.parseDouble(String.format("%.6f", probability));
                    System.out.println(probability);
                }
                else
                {
                    double numberOfElements = size - 1;
                    double combinationsPossible = (numberOfElements * (numberOfElements + 1)) / 2;
                    double probability = 1 / combinationsPossible;
                    probability = Double.parseDouble(String.format("%.6f", probability));
                    System.out.println(probability);
                }
            }
        }
    }
}
