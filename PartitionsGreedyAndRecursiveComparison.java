import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ArrayListNode
{
    ArrayList<Integer> solutionList = new ArrayList<Integer>();
}

class PartitionsGreedyWithUtil
{
        public static boolean recursivePartitions(int number, ArrayListNode arrayListNode, ArrayList<Integer> temporaryList, int N, int currentNumber, int x)
    {
        if(number == 0)
        {
            arrayListNode.solutionList = new ArrayList(temporaryList);
            return true;
        }
        else if(number < 0)
        {
            return false;
        }
        else
        {
            boolean isTheSolutionFound = false;
            int i = currentNumber;
            if(i <= N)
            {
                if(i != x)
                {
                    temporaryList.add(i);
                    isTheSolutionFound = recursivePartitions(number - i, arrayListNode, temporaryList, N, i + 1, x);
                    if(isTheSolutionFound)
                    {
                        return true;
                    }
                    temporaryList.remove(temporaryList.size() - 1);
                }
                isTheSolutionFound = recursivePartitions(number, arrayListNode, temporaryList, N, i + 1, x);
                if(isTheSolutionFound)
                {
                    return true;
                }
            }
            return false;
        }
    }


    public static boolean greedyPartition(int N, int x, ArrayList<Integer> setA)
    {
        ArrayList<Integer> setB = new ArrayList<Integer>();
        int sumA = 0;
        int sumB = 0;
        for(int i = N; i >= 1; i--)
        {
            if(i != x)
            {
                if(sumA <= sumB)
                {
                    sumA = sumA + i;
                    setA.add(i);
                }
                else
                {
                    sumB = sumB + i;
                    setB.add(i);
                }
            }
        }
        if(sumA == sumB)
        {
            return true;
        }
        else
        {
            int setASize = setA.size();
            int setBSize = setB.size();
            if(sumB < sumA)
            {
                if(setBSize == setASize)
                {
                    if(setBSize - 1 > 0)
                    {
                        int previousValueInSetA = (int)(setA.get(setBSize - 2));
                        int previousValueInSetB = (int)(setB.get(setBSize - 2));
                        if(previousValueInSetA > previousValueInSetB)
                        {
                            setA.set((setBSize - 2), previousValueInSetB);
                            setB.set((setBSize - 2), previousValueInSetA);
                            return true;
                        }
                        else
                        {
                            if(setBSize - 2 > 0)
                            {
                                int prevPreviousValueInSetA = (int)(setA.get(setBSize - 3));
                                int prevPreviousValueInSetB = (int)(setB.get(setBSize - 3));
                                if(prevPreviousValueInSetA > prevPreviousValueInSetB)
                                {
                                    setA.set((setBSize - 3), prevPreviousValueInSetB);
                                    setB.set((setBSize - 3), prevPreviousValueInSetA);
                                    return true;
                                }
                            }
                        }
                    }
                }
                else if(setASize > setBSize)
                {
                    int lastElementSetA = (int)setA.get(setASize - 1);
                    int difference = sumA - sumB;
                    if(lastElementSetA == 2 && difference == 2)
                    {
                        int setASubtractionIndex = 2;
                        int setBSubtractionIndex = 1;
                        boolean returnValue = false;
                        for(int j = setASize - 2, k = setBSize - 1; j >= 0 && k >= 0; j--, k--)
                        {
                            int setAElement = (int)setA.get(j);
                            int setBElement = (int)setB.get(k);
                            if(setAElement > setBElement)
                            {
                                setA.set(j, setBElement);
                                setB.set(k, setAElement);
                                returnValue = true;
                                break;
                            }
                        }
                        return returnValue;
                    }
                }
            }
            else
            {
                if(setBSize == setASize)
                {
                    if(setBSize - 1 > 0)
                    {
                        int previousValueInSetA = (int)(setA.get(setBSize - 2));
                        int previousValueInSetB = (int)(setB.get(setBSize - 2));
                        if(previousValueInSetB > previousValueInSetA)
                        {
                            setA.set((setBSize - 2), previousValueInSetB);
                            setB.set((setBSize - 2), previousValueInSetA);
                            return true;
                        }
                        else
                        {
                            if(setBSize - 2 > 0)
                            {
                                int prevPreviousValueInSetA = (int)(setA.get(setBSize - 3));
                                int prevPreviousValueInSetB = (int)(setB.get(setBSize - 3));
                                if(prevPreviousValueInSetB > prevPreviousValueInSetA)
                                {
                                    setA.set((setBSize - 3), prevPreviousValueInSetB);
                                    setB.set((setBSize - 3), prevPreviousValueInSetA);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
            return false;
        }
    }
    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int x;
            int N;
            x = in.nextInt();
            N = in.nextInt();
            int sum = (N * (N + 1)) / 2;
            int actualSum = sum - x;
            ArrayListNode arrayListNode = new ArrayListNode();
            ArrayList<Integer> temporaryList = new ArrayList<Integer>();
            ArrayList<Integer> setA = new ArrayList<Integer>();
            if(actualSum % 2 != 0)
            {
                System.out.println("impossible");
            }
            else
            {
                boolean greedyPartitionSolution = greedyPartition(N, x, setA);
                boolean recursiveSolution = recursivePartitions(actualSum / 2, arrayListNode, temporaryList, N, 1, x);
                if(greedyPartitionSolution != recursiveSolution)
                {
                    System.out.println("Greedy Partition: " + greedyPartitionSolution);
                    System.out.println("Recursive Partition: " + recursiveSolution);
                    System.out.println("Something went wrong");
                }
                if(greedyPartitionSolution)
                {
                    String[] solutionArray = new String[N + 1];
                    int lastElementOfA = (int)setA.get(setA.size() - 1);
                    if(lastElementOfA == 1)
                    {
                        Arrays.fill(solutionArray, "1");
                        Iterator setAIterator = setA.iterator();
                        while(setAIterator.hasNext())
                        {
                            int value = (int)setAIterator.next();
                            solutionArray[value] = "0";
                        }
                    }
                    else
                    {
                        Arrays.fill(solutionArray, "0");
                        Iterator setAIterator = setA.iterator();
                        while(setAIterator.hasNext())
                        {
                            int value = (int)setAIterator.next();
                            solutionArray[value] = "1";
                        }
                    }
                    for(int j = 1; j <= N; j++)
                    {
                        if(j != x)
                        {
                            System.out.print(solutionArray[j]);
                        }
                        else
                        {
                            System.out.print("2");
                        }
                    }
                    System.out.println();
                }
                else
                {
                    System.out.println("impossible");
                    Iterator setAIterator = setA.iterator();
                    while(setAIterator.hasNext())
                    {
                        int value = (int)setAIterator.next();
                        System.out.print(value + " ");
                    }
                    System.out.println();
                    System.out.println("-----Impossible-----");
                    Iterator solutionListIterator = arrayListNode.solutionList.iterator();
                    while(solutionListIterator.hasNext())
                    {
                        int value = (int)solutionListIterator.next();
                        System.out.print(value + " ");
                    }
                    System.out.println();
                    System.out.println("-------Impossible-------");
                }
            }
        }
    }
}
