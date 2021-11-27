import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Node
{
    int value;
    Node pointer;
}

class SelfAssignTest
{
    public static void main(String[] args)
    {
        Node[] nodeArray = new Node[3];
        for(int i = 0; i < 3; i++)
        {
            nodeArray[i] = new Node();
            nodeArray[i].value = i;
            nodeArray[i].pointer = nodeArray[i];
        }

        for(int i = 0; i < 3; i++)
        {
            System.out.println(nodeArray[i].pointer.value);
        }
    }
}
