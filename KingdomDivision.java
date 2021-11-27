import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

class KingdomDivision
{
    int dfs(ArrayList[]<Integer> cityRoads, int level, boolean[] nodeChecker)
    {
        int numberOfIterations = cityRoads[level].size();
        int solution = 1;
        for(int i = 0; i < numberOfIterations; i++)
        {
            int number = cityRoads[level].get(i);
            if(nodeChecker[i] == true)
            {
                continue;
            }
        }
        
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfCities = in.nextInt();
        int numberOfQueries = numberOfCities - 1;
        ArrayList<Integer>[] cityRoads = new ArrayList[numberOfCities];
        boolean[] nodeChecker = new boolean[numberOfCities];
        for(int i = 0; i < numnberOfCities; i++)
        {
            cityRoads[i] = new ArrayList();
        }
        for(int i = 0; i < numberOfQueries; i++)
        {
            int city1 = in.nextInt();
            int city2 = in.nextInt();
            cityRoads[city1].add(city2);
            cityRoads[city2].add(city1);
        }
        int level = 0;
        nodeChecker[level] = true;
        int numberOfPossibleConfigurations = new KingdomDivision(). dfs(cityRoads, level, nodeChecker);
        System.out.println(numnberofPossibleConfigurations);
    }
}
