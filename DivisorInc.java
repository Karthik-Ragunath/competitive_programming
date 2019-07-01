import java.io.*;
import java.math.*;
import java.util.*;

class DivisorInc
{
    public static ArrayList<Integer> primeNumbers(int endingNumber)
    {
        ArrayList<Integer> primeList = new ArrayList<Integer>();
        boolean[] primeChecker = new boolean[endingNumber + 1];
        Arrays.fill(primeChecker, true);
        int sqrtValue = (int)(Math.sqrt(endingNumber));
        primeList.add(2);
        for(int i = 3; i <= sqrtValue; i += 2)
        {
            for(int j = i; j <= endingNumber; j += 2)
            {
                int value = i * j;
                if(value <= endingNumber)
                {
                    primeChecker[value] = false;
                }
                else
                {
                    break;
                }
            }
        }
        for(int i = 3; i <= endingNumber; i += 2)
        {
            if(primeChecker[i])
            {
                primeList.add(i);
            }
        }
        return primeList;
    }

    public static ArrayList<Integer> possiblePrimeFactors(int endingNumber)
    {
        ArrayList<Integer> primeList = new ArrayList<Integer>();
        boolean[] primeChecker = new boolean[(endingNumber/2) + 1]; //Because primeNumber greater than half the value of a nummber cant be the divisor of the number
        Arrays.fill(primeChecker, true);
        //One factor always lies below the sqrt value an therefore the remaining factor can be found from the factors which lies below sqrtValue, in that, the left out numbers are primes.
        int sqrtValue = (int)(Math.sqrt(endingNumber/2));
        primeList.add(2);
        for(int i = 3; i <= sqrtValue; i += 2)
        {
            for(int j = i; j <= (endingNumber/2); j += 2)
            {
                int value = i * j;
                if(value <= (endingNumber / 2))
                {
                    primeChecker[value] = false;
                }
                else
                {
                    break;
                }
            }
        }
        for(int i = 3; i <= (endingNumber / 2); i += 2)
        {
            if(primeChecker[i])
            {
                primeList.add(i);
            }
        }
        return primeList;
    }

    public static int[] getThePrimeArray(ArrayList<Integer> primeList)
    {
        int[] primeArray = new int[primeList.size()];
        Iterator primeListIterator = primeList.iterator();
        int count = 0;
        while(primeListIterator.hasNext())
        {
            primeArray[count] = (int)primeListIterator.next();
            // System.out.println(primeArray[count]);
            count += 1;
        }
        return primeArray;
    }

    public static int[] getThePrimeDivisorsArray(ArrayList<Integer> primeList)
    {
        int[] primeArray = new int[primeList.size()];
        Iterator primeListIterator = primeList.iterator();
        int count = 0;
        while(primeListIterator.hasNext())
        {
            primeArray[count] = (int)primeListIterator.next();
            // System.out.println(primeArray[count]);
            count += 1;
        }
        return primeArray;
    }

    public static ArrayList<Integer> getThePrimeDivisors(int[] primeArray, int endingNumber)
    {
        ArrayList<Integer> primeDivisorsList = new ArrayList<Integer>();
        int arrayLenth = primeArray.length;
        for(int i = 0; i < arrayLenth; i++)
        {
            if(endingNumber % primeArray[i] == 0)
            {
                primeDivisorsList.add(primeArray[i]);
            }
        }
        return primeDivisorsList;
    }

    public static int[] getTheCountOfPrimeFactorsExponent(int[] primeDivisorsArray, int endingNumber)
    {
        int lengthOfPrimeDivisorsArray = primeDivisorsArray.length;
        int[] exponentValueOfPrimeDivisors = new int[primeDivisorsArray.length];
        for(int i = 0; i < lengthOfPrimeDivisorsArray; i++)
        {
            int exponentValue = 0;
            while(endingNumber % primeDivisorsArray[i] == 0)
            {
                exponentValue = exponentValue + 1;
                endingNumber = endingNumber / primeDivisorsArray[i];
            }
            exponentValueOfPrimeDivisors[i] = exponentValue;
        }
        return exponentValueOfPrimeDivisors;
    }

    public static void printTheExponents(int[] getThePrimeExponents)
    {
        for(int i = 0; i < getThePrimeExponents.length; i++)
        {
            System.out.println(getThePrimeExponents[i]);
        }
    }

    public static void getAllDivisors(int[] primeDivisors, int[] primeExponents, int currentIndex, int currentValue, int primeDivisorsLength, ArrayList<Integer> allDivisors)
    {
        int value = primeDivisors[currentIndex];
        for(int i = 0; i <= primeExponents[currentIndex]; i++)
        {
            if(i == 0)
            {
                if (currentIndex == 0)
                {
                    currentValue = 1;
                }
                if(currentIndex == (primeDivisorsLength - 1))
                {
                    allDivisors.add(currentValue);
                }
                else
                {
                    getAllDivisors(primeDivisors, primeExponents, currentIndex + 1, currentValue, primeDivisorsLength, allDivisors);
                }
            }
            else
            {
                if (currentIndex == 0)
                {
                    currentValue = 0;
                    currentValue = currentValue + value;
                }
                else
                {
                    currentValue = currentValue * value;
                }
                if(currentIndex == (primeDivisorsLength - 1))
                {
                    allDivisors.add(currentValue);
                }
                else
                {
                    getAllDivisors(primeDivisors, primeExponents, currentIndex + 1, currentValue, primeDivisorsLength, allDivisors);
                }
                value *= primeDivisors[currentIndex];
            }
        }
    }

    public static void getAllDivisorsArray(ArrayList<Integer> allDivisors)
    {
        Iterator allDivisorsIterator = allDivisors.iterator();
        while(allDivisorsIterator.hasNext())
        {
            int divisorValue = (int)allDivisorsIterator.next();
            System.out.println(divisorValue);
        }
    }

    public static void main(String[] args)
    {
        int startingNumber;
        int endingNumber;
        Scanner in = new Scanner(System.in);
        startingNumber = in.nextInt();
        endingNumber = in.nextInt();
        ArrayList<Integer> primeList = possiblePrimeFactors(endingNumber);
        int[] primeArray = getThePrimeArray(primeList);
        ArrayList<Integer> primeDivisors = getThePrimeDivisors(primeArray, endingNumber);
        int[] primeDivisorsArray = getThePrimeDivisorsArray(primeDivisors);
        int[] getThePrimeExponents = getTheCountOfPrimeFactorsExponent(primeDivisorsArray, endingNumber);
        // printTheExponents(getThePrimeExponents);
        ArrayList<Integer> allDivisors = new ArrayList<Integer>();
        int primeDivisorsLength = primeDivisorsArray.length;
        getAllDivisors(primeDivisorsArray, getThePrimeExponents, 0, 1, primeDivisorsLength, allDivisors);
        getAllDivisorsArray(allDivisors);
    }
}
