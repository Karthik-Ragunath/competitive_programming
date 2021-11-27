import java.io.*;
import java.util.*;
import java.math.*;

class GeometricTrick
{
    public static int[] factorize (int num, int primeArray[], int[] minimumPrimeArray, ArrayList<Integer> primeList, Map<Integer, Integer> hash)
    {
        if (primeList.contains(num))
        {
            int[] factorizeReturner = new int[2];
            factorizeReturner[0] = 1;
            factorizeReturner[1] = num;
            return factorizeReturner;
        }
        else
        {
            int minimumPrimePositionInPrimeArray = (int)(hash.get(num));
            System.out.println(minimumPrimePositionInPrimeArray);
            int sqrtValue = (int)(Math.sqrt((double)(num)));
            ArrayList<Integer> returnList = new ArrayList<Integer>();
            for(int i = minimumPrimePositionInPrimeArray; primeArray[i] <= sqrtValue; i++)
            {
                System.out.println(primeArray[i]);
                if (num % primeArray[i] == 0)
                {
                    while(num % primeArray[i] == 0)
                    {
                        num = num / primeArray[i];
                        System.out.println("Number: "+ num);
                        returnList.add(primeArray[i]);
                    }
                }
            }
            if (num != 1)
            {
                returnList.add(num);
            }
            Integer[] primeArrayInteger = returnList.toArray(new Integer[returnList.size()]);
            int returnListSize = returnList.size();
            int[] returnerArray = new int[returnListSize + 1];
            returnerArray[0] = returnListSize;
            for(int i = 0; i < returnListSize; i++)
            {
                returnerArray[i + 1] = primeArrayInteger[i];
            }
            return returnerArray;
        }
    }
    public static void main(String[] args)
    {
        int number = 100;
        ArrayList<Integer> primeList = new ArrayList<Integer>();
        boolean[] primeChecker = new boolean[number + 1];
        Map<Integer, Integer> hash = new HashMap<Integer, Integer>();

        for ( int i = 1; i <= (number); i ++)
        {
            primeChecker[i] = true;
        }
        int[] minimumPrimeArray = new int[number + 1];

        for(int i = 3; i <= number; i = i + 2)
        {
            minimumPrimeArray[i] = i;
        }

        int counter = 0;

        for(int i = 2; i <= number; i = i + 2)
        {
            minimumPrimeArray[i] = 2;
            hash.put(i,counter);
        }

        int sqrtOfMaxValue = (int)(Math.sqrt((double)(number)));

        for(int i = 3; i <= sqrtOfMaxValue; i = i + 2)
        {
            if(primeChecker[i])
            {
                counter = counter + 1;
                //minimumPrimeArray[i] = i;
                for(int j = i; (j * i) <= number; j = j + 2)
                {
                    if ((i * j) <= number)
                    {
                        primeChecker[(i * j)] = false;
                        minimumPrimeArray[(i * j)] = i;
                        hash.put((i * j), counter);
                    }
                }
            }
        }

        int count = 0;

        for( int i = 2; i <= number; i++)
        {
            if (minimumPrimeArray[i] == i)
            {
                primeList.add(i);
            }
        }

        for (int i = 0; i <= number; i++)
        {
            System.out.println(i + ": " + minimumPrimeArray[i]);
        }

        int arrayListSize = primeList.size();
        System.out.println(arrayListSize);
        int[] primeArray = new int[arrayListSize];
        Iterator iterator = primeList.iterator();
        System.out.println("Prime Values: ");

        while(iterator.hasNext())
        {
            int primeValue = (int)(iterator.next());
            primeArray[count] = primeValue;
            System.out.println(primeValue);
            count++;
        }

        int num1 = 98;
        int num2 = 24;
        int[] factors = new GeometricTrick().factorize(num1, primeArray, minimumPrimeArray, primeList, hash);
        int size = factors[0];
        System.out.println("The factors are: ");

        for(int i = 1; i <= size; i++)
        {
            System.out.println(factors[i]);
        }
    }
}
