import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class Node
{
    int key;
    int value;
    Node left;
    Node right;
    Node parent;
}

class ImplicitSplayTrees
{
    public static Node insert(Node root, Node nodeToBeInserted)
    {
        if (nodeToBeInserted.key < root.key)
        {
            if (root.left != null)
            {
                root.left = insert(root.left, nodeToBeInserted);
            }
            else
            {
                root.left = nodeToBeInserted;
                nodeToBeInserted.parent = root;
            }
        }
        else
        {
            if (root.right != null)
            {
                root.right = insert(root.right, nodeToBeInserted);
            }
            else
            {
                root.right = nodeToBeInserted;
                nodeToBeInserted.parent = root;
            }
        }
        return root;
    }


    public static Node[] leftSplit(Node root)
    {
        Node[] leftAndRightParts = new Node[2];
        leftAndRightParts[0] = root.left;
        root.left = null;
        leftAndRightParts[1] = root;
        return leftAndRightParts;
    }

    public static Node[] rightSplit(Node root, int value, Node rightNode)
    {
        Node[] leftAndRightParts = new Node[2];
        if (value == root.key)
        {
            rightNode = root.right;
            leftAndRightParts[0] = root;
            leftAndRightParts[1] = rightNode;
            root.right = null;
        }
        else
        {
            leftAndRightParts = rightSplit(root.right, value, rightNode);
            leftAndRightParts[0] = root;
        }
        return leftAndRightParts;
    }

    public static Node append(Node root1, Node root2)
    {
        if(root1.right != null)
        {
            root1.right = append(root1.right, root2);
        }
        else
        {
            root1.right = root2;
        }
        return root1;
    }

    public static Node join(Node root1, Node root2)
    {
        if(root1 != null)
        {
            Node nodeToBeSwapped1 = root1.right;
            Node nodeToBeSwapped2 = root2.left;
            root1.right = root2;
            root1.right.left = nodeToBeSwapped1;
            if (root1.right.left != null)
            {
                root1.right.left = append(root1.right.left, nodeToBeSwapped2);
            }
        }
        return root1;
    }

    public static Node splay(Node root, int keyToBeSplayed, Node nodeToBeSplayed)
    {
        if (keyToBeSplayed < root.key)
        {
            nodeToBeSplayed = splay(root.left, keyToBeSplayed, nodeToBeSplayed);
            // Swap root and nodeToBeDisplayed(root.left) such that nodeToBeDisplayed is in root's position and nodeToDisplayed's right child is root.
            // Follow conventional AVL rotations.
            Node nodeToBeSwapped1 = nodeToBeSplayed.right;
            Node nodeToBeSwapped2 = root;
            root = nodeToBeSplayed;
            root.right = nodeToBeSwapped2;
            root.right.left = nodeToBeSwapped1;
        }
        else if (keyToBeSplayed > root.key)
        {
            nodeToBeSplayed = splay(root.right, keyToBeSplayed, nodeToBeSplayed);
            // Swap root and nodeToBeDisplayed(root.right) such that nodeToDisplayed's left child is root.
            // Follow conventional AVL rotations.
            Node nodeToBeSwapped1 = nodeToBeSplayed.left;
            Node nodeToBeSwapped2 = root;
            root = nodeToBeSplayed;
            root.left = nodeToBeSwapped2;
            root.left.right = nodeToBeSwapped1;
        }
        else
        {
            nodeToBeSplayed = root;
        }

        return root;
    }


    public static Node keySetter(Node root, Node valueSetter)
    {
        if (root.left != null)
        {
            keySetter(root.left, valueSetter);
        }
        root.key = valueSetter.value;
        valueSetter.value = valueSetter.value + 1;
        if(root.right != null)
        {
            keySetter(root.right, valueSetter);
        }
        return root;
    }

    public static void keyAndValuePrinter(Node root, Node elementCounter)
    {
        if (root.left != null)
        {
            keyAndValuePrinter(root.left, elementCounter);
        }
        System.out.println("The key and value of element No. "+ elementCounter.value + " is : " + root.key + " and " + root.value);
        elementCounter.value = elementCounter.value + 1;
        if (root.right != null)
        {
            keyAndValuePrinter(root.right, elementCounter);
        }
    }

