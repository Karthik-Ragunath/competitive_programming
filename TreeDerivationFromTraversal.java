import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Node
{
    int value;
    Node left;
    Node right;
}

class TreeDerivationFromTraversal
{

    static int preorderIndex = 0;

    public static Node buildTree(char[] inorder, char[] preorder, int min, int max)
    {
        if(min > max)
        {
            return null; //Acts as left and right child of leaves.
        }
        Node root = new Node();
        root.value = preorder[preorderIndex++];
        if(min == max)
        {
            return root;
        }
        int inorderIndex = returnInorderIndex(inorder, min, max, root.value);
        if(inorderIndex != -1)
        {
            root.left = buildTree(inorder, preorder, min, inorderIndex - 1);
            root.right = buildTree(inorder, preorder, inorderIndex + 1, max);
        }
        return root;
    }

    public static void printInorderTraversal(Node root)
    {
        if(root.left != null)
        {
            printInorderTraversal(root.left);
        }
        char value = (char)root.value; //If input is in terms of characters and not integers
        System.out.println(value);
        if(root.right != null)
        {
            printInorderTraversal(root.right);
        }
    }

    public static int returnInorderIndex(char[] inorder, int min, int max, int searchValue)
    {
        for(int i = min; i <= max; i++)
        {
            if(inorder[i] == searchValue)
            {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args)
    {
        char[] inorder = {'D','B','E','A','F','C'};
        char[] preorder = {'A','B','D','E','C','F'};
        int length = inorder.length;

        Node root = buildTree(inorder, preorder, 0, length - 1);
        printInorderTraversal(root);
    }
}
