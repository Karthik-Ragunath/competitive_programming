import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class RestaurantRatingMaxMinHeaps
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
            int leftIndex = minHeap.get(2 * i);
            int rightIndex = minHeap.get(2 * i + 1);
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
            int leftIndex = maxHeap.get(2 * i);
            int rightIndex = maxHeap.get(2 * i + 1);
            if(rightIndex >= maxHeapSize)
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

    public static void buildMinHeap(ArrayList<Integer> minHeap, int minHeapSize)
    {
        if(minHeapSize == 2)
        {
            return;
        }
        else
        {
            minHeapify(minHeap, minHeapSize - 1);
        }
    }

    public static boolean buildMinMaxHeaps(ArrayList<Integer> minHeap, ArrayList<Integer> maxHeap, int valueToBeAdded, int minHeapSize, int maxHeapSize, int lowestValueOfMinHeap, int maximumValueOfMaxHeap)
    {
        int totalSize = minHeapSize + maxHeapSize + 1; //+1 indicates the size after adding the value to be added
        int oneThird = totalSize / 3;
        if(oneThird >= minHeapSize)
        {
            if(valueToBeAdded <= lowestValueOfMinHeap)
            {
                maxHeap.add(valueToBeAdded);
                maxHeapSize++;
                if(maxHeapSize == 2)
                {
                    return true;
                }
                else
                {
                    maxHeapify(maxHeap, maxHeapSize - 1);
                }
            }
            else
            {
                Collections.swap(minHeap, minHeapSize - 1, 1);
                minHeap.remove(minHeapSize - 1);
                minHeapSize--;
                minHeapifyAfterDeletion(minHeap, minHeapSize - 1);
                minHeap.add(valueToBeAdded);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize - 1);
                maxHeap.add(lowestValueOfMinHeap);
                maxHeapSize++;
                if(maxHeapSize == 2)
                {
                    return true;
                }
                else
                {
                    maxHeapify(maxHeap, maxHeapSize - 1);
                }
            }
            return true;
        }
        else
        {
            if(valueToBeAdded >= maximumValueOfMaxHeap)
            {
                minHeap.add(valueToBeAdded);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize - 1);
            }
            else
            {
                Collections.swap(maxHeap, 1, maxHeapSize - 1);
                maxHeap.remove(maxHeapSize - 1);
                maxHeapSize--;
                maxHeapifyAfterDeletion(maxHeap, maxHeapSize - 1);
                maxHeap.add(valueToBeAdded);
                maxHeapSize++;
                maxHeapify(maxHeap, maxHeapSize - 1);
                minHeap.add(maximumValueOfMaxHeap);
                minHeapSize++;
                minHeapify(minHeap, minHeapSize - 1);
            }
            return false;
        }
    }

    public static void main(String[] args)
    {
        int queries;
        int minHeapSize = 0;
        int maxHeapSize = 0;
        int lowestValueOfMinHeap = -1;
        int highestValueOfMaxHeap = -1;
        Scanner in = new Scanner(System.in);
        queries = in.nextInt();
        ArrayList<Integer> minHeap = new ArrayList<Integer>();
        ArrayList<Integer> maxHeap = new ArrayList<Integer>();
        minHeap.add(-1);
        maxHeap.add(-1);
        maxHeapSize++;
        minHeapSize++;
        for(int i = 0; i < queries; i++)
        {
            int queryType = in.nextInt();
            if(queryType == 1)
            {
                if(minHeapSize <= 3)
                {
                    int valueToBeAdded = in.nextInt();
                    minHeap.add(valueToBeAdded);
                    minHeapSize++;
                    buildMinHeap(minHeap, minHeapSize);
                    lowestValueOfMinHeap = minHeap.get(1);
                }
                else
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
                    lowestValueOfMinHeap = minHeap.get(1);
                    highestValueOfMaxHeap = maxHeap.get(1);
                }
            }
            else
            {
                if(minHeapSize > 3)//Indicates that 1/3 rd element (because -1 is defaultly added as 1st element and hence min size needs to be four for atleast 1 element to be in top 1/3rd portion) is atleast 1.
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
