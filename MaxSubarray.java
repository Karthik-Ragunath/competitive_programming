import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class MaxSubarray
{
    public static int[] merge(int[] globalMax, int[] currentMax, int numberOfTerms)
    {
        int globalMaxIndex = 0;
        int currentMaxIndex = 0;
        int returnArrayIndex = 0;
        for(int i = 0; i < numberOfTerms; i++)
        {
            if(currentMax[currentMaxIndex] > globalMax[globalMaxIndex])
            {
                returnArrayIndex[i] = currentMax[currentMaxIndex++];
            }
            else
            {
                returnArrayIndex[i] = globalMax[globalMaxIndex++];
            }
        }
        return returnArrayIndex;
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int l = 0; l < testcases; l++)
        {
            int numberOfTerms, k1, k2, k3;
            numberOfTerms = in.nextInt();
            int maxOfK = Math.max(Math.max(k1, k2), k3);
            int[] prefixSumArray = new int[numberOfTerms + 1];
            int[] terms = new int[numberOfTerms + 1];
            int[] globalMax = new int[maxOfK];
            int[] currentMax = new int[maxOfK];
            int sum = 0;
            prefixSumArray[0] = 0;
            for(int i = 0; i < numberOfTerms; i++)
            {
                terms[i + 1] = in.nextInt();
                prefixSumArray[i + 1] = prefixSubArray[i] + terms[i + 1];
            }
            for(int i = 1; i <= numberOfTerms; i++)
            {
                int[] currentMax = new int[maxOfK];
                for(int j = 0; j < maxOfK; j++)
                {
                    if(i - j > 0)
                    {
                        //currentMax[j] = prefixSumArray[i] - prefixSumArray[i - j];
                        
                        // Insertion Sort
                        currentMax[j] = prefixSumArray[i] - prefixSumArray[i - j];
                        for(int k = 0; k < j; k++)
                        {
                            if(currentMax[k] > currentMax[j])
                            {
                                break;
                            }
                            else
                            {
                                int temp = currentMax[j];
                                currentMax[j] = currentMax[k];
                                currentMax[k] = temp;
                            }
                        }
                    }
                }
                //Arrays.sort(currentMax);
                globalMax = merge(globalMax, currentMax, maxOfK);
            }
            System.out.println(globalMax[k1] + " " + globalMax[k2] + " " + globalMax[k3]);
        }
    }
}
