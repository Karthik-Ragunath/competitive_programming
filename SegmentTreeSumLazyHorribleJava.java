import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SegmentTreeSumLazyJava
{
    public static long buildSegmentTree(long[] segmentTree, int low, int high, int position, long[] input)
    {
        int mid = (low + high) / 2;
        if(low == high)
        {
            segmentTree[position] = input[low];
            return segmentTree[position];
        }
        long left = buildSegmentTree(segmentTree, low, mid, 2 * position + 1, input);
        long right = buildSegmentTree(segmentTree, mid + 1, high, 2 * position + 2, input);
        segmentTree[position] += (left + right);
        return segmentTree[position];
    }

    public static long updateSegmentTree(long[] segmentTree, int low, int high, int startRange, int endRange, int N, int position, long[] input, long[] lazyTree, int updateValue)
    {
        //System.out.println("Low: " + low + " High: " + high + " Start Range: " + startRange + " End Range: " + endRange);
        int mid = (low + high) / 2;
        if(lazyTree[position] != 0)
        {
            long numberOfTermsInBetween = (long)(high - low + 1);
            segmentTree[position] = segmentTree[position] + (numberOfTermsInBetween * lazyTree[position]);
            System.out.println("Position: " + position + " N: " + N);
            if((2 * position + 2) < (2 * (N + 1) - 1))
            {
                lazyTree[2 * position + 2] = lazyTree[position];
                lazyTree[2 * position + 1] = lazyTree[position];
            }
            else if((2 * position + 1) < (2 * (N + 1) - 1))
            {
                lazyTree[2 * position + 1] = lazyTree[position];
            }
            lazyTree[position] = 0;
        }

        if((low < startRange && high < startRange) || low > endRange)
        {
            //System.out.println("Low < startRange and high < startRange");
            return 0;
        }

        if(low >= startRange && high <= endRange)
        {
            long numberOfTermsInBetween = (long)(high - low + 1);
            long valueToBeAdded = (numberOfTermsInBetween * updateValue);
            segmentTree[position] = segmentTree[position] + valueToBeAdded;
            if((2 * position + 2) < (2 * (N + 1) - 1))
            {
                lazyTree[2 * position + 2] += updateValue;
                lazyTree[2 * position + 1] += updateValue;
            }
            else if((2 * position + 1) < (2 * (N + 1) - 1))
            {
                lazyTree[2 * position + 1] += updateValue;
            }
            return valueToBeAdded;
        }

        long left = updateSegmentTree(segmentTree, low, mid, startRange, endRange, N, (2 * position + 1), input, lazyTree, updateValue);
        long right = updateSegmentTree(segmentTree, mid + 1, high, startRange, endRange, N, (2 * position + 2), input, lazyTree, updateValue);
        segmentTree[position] += (left + right);
        return (left + right);
    }

    public static long rangeSum(long[] segmentTree, int low, int high, int startRange, int endRange, int N, int position, long[] input, long[] lazyTree)
    {
        int mid = (low + high) / 2;
        if(lazyTree[position] != 0)
        {
            long numberOfTermsInBetween = (long)(high - low + 1);
            segmentTree[position] = segmentTree[position] + (numberOfTermsInBetween * lazyTree[position]);
            if((2 * position + 2) < (2 * (N + 1) - 1))
            {
                lazyTree[2 * position + 2] = lazyTree[position];
                lazyTree[2 * position + 1] = lazyTree[position];
            }
            else if((2 * position + 1) < (2 * (N + 1) - 1))
            {
                lazyTree[2 * position + 1] = lazyTree[position];
            }
            lazyTree[position] = 0;
        }

        if((low < startRange && high < startRange) || (low > endRange))
        {
            //System.out.println("Low < startRange and high < startRange");
            return 0;
        }

        if(low >= startRange && high <= endRange)
        {
            System.out.println("Position where value other than zero is returned: " + position + " value: " + segmentTree[position]);
            return segmentTree[position];
        }

        long left = rangeSum(segmentTree, low, mid, startRange, endRange, N, (2 * position + 1), input, lazyTree);
        long right = rangeSum(segmentTree, mid + 1, high, startRange, endRange, N, (2 * position + 2), input, lazyTree);
        long total = left + right;
        return total;
    }

    public static void printValues(long[] segmentTree, long[] lazyTree)
    {
        for(int i = 0; i < 15; i++)
        {
            System.out.println("SegTree[" + i + "] = " + segmentTree[i] + " LazyTree[" + i +"] = " + lazyTree[i]);
        }
        System.out.println("------------");
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        // long[] segmentTree = new long[1000000];
        // long sumOfValues = buildSegmentTree(segmentTree, 0, 0, 0, 0);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            // int segmentTreeSum = segmentTree.clone();
            int N, C;
            N = in.nextInt();
            C = in.nextInt();
            long[] input = new long[N];
            long[] segmentTree = new long[2 * N - 1];
            long[] lazyTree = new long[2 * N - 1];
            buildSegmentTree(segmentTree, 0, (N - 1), 0, input);
            for(int j = 0; j < C; j++)
            {
                int inputType = in.nextInt();
                if(inputType == 0)
                {
                    int startRange = in.nextInt();
                    int endRange = in.nextInt();
                    int updateValue = in.nextInt();
                    long maxValueNow = updateSegmentTree(segmentTree, 0, (N - 1), startRange - 1, endRange - 1, (N - 1), 0, input, lazyTree, updateValue);
                    printValues(segmentTree, lazyTree);

                }
                else
                {
                    int startRange = in.nextInt();
                    int endRange = in.nextInt();
                    long sumInGivenRange = rangeSum(segmentTree, 0, (N - 1), startRange - 1, endRange - 1, (N - 1), 0, input, lazyTree);
                    System.out.println("The sum in given range: " + sumInGivenRange);
                    System.out.println("--------------");
                }
            }
        }
    }
}
