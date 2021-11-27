import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class IntegrePartitions
{
    public static int getTheCountOfCombinations(int number, int maxValue)
    {
        if (number == 0)
        {
            return 1; //base case in which the combinations is obtained
        }
        else if (number < 0)
        {
            return 0; //base case in which combination is not obtained
        }
        else
        {
            int counter = 0;
            for(int i = 2; i <= maxValue; i += 2)
            {
                counter += getTheCountOfCombinations(number - i, maxValue);
            }
            return counter;
        }
    }

    public static void getTheCombinations(int number, int maxValue, ArrayList<ArrayList<Integer>> combinations, ArrayList<Integer> tempCombinations)
    {
        if(number == 0)
        {
            ArrayList<Integer> temp = new ArrayList(tempCombinations);
            combinations.add(temp);
            // We make a copy of list and append in solution list because python lists are pass by reference and hence when elements are modified in tempCombinations, they get modified in combinations as well.
            return;
        }
        else if (number < 0)
        {
            return;
        }
        else
        {
            for(int i = 2; i <= maxValue; i += 2)
            {
                tempCombinations.add(i);
                getTheCombinations(number - i, maxValue, combinations, tempCombinations);
                tempCombinations.remove(tempCombinations.size() - 1);
            }
        }
    }

    public static int getTheUniqueCountOfCombinations(int number, int maxValue, int currentValue)
    {
        if (number == 0)
        {
            return 1; //base case in which the combinations is obtained
        }
        else if (number < 0)
        {
            return 0; //base case in which combination is not obtained
        }
        else
        {
            int counter = 0;
            for(int i = currentValue; i <= maxValue; i += 2)
            {
                currentValue = i;
                counter += getTheUniqueCountOfCombinations(number - i, maxValue, currentValue);
            }
            return counter;
        }
    }

        public static void getTheUniqueCombinations(int number, int maxValue, ArrayList<ArrayList<Integer>> combinations, ArrayList<Integer> tempCombinations, int currentValue)
    {
        if(number == 0)
        {
            ArrayList<Integer> temp = new ArrayList(tempCombinations);
            combinations.add(temp);
            return;
        }
        else if (number < 0)
        {
            return;
        }
        else
        {
            for(int i = currentValue; i <= maxValue; i += 2)
            {
                currentValue = i;
                tempCombinations.add(i);
                getTheUniqueCombinations(number - i, maxValue, combinations, tempCombinations, currentValue);
                tempCombinations.remove(tempCombinations.size() - 1);
            }
        }
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int value = in.nextInt();
            int maxValue = in.nextInt();
            int countValue = getTheCountOfCombinations(value, maxValue);
            System.out.println(countValue);
            System.out.println("-------**********-------");
            ArrayList<ArrayList<Integer>> combinations = new ArrayList<ArrayList<Integer>>();
            ArrayList<Integer> tempCombinations = new ArrayList<Integer>();
            getTheCombinations(value, maxValue, combinations, tempCombinations);
            Iterator combinationsIter = combinations.iterator();
            while(combinationsIter.hasNext())
            {
                ArrayList<Integer> induvidualCombinations = (ArrayList<Integer>)combinationsIter.next();
                Iterator induvidualIter = induvidualCombinations.iterator();
                while(induvidualIter.hasNext())
                {
                    int induvidualValue = (int)induvidualIter.next();
                    System.out.print(induvidualValue + " ");
                }
                System.out.println();
            }
            System.out.println("-------**********-------");
            int uniqueCountValue = getTheUniqueCountOfCombinations(value, maxValue, 2);
            System.out.println(uniqueCountValue);
            System.out.println("-------**********-------");
            ArrayList<ArrayList<Integer>> uniqueCombinations = new ArrayList<ArrayList<Integer>>();
            ArrayList<Integer> tempUniqueCombinations = new ArrayList<Integer>();
            getTheUniqueCombinations(value, maxValue, uniqueCombinations, tempUniqueCombinations, 2);
            Iterator uniqueCombinationsIter = uniqueCombinations.iterator();
            while(uniqueCombinationsIter.hasNext())
            {
                ArrayList<Integer> induvidualCombinations = (ArrayList<Integer>)uniqueCombinationsIter.next();
                Iterator induvidualIter = induvidualCombinations.iterator();
                while(induvidualIter.hasNext())
                {
                    int induvidualValue = (int)induvidualIter.next();
                    System.out.print(induvidualValue + " ");
                }
                System.out.println();
            }
            System.out.println("-------**********-------");
        }
    }
}
