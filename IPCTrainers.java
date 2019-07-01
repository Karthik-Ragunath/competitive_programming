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
            System.out.print("key: " + key + " ");
            ArrayList<Integer> listValue = (ArrayList<Integer>)treeMap.get(key);
            Iterator listValueIter = listValue.iterator();
            System.out.print("Value(s): ");
            while(listValueIter.hasNext())
            {
                int value = (int)listValueIter.next();
                System.out.print(value + " ");
            }
            System.out.println();
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

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int numberOfDays = in.nextInt();
            int numberOfLecturers = in.nextInt();
            int[] arrivalDay = new int[numberOfDays];
            int[] lecturesToBeTaken = new int[numberOfDays];
            int[] sadnessCount = new int[numberOfLecturers];

            TreeMap<Integer, ArrayList<Integer>> lectureIndexMap = new TreeMap<Integer, ArrayList<Integer>>();
            for(int j = 0; j < numberOfDays; j++)
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

            int[] heapifyArray = new int[numberOfLecturers + 1];
            for(int j = 1; j <= numberOfDays; j++)
            {
                if (lectureIndexMap.containsKey(j))
                {

                }
            }
        }
    }
}
