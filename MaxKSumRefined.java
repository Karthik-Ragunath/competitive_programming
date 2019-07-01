import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class MaxSubarray
{
    public static int[] merge(int[] globalMax, int[] currentMax, int numberOfTerms, int globalMaxIndexPosition, int currentMaxIndexPosition)
    {
        int[] returnArray = new int[numberOfTerms];
        if(globalMaxIndexPosition >= numberOfTerms)
        {
            int globalMaxIndex = 0;
            int currentMaxIndex = 0;
            for(int i = 0; i < numberOfTerms; i++)
            {
                if(currentMax[currentMaxIndex] > globalMax[globalMaxIndex])
                {
                    returnArray[i] = currentMax[currentMaxIndex++];
                    if(currentMaxIndex >= currentMaxIndexPosition)
                    {
                        for(int j = i + 1; j < numberOfTerms; j++)
                        {
                            returnArray[j] = globalMax[globalMaxIndex++];
                        }
                        break;
                    }
                }
                else
                {
                    returnArray[i] = globalMax[globalMaxIndex++];
                }
            }
        }
        else
        {
            if(globalMaxIndexPosition < currentMaxIndexPosition)
            {
                int globalMaxIndex = 0;
                int currentMaxIndex = 0;
                if(globalMaxIndexPosition == 0)
                {
                    for(int i = 0; i < currentMaxIndexPosition; i++)
                    {
                        returnArray[i] = currentMax[i];
                    }
                }
                else
                {
                    for(int i = 0; i < numberOfTerms; i++)
                    {
                        if(currentMax[currentMaxIndex] > globalMax[globalMaxIndex])
                        {
                            returnArray[i] = currentMax[currentMaxIndex++];
                            if(currentMaxIndex >= currentMaxIndexPosition)
                            {
                                for(int j = i + 1; j < numberOfTerms; j++)
                                {
                                    if(globalMaxIndex < globalMaxIndexPosition)
                                    {
                                        returnArray[j] = globalMax[globalMaxIndex++];
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        else
                        {
                            returnArray[i] = globalMax[globalMaxIndex++];
                            if(globalMaxIndex >= globalMaxIndexPosition)
                            {
                                for(int j = i + 1; j < numberOfTerms; j++)
                                {
                                    if(currentMaxIndex < currentMaxIndexPosition)
                                    {
                                        returnArray[j] = currentMax[currentMaxIndex++];
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                int globalMaxIndex = 0;
                int currentMaxIndex = 0;
                for(int i = 0; i < numberOfTerms; i++)
                {
                    if(currentMax[currentMaxIndex] > globalMax[globalMaxIndex])
                    {
                        returnArray[i] = currentMax[currentMaxIndex++];
                        if(currentMaxIndex >= currentMaxIndexPosition)
                        {
                            for(int j = i + 1; j < numberOfTerms; j++)
                            {
                                if(globalMaxIndex < globalMaxIndexPosition)
                                {
                                    returnArray[j] = globalMax[globalMaxIndex++];
                                }
                                else
                                {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    else
                    {
                        returnArray[i] = globalMax[globalMaxIndex++];
                        if(globalMaxIndex >= globalMaxIndexPosition)
                        {
                            for(int j = i + 1; j < numberOfTerms; j++)
                            {
                                if(currentMaxIndex < currentMaxIndexPosition)
                                {
                                    returnArray[j] = currentMax[currentMaxIndex++];
                                }
                                else
                                {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
        return returnArray;
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
            k1 = in.nextInt();
            k2 = in.nextInt();
            k3 = in.nextInt();
            int maxOfK = Math.max(Math.max(k1, k2), k3);
            int[] prefixSumArray = new int[numberOfTerms + 1];
            int[] terms = new int[numberOfTerms + 1];
            int[] globalMax = new int[maxOfK];
            int sum = 0;
            prefixSumArray[0] = 0;
            for(int i = 0; i < numberOfTerms; i++)
            {
                terms[i + 1] = in.nextInt();
                prefixSumArray[i + 1] = prefixSumArray[i] + terms[i + 1];
            }
            int globalMaxIndexPosition = 0;
            for(int i = 1; i <= numberOfTerms; i++)
            {
                int[] currentMax = new int[maxOfK];
                int currentMaxIndexPosition = 0;
                int tempGlobalMaxIndexPosition = 0;
                for(int j = 1; j <= maxOfK; j++)
                {
                    if(i - j >= 0)
                    {
                        //currentMax[j] = prefixSumArray[i] - prefixSumArray[i - j];

                        // Insertion Sort
                        tempGlobalMaxIndexPosition++;
                        currentMaxIndexPosition++;
                        currentMax[j - 1] = prefixSumArray[i] - prefixSumArray[i - j];
                        for(int k = j - 1; k >= 1; k--)
                        {
                            if(currentMax[k - 1] > currentMax[k])
                            {
                                break;
                            }
                            else
                            {
                                int temp = currentMax[k - 1];
                                currentMax[k - 1] = currentMax[k];
                                currentMax[k] = temp;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                //Arrays.sort(currentMax);
                globalMax = merge(globalMax, currentMax, maxOfK, globalMaxIndexPosition, currentMaxIndexPosition);
                globalMaxIndexPosition += tempGlobalMaxIndexPosition;
            }
            System.out.println(globalMax[k1 - 1] + " " + globalMax[k2 - 1] + " " + globalMax[k3 - 1]);
        }
    }
}
