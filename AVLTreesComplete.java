import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Node
{
    int value;
    int height;
    Node left;
    Node right;
}

class AVLTreesComplete
{
    public static Node returnAVLTree(Node root, int valueToBeInserted)
    {
        if (valueToBeInserted < root.value)
        {
            if(root.left.height != -1)
            {
                root.left = returnAVLTree(root.left, valueToBeInserted);
                int realDifference = Math.abs(root.left.height - root.right.height);
                if (realDifference > 1)
                {
                    if (root.left.height > root.right.height)
                    {
                        if (root.left.left.height > root.left.right.height)
                        {
                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                            Node tempNode1 = root.left.right;
                            Node tempNode2 = root.left.left;
                            Node swapNode = root;
                            root = root.left;
                            root.left = tempNode2;
                            root.right = swapNode;
                            root.right.height = root.right.height - 1;
                            root.right.left = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                        else
                        {
                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);

                            Node tempNode3 = root.left.right.left;
                            Node tempNode4 = root.left;
                            root.left = root.left.right;
                            root.left.height = root.left.height + 1;
                            root.left.left = tempNode4;
                            root.left.left.height = root.left.left.height - 1;
                            root.left.left.right = tempNode3;

                            Node tempNode1 = root.left.right;
                            Node tempNode2 = root.left.left;
                            Node swapNode = root;
                            root = root.left;
                            root.left = tempNode2;
                            root.right = swapNode;
                            root.right.height = root.right.height - 1;
                            root.right.left = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                    }
                    else
                    {
                        if (root.right.right.height > root.right.left.height)
                        {
                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);

                            Node tempNode1 = root.right.left;
                            Node tempNode2 = root.right.right;
                            Node swapNode = root;
                            root = root.right;
                            root.right = tempNode2;
                            root.left = swapNode;
                            root.left.height = root.left.height - 1;
                            root.left.right = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                        else
                        {

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);

                            Node tempNode3 = root.right.left.right;
                            Node tempNode4 = root.right;
                            root.right = root.right.left;
                            root.right.height = root.right.height + 1;
                            root.right.right = tempNode4;
                            root.right.right.height = root.right.right.height - 1;
                            root.right.right.left = tempNode3;

                            Node tempNode1 = root.right.left;
                            Node tempNode2 = root.right.right;
                            Node swapNode = root;
                            root = root.right;
                            root.right = tempNode2;
                            root.left = swapNode;
                            root.left.height = root.left.height - 1;
                            root.left.right = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                    }
                }
                int leftSubTreeHeight = root.left.height;
                int rightSubTreeHeight = root.right.height;
                if(leftSubTreeHeight > rightSubTreeHeight)
                {
                    root.height = leftSubTreeHeight + 1;
                }
                else
                {
                    root.height = rightSubTreeHeight + 1;
                }
                return root;
            }
            else
            {
                root.left = new Node();
                root.left.height = 0;
                root.left.value = valueToBeInserted;
                root.left.left = new Node();
                root.left.right = new Node();
                root.left.left.height = -1;
                root.left.right.height = -1;

                System.out.println("The root.left.value is: " + root.left.value);
                System.out.println("The root.right.value is: " + root.right.value);

                int leftSubTreeHeight = root.left.height;
                int rightSubTreeHeight = root.right.height;
                if(leftSubTreeHeight > rightSubTreeHeight)
                {
                    root.height = leftSubTreeHeight + 1;
                }
                else
                {
                    root.height = rightSubTreeHeight + 1;
                }
                return root;
            }
        }
        else
        {
            if(root.right.height != -1)
            {
                root.right = returnAVLTree(root.right, valueToBeInserted);
                int realDifference = Math.abs(root.left.height - root.right.height);
                if (realDifference > 1)
                {
                    if (root.left.height > root.right.height)
                    {
                        if (root.left.left.height > root.left.right.height)
                        {
                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                            Node tempNode1 = root.left.right;
                            Node tempNode2 = root.left.left;
                            Node swapNode = root;
                            root = root.left;
                            root.left = tempNode2;
                            root.right = swapNode;
                            root.right.height = root.right.height - 1;
                            root.right.left = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                        else
                        {
                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);

                            Node tempNode3 = root.left.right.left;
                            Node tempNode4 = root.left;
                            root.left = root.left.right;
                            root.left.height = root.left.height + 1;
                            root.left.left = tempNode4;
                            root.left.left.height = root.left.left.height - 1;
                            root.left.left.right = tempNode3;

                            Node tempNode1 = root.left.right;
                            Node tempNode2 = root.left.left;
                            Node swapNode = root;
                            root = root.left;
                            root.left = tempNode2;
                            root.right = swapNode;
                            root.right.height = root.right.height - 1;
                            root.right.left = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                    }
                    else
                    {
                        if (root.right.right.height > root.right.left.height)
                        {

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);

                            Node tempNode1 = root.right.left;
                            Node tempNode2 = root.right.right;
                            Node swapNode = root;
                            root = root.right;
                            root.right = tempNode2;
                            root.left = swapNode;
                            root.left.height = root.left.height - 1;
                            root.left.right = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                        else
                        {

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);

                            Node tempNode3 = root.right.left.right;
                            Node tempNode4 = root.right;
                            root.right = root.right.left;
                            root.right.height = root.right.height + 1;
                            root.right.right = tempNode4;
                            root.right.right.height = root.right.right.height - 1;
                            root.right.right.left = tempNode3;

                            Node tempNode1 = root.right.left;
                            Node tempNode2 = root.right.right;
                            Node swapNode = root;
                            root = root.right;
                            root.right = tempNode2;
                            root.left = swapNode;
                            root.left.height = root.left.height - 1;
                            root.left.right = tempNode1;

                            System.out.println("root.left.height: " + root.left.height);
                            System.out.println("root.right.height: " + root.right.height);
                            System.out.println("root.left.value: " + root.left.value);
                            System.out.println("root.right.value: " + root.right.value);
                        }
                    }
                }
                int leftSubTreeHeight = root.left.height;
                int rightSubTreeHeight = root.right.height;
                if(leftSubTreeHeight > rightSubTreeHeight)
                {
                    root.height = leftSubTreeHeight + 1;
                }
                else
                {
                    root.height = rightSubTreeHeight + 1;
                }
                return root;
            }
            else
            {
                root.right = new Node();
                root.right.height = 0;
                root.right.value = valueToBeInserted;
                root.right.left = new Node();
                root.right.right = new Node();
                root.right.left.height = -1;
                root.right.right.height = -1;

                System.out.println("The root.left.value is: " + root.left.value);
                System.out.println("The root.right.value is: " + root.right.value);

                int leftSubTreeHeight = root.left.height;
                int rightSubTreeHeight = root.right.height;
                if (leftSubTreeHeight > rightSubTreeHeight)
                {
                    root.height = leftSubTreeHeight + 1;
                }
                else
                {
                    root.height = rightSubTreeHeight + 1;
                }
                return root;
            }
        }
    }

    public static Node inorder(Node root)
    {
        if(root.left.height != -1)
        {
            inorder(root.left);
        }
        System.out.println(root.value);
        if(root.right.height != -1)
        {
            inorder(root.right);
        }
        return root;
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int[] numbersToBeSorted = {3,45,67,23,69,98,457,567,1,7,349,123}; //hardcoded
        //int[] numbersToBeSorted = {45,23,12};
        //int[] numbersToBeSorted = {45,23,37};
        //int[] numbersToBeSorted = {23,37,45};
        //int[] numbersToBeSorted = {23,45,37};
        //int[] numbersToBeSorted = {3,45,67,23,69,98};
        int lengthOfTheArray = numbersToBeSorted.length;
        System.out.println(lengthOfTheArray);
        Node root = new Node();
        root.left = new Node();
        root.right = new Node();
        root.left.height = -1;
        root.right.height = -1;
        root.height = 0;
        root.value = numbersToBeSorted[0];
        //Making the AVL Tree

        for(int i = 1; i < lengthOfTheArray; i++)
        {
            int valueToBeInserted = numbersToBeSorted[i];
            root = returnAVLTree(root, valueToBeInserted);
            System.out.println(root.value);
            System.out.println(root.left.value);
            System.out.println(root.right.value);
            System.out.println(root.height);
            System.out.println("*******");
        }

        inorder(root);
    }
}
