import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
        int numberofbuildings;
        Scanner in=new Scanner(System.in);
        numberofbuildings=in.nextInt();
        int[] buildingheights=new int[numberofbuildings];
        int j=0;
        int amountofmemoryneeded=(numberofbuildings*(numberofbuildings+1))/2;
        int maximumheight=0;
        int[] dynamicsolution=new int[amountofmemoryneeded];
        for(int i=0;i<numberofbuildings;i++)
        {
            buildingheights[i]=in.nextInt();
            for(j=0;j<=i;j++)
            {
                if(j==i)
                {
                    dynamicsolution[j]=buildingheights[i];
                        System.out.println("dynmaic solution of "+j+" and pos "+i+" is :"+dynamicsolution[j]);
                    if(dynamicsolution[j]>maximumheight)
                    {
                        maximumheight=dynamicsolution[j];
                            System.out.println("inside first if of "+i+" :maxheight height "+maximumheight);
                    }
                }
                else
                {
                    if(buildingheights[j]<=buildingheights[i])
                    {
                        dynamicsolution[j]=buildingheights[j]+dynamicsolution[j];
                            System.out.println("dynmaic solution of "+j+" and pos "+i+" is :"+dynamicsolution[j]);
                        if(dynamicsolution[j]>maximumheight)
                        {
                            maximumheight=dynamicsolution[j];
                                System.out.println("inside second if of "+i+" :maxheight height "+maximumheight);
                        }
                    }
                    else
                    {
                        dynamicsolution[j]=buildingheights[i]*(i-j+1);
                        buildingheights[j]=buildingheights[i];
                            System.out.println("dynmaic solution of "+j+" and pos "+i+" is :"+dynamicsolution[j]);
                        if(dynamicsolution[j]>maximumheight)
                        {
                            maximumheight=dynamicsolution[j];
                                System.out.println("inside third if of "+i+" :maxheight height "+maximumheight);
                        }
                    }
                }
            }
        }
        System.out.println(maximumheight);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}