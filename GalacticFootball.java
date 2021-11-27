import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

class Planet
{
    int value;
    int index;
    Planet parent;
}

class GalacticFootball
{
    public static void main(String[] args)
    {
        int numberOfPlanets;
        int numberOfMutualAgreements;
        Scanner in = new Scanner(system.in);
        numberOfPlanets = in.nextInt();
        numberOfMutualAgreements = in.nextInt();
        int[] leftPartOfPair = new int[numberOfMutualAgreements];
        int[] rightPartOfPair = new int[numberOfMutualAgreements];
        int[] planetTaxes = new int[numberOfPlanets + 1];
        ArrayList<Planet> planetList = new ArrayList<Planet>();
        Planet emptyPlanet = new Planet();
        planetList.add(emptyPlanet);
        boolean[] planetExists = new boolean[numberOfPlanets + 1];
        for(int i = 0; i < numberOfMutualAgreements; i++)
        {
            leftPartOfPair[i] = in.nextInt();
            rightPartOfPair[i] = in.nextInt();
        }
        for(int i = 1; i <= numberOfPlanets; i++)
        {
            planetTaxes[i + 1] = in.nextInt();
            Planet planet = new Planet();
            planet.value = planetTaxes[i + 1];
            planet.parent = parent;
            planet.index = i;
            planetList.add(planet);
        }
        for(int i = 0; i < numberOfMutualAgreements; i++)
        {
            if(planetTaxes[leftPartOfPair[i]] < planetTaxes[rightPartOfPair[i]])
            {
                Planet planet = new Planet();
                planet.value = planet[rightPartOfPair[i]].value;
                planet.parent = (Planet)planetList.get(leftPartOfPair[i]);
                planet.index = rightPartOfPair[i];
                planetList.remove(rightPartOfPair[i]);
                planetExists[rightPartOfPair[i]] = false;
            }
            else
            {
                Planet planet = new Planet();
                planet.value = planet[leftPartOfPair[i]].value;
                planet.parent = planetList.get(rightPartOfPair[i]);
            }
        }
    }
}
