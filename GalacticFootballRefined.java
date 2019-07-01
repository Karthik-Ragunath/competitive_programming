import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class Planet
{
    Hash pointer;
    int value;
}

class Hash
{
    int value;
}

class GalacticFootballRefined
{
    public static void main(String[] args)
    {
        int numberOfPlanets;
        int numberOfMutualAgreements;
        Scanner in = new Scanner(System.in);
        numberOfPlanets = in.nextInt();
        numberOfMutualAgreements = in.nextInt();
        Planet[] planet = new Planet[numberOfPlanets + 1];
        Hash[] hash = new Hash[numberOfPlanets + 1];
        int[] leftPartOfMutualAgreement = new int[numberOfMutualAgreements + 1];
        int[] rightPartOfMutualAgreement = new int[numberOfMutualAgreements + 1];
        int[] planetTaxes = new int[numberOfPlanets + 1];
        for(int i = 1; i <= numberOfMutualAgreements; i++)
        {
            leftPartOfMutualAgreement[i] = in.nextInt();
            rightPartOfMutualAgreement[i] = in.nextInt();
        }
        for(int i = 1; i <= numberOfPlanets; i++)
        {
            planet[i] = new Planet();
            hash[i] = new Hash();
            planetTaxes[i] = in.nextInt();
            planet[i].value = planetTaxes[i];
            planet[i].pointer = hash[i];
            hash[i].value = i;
        }
        // Hash tester = planet[1].pointer;
        // int value = tester.value;
        // System.out.println(value);
        // System.out.println(planet[1].pointer.value);
        for(int i = 1; i <= numberOfMutualAgreements; i++)
        {
            if(planetTaxes[hash[leftPartOfMutualAgreement[i]].value] >= 0 && planetTaxes[hash[rightPartOfMutualAgreement[i]].value] >= 0)
            {
                System.out.println("Case 1: " + hash[leftPartOfMutualAgreement[i]].value + " " + hash[rightPartOfMutualAgreement[i]].value);
                if(planetTaxes[hash[leftPartOfMutualAgreement[i]].value] < planetTaxes[hash[rightPartOfMutualAgreement[i]].value])
                {
                    hash[rightPartOfMutualAgreement[i]] = hash[leftPartOfMutualAgreement[i]];
                }
                else
                {
                    hash[leftPartOfMutualAgreement[i]] = hash[rightPartOfMutualAgreement[i]];
                }
            }
            else if(planetTaxes[hash[leftPartOfMutualAgreement[i]].value] < 0 && planetTaxes[hash[rightPartOfMutualAgreement[i]].value] >= 0)
            {
                hash[leftPartOfMutualAgreement[i]] = hash[rightPartOfMutualAgreement[i]];
            }
            else if(planetTaxes[hash[rightPartOfMutualAgreement[i]].value] < 0 && planetTaxes[hash[leftPartOfMutualAgreement[i]].value] >= 0)
            {
                hash[rightPartOfMutualAgreement[i]] = hash[leftPartOfMutualAgreement[i]];
            }
        }
        for(int i = 1; i <= numberOfPlanets; i++)
        {
            System.out.println(planet[i].pointer.value);
        }
        // System.out.println(planet[1].pointer.value);
        int referenceIndex = 1;
        if(planetTaxes[hash[referenceIndex].value] < 0)
        {
            System.out.println("-1");
        }
        else
        {
            int referenceCost = planetTaxes[hash[referenceIndex].value];
            ArrayList<Integer> visited = new ArrayList<Integer>();
            int totalCost = 0;
            for(int i = 2; i <= numberOfPlanets; i++)
            {
                if(hash[referenceIndex].value != hash[i].value)
                {
                    System.out.println("Solution Compute: " + hash[referenceIndex].value + " " + hash[i].value);
                    if(planetTaxes[hash[i].value] < 0)
                    {
                        totalCost = -1;
                        break;
                    }
                    else
                    {
                        if(!visited.contains(hash[i].value))
                        {
                            totalCost = totalCost + referenceCost + planetTaxes[hash[i].value];
                            visited.add(hash[i].value);
                        }
                    }
                }
            }
            System.out.println(totalCost);
        }
    }
}
