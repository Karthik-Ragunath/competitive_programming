import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;


class Node
{
    int value;
}
class ClassArray
{
    public static void main(String[] args)
    {
        Node[] nodeArray = new Node[5];
        for(int i = 0; i < 5; i++)
        {
            nodeArray[i] = new Node();
            nodeArray[i].value = i;
        }

        nodeArray[2] = nodeArray[4];
        System.out.println(nodeArray[2].value);
        System.out.println(nodeArray[4].value);
    }
}
