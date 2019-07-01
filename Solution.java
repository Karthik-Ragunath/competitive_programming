import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class Node
{
    int data;
    Node left;
    Node right;
}

class Solution
{
    boolean checkBST(Node root)
    {
        Node isBST = new Node();
        isBST.data = 1;
        isBST.left = null;
        isBST.right = null;
        int answer = new Solution().recurse(root, isBST);
        //System.out.println(answer);
        if(isBST.data != 0)
        {
            //System.out.println(answer);
            return true;
        }
        else
        {
            //System.out.println(answer);
            return false;
        }
    }

    int recurse(Node root, Node isBST)
    {
        if (isBST.data != 0)
        {
            //System.out.println(root.data);
            if(root.left != null)
            {
                //System.out.println(root.left.data);
                //System.out.println(isBST.data);
                int left = new Solution().recurse(root.left, isBST);
                //System.out.println(left);
                //System.out.println(isBST.data);
                if (isBST.data != 0)
                {
                    if (left > root.data)
                    {
                        isBST.data = 0;
                        System.out.println(left);
                        return 0;
                    }
                }
                else
                {
                    //isBST.data = 0;
                    return 0;
                }
            }

            if (root.right != null)
            {
                //System.out.println(root.right.data);
                //System.out.println(isBST.data);
                int right = new Solution().recurse(root.right, isBST);
                //System.out.println(right);
                //System.out.println(isBST.data);

                if(isBST.data != 0)
                {
                    if(right < root.data)
                    {
                        isBST.data = 0;
                        System.out.println(right);
                        return 0;
                    }
                }
                else
                {
                    //isBST.data = 0;
                    return 0;
                }
            }

            return root.data;
        }
        else
        {
            //isBST.data = 0;
            return 0;
        }
    }

    public static void main(String[] args)
    {
        Node root = new Node();
        root.data = 5;

        root.left = new Node();
        root.left.left = new Node();
        root.left.right = new Node();
        root.left.left.left = null;
        root.left.left.right = null;
        root.left.right.left = null;
        root.left.right.right = null;

        root.right = new Node();
        root.right.left = new Node();
        root.right.right = new Node();
        root.right.left.left = null;
        root.right.left.right = null;
        root.right.right.left = null;
        root.right.right.right = null;

        root.left.data = 100;
        root.left.left.data = 1002;
        root.left.right.data = 8;

        root.right.data = 2;
        root.right.left.data = 5;
        root.right.right.data = 1;

        boolean solution = new Solution().checkBST(root);
        if (solution == true)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}