    public static int solutionPrinter(Node root, Node valueSetter, int initialNumber, int finalNumber, Node initialNode, Node finalNode, int solution)
    {
        if (root.left != null)
        {
            solution = solutionPrinter(root.left, valueSetter, initialNumber, finalNumber, initialNode, finalNode, solution);
        }
        if (valueSetter.value == 1)
        {
            initialNode.value = root.value;
        }
        else if (valueSetter.value == finalNumber)
        {
            finalNode.value = root.value;
            solution = Math.abs(finalNode.value - initialNode.value);
        }
        valueSetter.value = valueSetter.value + 1;
        if (root.right != null)
        {
            solution = solutionPrinter(root.right, valueSetter, initialNumber, finalNumber, initialNode, finalNode, solution);
        }
        return solution;
    }

    public static void resultingArray(Node root)
    {
        if (root.left != null)
        {
            resultingArray(root.left);
        }
        System.out.print(root.value + " ");
        if (root.right != null)
        {
            resultingArray(root.right);
        }
    }

    public static Node makeLeftMostPartAsNode(Node root, Node valueChecker, Node nodeToBeReturned)
    {
        if (root.left != null)
        {
            nodeToBeReturned = makeLeftMostPartAsNode(root.left, valueChecker, nodeToBeReturned);
            return nodeToBeReturned;
        }
        if (valueChecker.value == 1)
        {
            nodeToBeReturned = root;
            valueChecker.value = valueChecker.value + 1;
            return nodeToBeReturned;
        }
        return nodeToBeReturned;
    }

    public static void main(String[] args)
    {
        int numberOfValues;
        int numberOfQueries;
        Node root = new Node();
        Node valueMaintainer = new Node();
        Scanner in = new Scanner(System.in);
        numberOfValues = in.nextInt();
        numberOfQueries = in.nextInt();
        int[] values = new int[numberOfValues];
        for(int i = 0; i < numberOfValues; i++)
        {
            values[i] = in.nextInt();
            if (i == 0)
            {
                root.key = i + 1;
                root.value = values[i];
                root.left = null;
                root.right = null;
                root.parent = null;
            }
            else
            {
                Node newNode = new Node();
                newNode.value = values[i];
                newNode.key = i + 1;
                newNode.left = null;
                newNode.right = null;
                newNode.parent = null;
                root = insert(root, newNode);
            }
        }
        String[] queries = new String[numberOfQueries];
        in.nextLine();
        for(int i = 0; i < numberOfQueries; i++)
        {
            queries[i] = in.nextLine();
        }
        int[][] queryValues = new int[numberOfQueries][3];
        for(int i = 0; i < numberOfQueries; i++)
        {
            String[] splittedString = queries[i].split(" ");
            for(int j = 0; j < splittedString.length; j++)
            {
                queryValues[i][j] = Integer.parseInt(splittedString[j]);
            }
        }
        for(int i = 0; i < numberOfQueries; i++)
        {
            int startingKeyIndex = queryValues[i][1];
            int endingKeyIndex = queryValues[i][2];
            Node nodeToBeSplayed = new Node();
            root = splay(root, startingKeyIndex, nodeToBeSplayed);

            Node[] leftAndRightParts = leftSplit(root);
            Node leftPart = leftAndRightParts[0];
            root = leftAndRightParts[1];

            nodeToBeSplayed = new Node();
            if (endingKeyIndex != numberOfValues)
            {
                root = splay(root, endingKeyIndex + 1, nodeToBeSplayed);
            }

            Node[] rightEndSplit = leftSplit(root);
            valueMaintainer.value = 1;
            Node newNode = new Node();
            Node oldRoot = makeLeftMostPartAsNode(rightEndSplit[0], valueMaintainer, newNode);
            root = rightEndSplit[1];

            if (leftPart != null)
            {
                root = join(leftPart, root);
            }

            if (queryValues[i][0] == 1)
            {
                root = join(oldRoot, root);
            }
            else
            {
                root = append(root, oldRoot);
            }
            valueMaintainer.value = 1;
            keySetter(root, valueMaintainer);

        }
        int initialNumber = 1;
        int finalNumber = numberOfValues;
        int solution = -789;
        Node initialNode = new Node();
        Node finalNode = new Node();
        valueMaintainer.value = 1;
        solution = solutionPrinter(root, valueMaintainer, initialNumber, finalNumber, initialNode, finalNode, solution);
        System.out.println(solution);
        resultingArray(root);

    }
}
