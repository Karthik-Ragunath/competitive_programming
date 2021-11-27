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

class BasicUnderstandingGalactic
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
        System.out.println(planet[2].pointer.value);
        System.out.println(hash[2].value);
        // Hash tester = planet[1].pointer;
        // int value = tester.value;
        // System.out.println(value);
        // System.out.println(planet[1].pointer.value);
        for(int i = 1; i <= numberOfMutualAgreements; i++)
        {
            if(planetTaxes[leftPartOfMutualAgreement[i]] < planetTaxes[rightPartOfMutualAgreement[i]])
            {
                hash[rightPartOfMutualAgreement[i]] = hash[leftPartOfMutualAgreement[i]];
                // planet[rightPartOfMutualAgreement[i]].pointer = hash[leftPartOfMutualAgreement[i]];
            }
            else
            {
                hash[leftPartOfMutualAgreement[i]] = hash[rightPartOfMutualAgreement[i]];
                // planet[leftPartOfMutualAgreement[i]].pointer = hash[rightPartOfMutualAgreement[i]];
            }
        }
        System.out.println(((Hash)planet[2].pointer).value);
        System.out.println(hash[2].value);
    }
}
