import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;


class Node
{
    ArrayList<Integer> weights = new ArrayList<Integer>();
    ArrayList<Integer> children = new ArrayList<Integer>();
    int distance;
}

/*
Better Data Structure would be to use the following
Class Edge
{
    int source;
    int destination;
    int weight;
}
*/

class BellmanFord
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfNodes = in.nextInt();
        int numberOfEdges = in.nextInt();
        Node[] node = new Node[numberOfNodes];
        for(int i = 0; i < numberOfNodes; i++)
        {
            node[i] = new Node();
            if(i == 0)
            {
                node[i].distance = 0;
            }
            else
            {
                node[i].distance = 7777;
            }
        }
        for(int i = 0; i < numberOfEdges; i++)
        {
            int source = in.nextInt();
            int destination = in.nextInt();
            int weight = in.nextInt();
            node[source].children.add(destination);
            node[source].weights.add(weight);
        }
        for(int k = 0; k < numberOfNodes - 1; k++)
        {
            for(int i = 0; i < numberOfNodes; i++)
            {
                int numberOfChildren = node[i].children.size();
                for(int j = 0; j < numberOfChildren; j++)
                {
                    int childIndex = node[i].children.get(j);
                    int weightOfTheEdge = node[i].weights.get(j);
                    if(node[childIndex].distance > node[i].distance + weightOfTheEdge)
                    {
                        node[childIndex].distance = node[i].distance + weightOfTheEdge;
                    }
                }
            }
        }

        System.out.println("After N-1 iterations: The distance of Nodes are: ");
        for(int i = 0; i < numberOfNodes; i++)
        {
            int distance = node[i].distance;
            System.out.println("The distance of Node " + i + " is : " + distance);
        }
        for(int i = 0; i < numberOfNodes; i++)
        {
            int numberOfChildren = node[i].children.size();
            for(int j = 0; j < numberOfChildren; j++)
            {
                int childIndex = node[i].children.get(j);
                int weightOfTheEdge = node[i].weights.get(j);
                if(node[childIndex].distance > node[i].distance + weightOfTheEdge)
                {
                    node[childIndex].distance = node[i].distance + weightOfTheEdge;
                    System.out.println("The graph contains acyclic edges");
                }
            }
        }
        System.out.println("After N iterations: The distance of Nodes are: ");
        for(int i = 0; i < numberOfNodes; i++)
        {
            int distance = node[i].distance;
            System.out.println("The distance of Node " + i + " is : " + distance);
        }
    }
}
