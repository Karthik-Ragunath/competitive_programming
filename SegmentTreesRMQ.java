import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class Node
{
    int right;
    int left;
    int value;
    Node leftChild;
    Node rightChild;
}
class SegmentTreesRMQ
{
    public static Node buildMaxSegmentTrees(int[] terms, int left, int right)
    {
        Node node = new Node();
        node.left = left;
        node.right = right;
        if(left == right)
        {
            node.value = terms[left];
            node.leftChild = null;
            node.rightChild = null;
        }
        else
        {
            node.leftChild = buildMaxSegmentTrees(terms, left, (left + right)/2);
            node.rightChild = buildMaxSegmentTrees(terms, (left + right)/2 + 1, right);
            if(node.leftChild.value >= node.rightChild.value)
            {
                node.value = node.leftChild.value;
            }
            else
            {
                node.value = node.rightChild.value;
            }
        }
        return node;
    }

    public static Node buildMinSegmentTrees(int[] terms, int left, int right)
    {
        Node node = new Node();
        node.left = left;
        node.right = right;
        if(left == right)
        {
            node.value = terms[left];
            node.leftChild = null;
            node.rightChild = null;
        }
        else
        {
            node.leftChild = buildMinSegmentTrees(terms, left, (left + right)/2);
            node.rightChild = buildMinSegmentTrees(terms, (left + right)/2 + 1, right);
            if(node.leftChild.value <= node.rightChild.value)
            {
                node.value = node.leftChild.value;
            }
            else
            {
                node.value = node.rightChild.value;
            }
        }
        return node;
    }

    public static int buildRangeMinimumQuery(Node root, int left, int right, int leftRange, int rightRange)
    {
        if(leftRange <= left && rightRange >= right)
        {
            return root.value;
        }
        else
        {
            int leftMinimum = 18000;
            int rightMinimum = 18000;
            if(root.leftChild.right >= leftRange)
            {
                leftMinimum = buildRangeMinimumQuery(root.leftChild, left, (left + right)/2, leftRange, rightRange);
            }
            if(rightRange >= root.rightChild.left)
            {
                rightMinimum = buildRangeMinimumQuery(root.rightChild, (left + right)/2 + 1, right, leftRange, rightRange);
            }
            if(leftMinimum <= rightMinimum)
            {
                return leftMinimum;
            }
            else
            {
                return rightMinimum;
            }
        }
    }

    public static int buildRangeMaximumQuery(Node root, int left, int right, int leftRange, int rightRange)
    {
        if(leftRange <= left && rightRange >= right)
        {
            return root.value;
        }
        else
        {
            int leftMaximum = -18000;
            int rightMaximum = -18000;
            if(root.leftChild.right >= leftRange)
            {
                leftMaximum = buildRangeMaximumQuery(root.leftChild, left, (left + right)/2, leftRange, rightRange);
            }
            if(rightRange >= root.rightChild.left)
            {
                rightMaximum = buildRangeMaximumQuery(root.rightChild, (left + right)/2 + 1, right, leftRange, rightRange);
            }
            if(leftMaximum >= rightMaximum)
            {
                return leftMaximum;
            }
            else
            {
                return rightMaximum;
            }
        }
    }

    public static void main(String[] args)
    {
        int numberOfTerms;
        Scanner in = new Scanner(System.in);
        numberOfTerms = in.nextInt();
        int[] terms = new int[numberOfTerms];
        for(int i = 0; i < numberOfTerms; i++)
        {
            terms[i] = in.nextInt();
        }
        int left = 0;
        int right = numberOfTerms - 1;
        Node root = buildMinSegmentTrees(terms, left, right);
        int numberOfQueries = in.nextInt();
        for(int i = 0; i < numberOfQueries; i++)
        {
            int leftMin = in.nextInt();
            int rightMax = in.nextInt();
            int answer = buildRangeMinimumQuery(root, left, right, leftMin - 1, rightMax - 1);
            System.out.println(answer);
        }
    }
}
