import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class TempleOfSnakes
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int numberOfSections = in.nextInt();
            int[] sectionHeight = new int[numberOfSections];
            ArrayList<Integer> onePositionList = new ArrayList<Integer>();
            ArrayList<Long> heightsBetweenOnesPositionList = new ArrayList<Long>();
            ArrayList<Integer> numberOfInbetweenSectionsList = new ArrayList<Integer>();
            int numberOfInbetweenSections = 0;
            int totalHeightBetweenOnes = 0;
            int endHeight = 0;
            /*
            for(int j = 0; j < numberOfSections; j++)
            {
                sectionHeight[j] = in.nextInt();
                if(sectionHeight[j] == 1)
                {
                    onePositionList.add(j);
                    heightsBetweenOnesPositionList.add(totalHeightBetweenOnes);
                    numberOfInbetweenSectionsList.add(numberOfInbetweenSections);
                    numberOfInbetweenSections = 0;
                    totalHeightBetweenOnes = 0;
                }
                else if (j == (numberOfSections - 1))
                {
                    totalHeightBetweenOnes = totalHeightBetweenOnes + sectionHeight[j];
                    numberOfInbetweenSections = numberOfInbetweenSections + 1;
                    numberOfInbetweenSectionsList.add(numberOfSections);
                    heightsBetweenOnesPositionList.add(totalHeightBetweenOnes);
                    endHeight = totalHeightBetweenOnes;
                }
                else
                {
                    numberOfInbetweenSections = numberOfInbetweenSections + 1;
                    totalHeightBetweenOnes = totalHeightBetweenOnes + sectionHeight[j];
                }
            }
            */
            long totalSum = 0;
            for(int j = 0; j <= numberOfSections; j++)
            {
                sectionHeight[j] = in.nextInt();
                totalSum = totalSum + (long)numberOfSections[j];
                if(sectionHeight[j] == 1)
                {
                    onePositionList.add(j);
                }
            }
            int count = onePositionList.size();
            Integer[] onePositionArray = onePositionList.toArray(new Integer[onePositionList.size()]);
            int minimumReductions = 0;
            if(count>0)
            {
                if(numberOfSections % 2 == 1)
                {
                    int n = numberOfSections / 2;
                    n = n + 1;
                    minimumReductions = ((n * (n + 1))/2);
                    minimumReductions = minimumReductions + (int)(((n-1) * n)/2);
                }
                else
                {
                    int maximum = 0;
                    for(int k = 0; k < count; k++)
                    {
                        if(k == 0)
                        {
                            maximum = onePositionArray[k];
                        }
                        else
                        {
                            int temporary = onePositionArray[k] - onePositionArray[k - 1] + 1;
                            if(temporary > maximum)
                            {
                                maximum = temporary;
                            }
                        }
                    }
                    int n = numberOfSections / 2;
                    minimumReductions = (n * (n + 1)) / 2;
                    minimumReductions = minimumReductions + (((n - 1)* n) / 2);
                }
            }
        }
    }
}
