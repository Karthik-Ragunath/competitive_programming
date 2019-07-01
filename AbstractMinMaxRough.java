import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class AbstractMinMaxRough
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
                System.out.println("LeftIndex and RightIndex : " + leftIndex + " " + rightIndex);
                System.out.println("LeftValue : " + maxHeap.get(leftIndex) + " RightValue : " + maxHeap.get(rightIndex));
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
                System.out.println("MaxHeapify after deletion-" + " i : " + i + " leftIndex : " + leftIndex);
                System.out.println("i and leftValues : " + maxHeap.get(i) + " " + maxHeap.get(leftIndex));
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
        System.out.println("-------------New Addition--------------");
        int totalSize = minHeapSize + maxHeapSize + 1; //+1 indicates the size after adding the value to be added
        System.out.println("Total Size: " + totalSize);
        int oneThird = totalSize / 3;
        System.out.println("One Third: " + oneThird);
        if(oneThird <= minHeapSize)
        {
            System.out.println("MinHeap size less than one third");
            if(valueToBeAdded <= lowestValueOfMinHeap)
            {
                maxHeap.add(valueToBeAdded);
                maxHeapSize++;
                if(maxHeapSize == 1)
                {
                    System.out.println("MaxHeap size is 1");
                    return true;
                }
                else
                {
                    maxHeapify(maxHeap, maxHeapSize);
                    System.out.println("MaxHeapSize: " + maxHeapSize);
                }
            }
            else
            {
                System.out.println("Min value removed from minHeap and placed in maxHeap and new value is added to minHeap");
                System.out.println("MinHeap size: " + minHeapSize);
                Collections.swap(minHeap, minHeapSize, 1);
                System.out.println("Value to be removed: " + minHeap.get(minHeapSize));
                minHeap.remove(minHeapSize);
                minHeapSize--;
                System.out.println("Min Heap size: " + minHeapSize);
                minHeapifyAfterDeletion(minHeap, minHeapSize);
                if(minHeapSize >= 1)
                {
                    System.out.println("MinHeap value after deleting: " + minHeap.get(1));
                }
                else
                {
                    System.out.println("MinHeap size is 0");
                }
                minHeap.add(valueToBeAdded);
                System.out.println("New value to be added: " + valueToBeAdded);
                minHeapSize++;
                System.out.println("MinHeap size: " + minHeapSize);
                minHeapify(minHeap, minHeapSize);
                System.out.println("Min value of MinHeap: " + minHeap.get(1));
                System.out.println("Max Heap size before adding Prev min value from MinHeap: " + maxHeapSize);
                maxHeap.add(lowestValueOfMinHeap);
                maxHeapSize++;
                System.out.println("MaxHeap size after adding value: " + maxHeapSize);
                maxHeapify(maxHeap, maxHeapSize);
                System.out.println("Max value Now: " + maxHeap.get(1));
            }
            return true;
        }
        else
        {
            System.out.println("Value going to be added in MinHeap");
            if(valueToBeAdded >= maximumValueOfMaxHeap)
            {
                System.out.println("Value greater than maximum value of maxHeap");
                minHeap.add(valueToBeAdded);
                System.out.println("Value to be added: " + valueToBeAdded);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize);
                System.out.println("Mean HeapSize: " + minHeapSize);
            }
            else
            {
                System.out.println("Max value removed from maxHeap and placed in minheap and new value is added to maxHeap");
                System.out.println("MaxHeap size: " + maxHeapSize);
                Collections.swap(maxHeap, 1, maxHeapSize);
                System.out.println("Value to be removed: " + maxHeap.get(maxHeapSize));
                maxHeap.remove(maxHeapSize);
                maxHeapSize--;
                System.out.println("Max Heap size: " + maxHeapSize);
                maxHeapifyAfterDeletion(maxHeap, maxHeapSize);
                if(maxHeapSize >= 1)
                {
                    System.out.println("MaxHeap value after deleting: " + maxHeap.get(1));
                }
                else
                {
                    System.out.println("MaxHeap size is 0");
                }
                maxHeap.add(valueToBeAdded);
                System.out.println("New value to be added: " + valueToBeAdded);
                maxHeapSize++;
                System.out.println("MaxHeap size: " + maxHeapSize);
                maxHeapify(maxHeap, maxHeapSize);
                System.out.println("Max value of MaxHeap: " + maxHeap.get(1));
                System.out.println("Min Heap size before adding Prev max value from MaxHeap: " + minHeapSize);
                minHeap.add(maximumValueOfMaxHeap);
                minHeapSize++;
                System.out.println("MinHeap size after adding value: " + minHeapSize);
                minHeapify(minHeap, minHeapSize);
                System.out.println("Min value Now: " + minHeap.get(1));
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
                System.out.println("--------Output--------");
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
