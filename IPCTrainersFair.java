import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

class IPCTrainers
{
    public static void printTheMapAndKeys(TreeMap<Integer, ArrayList<Integer>> treeMap)
    {
        for(Integer key: treeMap.keySet())
        {
            ArrayList<Integer> listValue = (ArrayList<Integer>)treeMap.get(key);
            Iterator listValueIter = listValue.iterator();
            while(listValueIter.hasNext())
            {
                int value = (int)listValueIter.next();
            }
        }
    }

    public static void sortTheMapValues(TreeMap<Integer, ArrayList<Integer>> treeMap)
    {
        for(Integer key: treeMap.keySet())
        {
            ArrayList<Integer> listValue = (ArrayList<Integer>)treeMap.get(key);
            Collections.sort(listValue);
            Collections.reverse(listValue);
        }
    }

    public static void sortMapBasedOnSadnessCount(TreeMap<Integer, ArrayList<Integer>> treeMap, final int[] sadnessCount)
    {
        for(Integer key: treeMap.keySet())
        {
            ArrayList<Integer> listValue = (ArrayList<Integer>)treeMap.get(key);
            Collections.sort(listValue, new Comparator<Integer>()
            {
                public int compare(Integer left, Integer right)
                {
                    // return sadnessCount[right].compareTo(sadnessCount[left]); //This is not for primitives
                    // return Integer.compare(sadnessCount[right], sadnessCount[left]); //To get in descending order in Java 7+
                    if (sadnessCount[right] > sadnessCount[left])
                    {
                        return 1;
                    }
                    else if (sadnessCount[right] < sadnessCount[left])
                    {
                        return -1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            });
        }
    }

    public static void heapify(ArrayList<Integer> heapifyList)
    {
        int indexOfTheElementToBeHeapified = (int)(heapifyList.size() - 1);
        int elementToBeHeapified = (int)(heapifyList.get(indexOfTheElementToBeHeapified));
        while(indexOfTheElementToBeHeapified != 1)
        {
            int parentIndex = indexOfTheElementToBeHeapified / 2;
            int parentElement = (int)(heapifyList.get(parentIndex));
            if (elementToBeHeapified > parentElement)
            {
                Collections.swap(heapifyList, parentIndex, indexOfTheElementToBeHeapified);
                indexOfTheElementToBeHeapified = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    public static void heapifyProblemSpecific(ArrayList<Integer> heapifyList, int[] sadnessCount)
    {
        int indexOfTheElementToBeHeapified = (int)(heapifyList.size() - 1);
        int elementToBeHeapified = (int)(heapifyList.get(indexOfTheElementToBeHeapified));
        while(indexOfTheElementToBeHeapified != 1)
        {
            int parentIndex = indexOfTheElementToBeHeapified / 2;
            int parentElement = (int)(heapifyList.get(parentIndex));
            if (sadnessCount[elementToBeHeapified] > sadnessCount[parentElement])
            {
                Collections.swap(heapifyList, parentIndex, indexOfTheElementToBeHeapified);
                indexOfTheElementToBeHeapified = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    public static void printHeapifiedList(ArrayList<Integer> heapifiedList)
    {
        Iterator heapIter = heapifiedList.iterator();
        while(heapIter.hasNext())
        {
            int heapValue = (int)heapIter.next();
        }
    }

    public static void computeOnHeapifiedList(ArrayList<Integer> heapifiedList, int[] lecturesToBeTaken, int[] sadnessCount)
    {
        if (heapifiedList.size() != 1)
        {
            int heapHead = heapifiedList.get(1);
            int heapifiedListSize = heapifiedList.size();
            int lecturesLeft = lecturesToBeTaken[heapHead];
            if(lecturesLeft == 1)
            {
                Collections.swap(heapifiedList, 1, heapifiedListSize - 1);
                heapifiedList.remove(heapifiedListSize - 1);
                int headIndex = 1;
                while(headIndex < heapifiedListSize - 1 && ((headIndex * 2) < (heapifiedListSize - 1)))
                {
                    if(headIndex * 2 + 1 < heapifiedListSize - 1)
                    {
                        if(sadnessCount[headIndex * 2] > sadnessCount[(headIndex * 2 + 1)])
                        {
                            if(sadnessCount[headIndex] < sadnessCount[headIndex * 2])
                            {
                                Collections.swap(heapifiedList, headIndex, (headIndex * 2));
                                headIndex = headIndex * 2;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            if(sadnessCount[headIndex] < sadnessCount[headIndex * 2 + 1])
                            {
                                Collections.swap(heapifiedList, headIndex, headIndex * 2 + 1);
                                headIndex = headIndex * 2 + 1;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        if(sadnessCount[headIndex] < sadnessCount[headIndex * 2])
                        {
                            Collections.swap(heapifiedList, headIndex, headIndex * 2);
                            headIndex = headIndex * 2;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                lecturesToBeTaken[heapHead] -= 1;
            }
        }
    }

    public static void solution(ArrayList<Integer> heapifiedList, int[] lecturesToBeTaken, int[] sadnessLevel)
    {
        int solution = 0;
        Iterator heapIter = heapifiedList.iterator();
        while(heapIter.hasNext())
        {
            int tempSolutionIndex = (int)heapIter.next();
            if(tempSolutionIndex != -1)
            {
                int numberOfLecturesLeft = lecturesToBeTaken[tempSolutionIndex];
                int sadLevel = sadnessLevel[tempSolutionIndex];
                solution = solution + (numberOfLecturesLeft * sadLevel);
            }
        }
        System.out.println(solution);
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int numberOfLecturers = in.nextInt();
            int numberOfDays = in.nextInt();
            int[] arrivalDay = new int[numberOfLecturers];
            int[] lecturesToBeTaken = new int[numberOfLecturers];
            int[] sadnessCount = new int[numberOfLecturers];

            TreeMap<Integer, ArrayList<Integer>> lectureIndexMap = new TreeMap<Integer, ArrayList<Integer>>();
            for(int j = 0; j < numberOfLecturers; j++)
            {
                arrivalDay[j] = in.nextInt();
                lecturesToBeTaken[j] = in.nextInt();
                sadnessCount[j] = in.nextInt();
                if (lectureIndexMap.containsKey(arrivalDay[j]))
                {
                    ArrayList<Integer> listToBeAppended = (ArrayList<Integer>)lectureIndexMap.get(arrivalDay[j]);
                    listToBeAppended.add(j);
                }
                else
                {
                    ArrayList<Integer> initialList = new ArrayList<Integer>();
                    initialList.add(j);
                    lectureIndexMap.put(arrivalDay[j], initialList);
                }
            }
            printTheMapAndKeys(lectureIndexMap);
            // sortTheMapValues(lectureIndexMap);
            sortMapBasedOnSadnessCount(lectureIndexMap, sadnessCount);
            printTheMapAndKeys(lectureIndexMap);

            ArrayList<Integer> heapifyList = new ArrayList<Integer>();
            ArrayList<Integer> syncLecturesToBeTakenWithHeapifiedList = new ArrayList<Integer>();
            heapifyList.add(-1);
            for(int j = 1; j <= numberOfDays; j++)
            {
                if (lectureIndexMap.containsKey(j))
                {
                    if (heapifyList.size() == 1)
                    {
                        ArrayList<Integer> keyList= (ArrayList<Integer>)lectureIndexMap.get(j);
                        Iterator listIter = keyList.iterator();
                        while(listIter.hasNext())
                        {
                            int iterValue = (int)listIter.next();
                            heapifyList.add(iterValue);
                        }
                        computeOnHeapifiedList(heapifyList, lecturesToBeTaken, sadnessCount);
                        printHeapifiedList(heapifyList);
                    }
                    else
                    {
                        ArrayList<Integer> keyList= (ArrayList<Integer>)lectureIndexMap.get(j);
                        Iterator listIter = keyList.iterator();
                        while(listIter.hasNext())
                        {
                            int iterValue = (int)listIter.next();
                            heapifyList.add(iterValue);
                            // heapify(heapifyList);
                            heapifyProblemSpecific(heapifyList, sadnessCount);
                            computeOnHeapifiedList(heapifyList, lecturesToBeTaken, sadnessCount);
                            printHeapifiedList(heapifyList);
                        }
                    }
                }
                else
                {
                    computeOnHeapifiedList(heapifyList, lecturesToBeTaken, sadnessCount);
                    printHeapifiedList(heapifyList);
                }
            }
            solution(heapifyList, lecturesToBeTaken, sadnessCount);
        }
    }
}
