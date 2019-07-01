import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class TransitionToSocialism
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int rows = in.nextInt();
            int columns = in.nextInt();
            int[][] inputArray = new int[rows][columns];
            ArrayList<Integer> maxValuePositions = new ArrayList<Integer>();
            int maximum = 0;
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0; k < columns; k++)
                {
                    inputArray[j][k] = in.nextInt();
                    if(j == 0 && k == 0)
                    {
                        maximum = inputArray[j][k];
                        int maxPosition = j * columns + k;
                        maxValuePositions.add(maxPosition);
                    }
                    else
                    {
                        if(inputArray[j][k] > maximum)
                        {
                            maximum = inputArray[j][k];
                            maxValuePositions.clear();
                            int maxPosition = j * columns + k;
                            maxValuePositions.add(maxPosition);
                        }
                        else if(inputArray[j][k] == maximum)
                        {
                            int maximumPosition = j * columns + k;
                            maxValuePositions.add(maximumPosition);
                        }
                    }
                }
            }
            Integer[] maxValuePositionsArray = maxValuePositions.toArray(new Integer[maxValuePositions.size()]);
            int minimumDifference = 0;
            boolean flagship = false;
            for(int j = 0; j < rows; j++)
            {
                for(int k = 0; k < columns; k++)
                {
                    if(inputArray[j][k] != maximum)
                    {
                        for(int l = 0; l < maxValuePositions.size(); l++)
                        {
                            int rowPosition = ((int)(maxValuePositionsArray[l]) / columns);
                            int columnPosition = ((int)(maxValuePositionsArray[l]) % columns);
                            int rowDifference = Math.abs(rowPosition - j);
                            int columnDifference = Math.abs(columnPosition - k);
                            int difference = Math.max(rowDifference, columnDifference);
                            if(flagship == false)
                            {
                                minimumDifference = difference;
                            }
                            else if(difference < minimumDifference)
                            {
                                minimumDifference = difference;
                            }
                        }
                    }
                }
            }
            System.out.println(minimumDifference);
        }
    }
}
