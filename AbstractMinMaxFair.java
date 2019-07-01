import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class AbstractMinMaxFair
{
    public static void minHeapify(ArrayList<Integer> minHeap, int minHeapSize)
    {
        int i = minHeapSize;
        while(i > 1)
        {
            if(minHeap.get(i) < minHeap.get(i / 2))
            {
                Collections.swap(minHeap, i, i / 2);
                i = i / 2;
                continue;
            }
            else
            {
                break;
            }
        }
    }

    public static void maxHeapify(ArrayList<Integer> maxHeap, int maxHeapSize)
    {
        int i = maxHeapSize;
        while(i > 1)
        {
            if(maxHeap.get(i) > maxHeap.get(i / 2))
            {
                Collections.swap(maxHeap, i, i / 2);
                i = i / 2;
                continue;
            }
            else
            {
                break;
            }
        }
    }

    public static void minHeapifyAfterDeletion(ArrayList<Integer> minHeap, int minHeapSize)
    {
        int i = 1;
        while((2 * i) <= minHeapSize)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if(rightIndex <= minHeapSize)
            {
                if(minHeap.get(rightIndex) <= minHeap.get(leftIndex))
                {
                    if(minHeap.get(i) > minHeap.get(rightIndex))
                    {
                        Collections.swap(minHeap, i, rightIndex);
                        i = rightIndex;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(minHeap.get(i) > minHeap.get(leftIndex))
                    {
                        Collections.swap(minHeap, i, leftIndex);
                        i = leftIndex;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(minHeap.get(i) > minHeap.get(leftIndex))
                {
                    Collections.swap(minHeap, i, leftIndex);
                    i = leftIndex;
                }
                else
                {
                    break;
                }
            }
        }
    }

    public static void maxHeapifyAfterDeletion(ArrayList<Integer> maxHeap, int maxHeapSize)
    {
        int i = 1;
        while((2 * i) <= maxHeapSize)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if(rightIndex <= maxHeapSize)
            {
                if(maxHeap.get(rightIndex) >= maxHeap.get(leftIndex))
                {
                    if(maxHeap.get(i) < maxHeap.get(rightIndex))
                    {
                        Collections.swap(maxHeap, i, rightIndex);
                        i = rightIndex;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(maxHeap.get(i) < maxHeap.get(leftIndex))
                    {
                        Collections.swap(maxHeap, i, leftIndex);
                        i = leftIndex;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if(maxHeap.get(i) < maxHeap.get(leftIndex))
                {
                    Collections.swap(maxHeap, i, leftIndex);
                    i = leftIndex;
                }
                else
                {
                    break;
                }
            }
        }
    }

    public static boolean buildMinMaxHeaps(ArrayList<Integer> minHeap, ArrayList<Integer> maxHeap, int valueToBeAdded, int minHeapSize, int maxHeapSize, int lowestValueOfMinHeap, int maximumValueOfMaxHeap)
    {
        int totalSize = minHeapSize + maxHeapSize + 1; //+1 indicates the size after adding the value to be added
        int oneThird = totalSize / 3;
        if(oneThird <= minHeapSize)
        {
            if(valueToBeAdded <= lowestValueOfMinHeap)
            {
                maxHeap.add(valueToBeAdded);
                maxHeapSize++;
                if(maxHeapSize == 1)
                {
                    return true;
                }
                else
                {
                    maxHeapify(maxHeap, maxHeapSize);
                }
            }
            else
            {
                Collections.swap(minHeap, minHeapSize, 1);
                minHeap.remove(minHeapSize);
                minHeapSize--;
                minHeapifyAfterDeletion(minHeap, minHeapSize);
                minHeap.add(valueToBeAdded);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize);
                maxHeap.add(lowestValueOfMinHeap);
                maxHeapSize++;
                maxHeapify(maxHeap, maxHeapSize);
            }
            return true;
        }
        else
        {
            if(valueToBeAdded >= maximumValueOfMaxHeap)
            {
                minHeap.add(valueToBeAdded);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize);
            }
            else
            {
                Collections.swap(maxHeap, 1, maxHeapSize);
                maxHeap.remove(maxHeapSize);
                maxHeapSize--;
                maxHeapifyAfterDeletion(maxHeap, maxHeapSize);
                maxHeap.add(valueToBeAdded);
                maxHeapSize++;
                maxHeapify(maxHeap, maxHeapSize);
                minHeap.add(maximumValueOfMaxHeap);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize);
            }
            return false;
        }
    }

    public static void main(String[] args)
    {
        int queries;
        int minHeapSize = 0;
        int maxHeapSize = 0;
        int lowestValueOfMinHeap = 1000000009;
        int highestValueOfMaxHeap = -1;
        Scanner in = new Scanner(System.in);
        queries = in.nextInt();
        ArrayList<Integer> minHeap = new ArrayList<Integer>();
        ArrayList<Integer> maxHeap = new ArrayList<Integer>();
        minHeap.add(-1);
        maxHeap.add(-1);
        //Default values are added to minHeap and maxHeap arrays inorder to simplify the process of maintaining relationship between parent and child indices.
        for(int i = 0; i < queries; i++)
        {
            int queryType = in.nextInt();
            if(queryType == 1)
            {
                int valueToBeAdded = in.nextInt();
                boolean maxHeapSizeExtended = buildMinMaxHeaps(minHeap, maxHeap, valueToBeAdded, minHeapSize, maxHeapSize, lowestValueOfMinHeap, highestValueOfMaxHeap);//true indicates that maxHeap size is increamented by one and false indicates that minHeap size is increamented by 1
                if(maxHeapSizeExtended)
                {
                    maxHeapSize++;
                }
                else
                {
                    minHeapSize++;
                }
                if(minHeapSize >= 1)
                {
                    lowestValueOfMinHeap = minHeap.get(1);
                }
                if(maxHeapSize >= 1)
                {
                    highestValueOfMaxHeap = maxHeap.get(1);
                }
            }
            else
            {
                if(minHeapSize >= 1)//Indicates that 1/3 rd element (because -1 is defaultly added as 1st element and hence min size needs to be four for atleast 1 element to be in top 1/3rd portion) is atleast 1.
                {
                    System.out.println(minHeap.get(1));
                }
                else
                {
                    System.out.println("No reviews yet");
                }
            }
        }
    }
}
