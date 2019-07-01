import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

class KingdomDivisionToBeCompleted
{
    int dfs(ArrayList<Integer>[] cityRoads, int level, boolean[] nodeChecker)
    {
        int numberOfIterations = cityRoads[level].size();
        int solution = 2;
        boolean atLeastOneElementExist = false;
        ArrayList<Integer> levelOne = new ArrayList<Integer>();
        for(int i = 0; i < numberOfIterations; i++)
        {
            int number = cityRoads[level].get(i);
            System.out.println("Level: " + level + " Number: " + number);
            if(nodeChecker[number] == true)
            {
                continue;
            }
            System.out.println("Came Here");
            atLeastOneElementExist = true;
            nodeChecker[number] = true;
            if(level == 1)
            {
                levelOne.add(dfs(cityRoads, number, nodeChecker));
            }
            else
            {
                solution = solution * dfs(cityRoads, number, nodeChecker);
            }
        }
        if( atLeastOneElementExist == true )
        {
            if(level == 1)
            {
                Integer[] levelOneSolutions = levelOne.toArray(new Integer[levelOne.size()]);
                Arrays.sort(levelOneSolutions);
                System.out.println();
                System.out.print("Inside Level One Solutions Array:");
                for(int i = 0; i < levelOne.size(); i++)
                {
                    //System.out.print(" " + levelOneSolutions[i]);
                    if(i == 0)
                    {

                    }
                }
            }
            return solution;
        }
        else
        {
            return 1;
        }
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfCities = in.nextInt();
        int numberOfQueries = numberOfCities - 1;
        System.out.println("Number of Cities: " + numberOfCities);
        ArrayList<Integer>[] cityRoads = new ArrayList[numberOfCities + 1];
        boolean[] nodeChecker = new boolean[numberOfCities + 1];
        for(int i = 0; i <= numberOfCities; i++)
        {
            cityRoads[i] = new ArrayList();
        }
        for(int i = 0; i < numberOfQueries; i++)
        {
            int city1 = in.nextInt();
            int city2 = in.nextInt();
            System.out.println("City1: " + city1 +" City2: " + city2);
            cityRoads[city1].add(city2);
            cityRoads[city2].add(city1);
            System.out.println("i: " + i);
        }
        int level = 1;
        nodeChecker[level] = true;
        int numberOfPossibleConfigurations = new KingdomDivision(). dfs(cityRoads, level, nodeChecker);
        System.out.println(numberOfPossibleConfigurations);
    }
}
