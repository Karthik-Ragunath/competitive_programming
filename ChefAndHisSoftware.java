import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class ChefAndHisSoftwareHeap
{
    public static void minHeapify(int[] minHeap, int size)
    {
        while((size / 2) >= 1)
        {
            if(minHeap[size / 2] > minHeap[size])
            {
                int temp = minHeap[size / 2];
                minHeap[size / 2] = minHeap[size];
                minHeap[size] = temp;
                size = size / 2;
            }
            else
            {
                break;
            }
        }
    }

    public static void minHeapifySaturated(int[] minHeap, int element, int size)
    {
        if(element > minHeap[1])
        {
            int tempSize = size - 1;
            minHeap[1] = minHeap[size];
            minHeap[size] = element;
            int currentIndex = 1;
            while((2 * currentIndex) <= tempSize)
            {
                if((2 * currentIndex + 1) <= tempSize)
                {
                    if(minHeap[2 * currentIndex] > minHeap[2 * currentIndex + 1])
                    {
                        if(minHeap[currentIndex] > minHeap[2 * currentIndex + 1])
                        {
                            int tempElement = minHeap[currentIndex];
                            minHeap[currentIndex] = minHeap[2 * currentIndex + 1];
                            minHeap[2 * currentIndex + 1] = tempElement;
                            currentIndex = 2 * currentIndex + 1;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        if(minHeap[currentIndex] > minHeap[2 * currentIndex])
                        {
                            int tempElement = minHeap[currentIndex];
                            minHeap[currentIndex] = minHeap[2 * currentIndex];
                            minHeap[2 * currentIndex] = tempElement;
                            currentIndex = 2 * currentIndex;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if(minHeap[currentIndex] > minHeap[2 * currentIndex])
                    {
                        int tempElement = minHeap[currentIndex];
                        minHeap[currentIndex] = minHeap[2 * currentIndex];
                        minHeap[2 * currentIndex] = tempElement;
                        currentIndex = 2 * currentIndex;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            minHeapify(minHeap, size);
        }
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int minHeapSize;
            int numberOfInsertions;
            minHeapSize = in.nextInt();
            numberOfInsertions = in.nextInt();
            int[] minHeap = new int[minHeapSize + 1];
            minHeap[0] = -1;
            for(int j = 1; j <= numberOfInsertions; j++)
            {
                int element = in.nextInt();
                if(j < minHeapSize)
                {
                    minHeap[j] = element;
                    minHeapify(minHeap, j);
                    System.out.print("-1 ");
                }
                else if (j == minHeapSize)
                {
                    minHeap[j] = element;
                    minHeapify(minHeap, j);
                    System.out.print(minHeap[1] + " ");
                }
                else
                {
                    minHeapifySaturated(minHeap, element, minHeapSize);
                    System.out.print(minHeap[1] + " ");
                }
            }
            System.out.println();
        }
    }
}
