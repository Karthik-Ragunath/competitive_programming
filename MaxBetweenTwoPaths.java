import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Node
{
    int parent;
    int index;
    int subtreeSize = 1;
    int level;
    int section;
    ArrayList<Node> children = new ArrayList<Node>();
    int ancestorInPreviousSection;
    int chainIndex;
    int positionInChainIndex;
    int maxUptoThatPoint;
}

class MaxLevelMaintainer
{
    int maxValue;
}

class MaxBetweenTwoPaths
{
    public static int DFS(Node[] node, boolean[] visited, int currentIndex, int level, MaxLevelMaintainer maxLevelMaintainer)
    {
        visited[currentIndex] = true;
        node[currentIndex].level = ++level;
        if(level > maxLevelMaintainer.maxValue)
        {
            maxLevelMaintainer.maxValue = level;
        }
        Iterator iterator = node[currentIndex].children.iterator();
        while(iterator.hasNext())
        {
            Node childNode = (Node)(iterator.next());
            int childIndex = childNode.index;
            if(!visited[childIndex])
            {
                childNode.parent = currentIndex;
                node[currentIndex].subtreeSize = node[currentIndex].subtreeSize + DFS(node, visited, childIndex, level, maxLevelMaintainer);
            }
            else
            {
                iterator.remove();
            }
        }
        return node[currentIndex].subtreeSize;
    }

    public static void assignAncestors(Node[] node, int numberOfNodes)
    {
        for(int i = 1; i <= numberOfNodes; i++)
        {
            if(node[i].section == 1)
            {
                node[i].ancestorInPreviousSection = 1;
            }
            else
            {
                int j = i;
                int parentNodeIndex = node[j].parent;
                //Loop till currentNode's parent's section and current Node's section are different.
                while(node[parentNodeIndex].section == node[j].section)
                {
                    j = node[j].parent;
                    parentNodeIndex = node[j].parent;
                }
                node[i].ancestorInPreviousSection = parentNodeIndex;
            }
        }
    }

    public static int LCA(int x, int y, Node[] node)
    {
        //Inorder to ensure that both x and y are in the same section in such a way that when they are in section, their ancestors in previous section is same (Thus, not being in same section isnt enough for the first while loop to break)
        while(node[x].ancestorInPreviousSection != node[y].ancestorInPreviousSection)
        {
            if(node[x].level > node[y].level)
            {
                x = node[x].ancestorInPreviousSection;
            }
            else
            {
                y = node[y].ancestorInPreviousSection;
            }
        }

        //Inorder to ensure that both x and y refer to the same node which is the LCA
        while(x != y)
        {
            if(node[x].level > node[y].level)
            {
                x = node[x].parent;
            }
            else
            {
                y = node[y].parent;
            }
        }

        return x;
    }

    public static int heavyLightDecomposition(Node[] node, int numberOfNodes, int[] chainHeadArray, int chainNumber, int currentIndex, int[] chainSize, int[] maximumValueOfChains, int[][] costs)
    {
        System.out.println("Top: " + chainNumber);
        if(chainHeadArray[chainNumber] == -1)
        {
            chainHeadArray[chainNumber] = currentIndex;
        }

        System.out.println("Current Index: " + currentIndex);
        node[currentIndex].chainIndex = chainNumber;
        System.out.println("Chain Size: " + chainSize[chainNumber]);
        node[currentIndex].positionInChainIndex = chainSize[chainNumber];
        chainSize[chainNumber]++;
        int numberOfChildrenOfCurrentNode = node[currentIndex].children.size();
        boolean childrenPresent = false;
        int specialChildIndex = -1;
        int specialChildIndexSubtreeSize = -1;
        for(int i = 0; i < numberOfChildrenOfCurrentNode; i++)
        {
            childrenPresent = true;
            Node childNode = node[currentIndex].children.get(i);
            int indexOfChildNode = childNode.index;
            if(node[indexOfChildNode].subtreeSize > specialChildIndexSubtreeSize)
            {
                specialChildIndex = indexOfChildNode;
                specialChildIndexSubtreeSize = node[indexOfChildNode].subtreeSize;
            }
        }

        if(childrenPresent)
        {
            if(maximumValueOfChains[chainNumber] < costs[currentIndex][specialChildIndex])
            {
                maximumValueOfChains[chainNumber] = costs[currentIndex][specialChildIndex];
                node[currentIndex].maxUptoThatPoint = costs[currentIndex][specialChildIndex];
                node[specialChildIndex].maxUptoThatPoint = costs[currentIndex][specialChildIndex];
            }
            else
            {
                node[currentIndex].maxUptoThatPoint = maximumValueOfChains[chainNumber];
                node[specialChildIndex].maxUptoThatPoint = maximumValueOfChains[chainNumber];
            }
            chainNumber = heavyLightDecomposition(node, numberOfNodes, chainHeadArray, chainNumber, specialChildIndex, chainSize, maximumValueOfChains, costs);
        }

        if(childrenPresent)
        {
            for(int i = 0; i < numberOfChildrenOfCurrentNode; i++)
            {
                Node childNode = node[currentIndex].children.get(i);
                int indexOfChildNode = childNode.index;
                if(indexOfChildNode != specialChildIndex)
                {
                    chainNumber++;
                    chainNumber = heavyLightDecomposition(node, numberOfNodes, chainHeadArray, chainNumber, indexOfChildNode, chainSize, maximumValueOfChains, costs);
                }
            }
        }
        return chainNumber;
    }


    public static int returnMaxInThePath(int x, int y, Node[] node, int maxValue, int[] chainHeadArray, int[][] costs)
    {
        int chainNumberX = node[x].chainIndex;
        int chainNumberY = node[y].chainIndex;
        if(chainNumberX != chainNumberY)
        {
            int chainXMaxUptoThatPointInTheChain = node[x].maxUptoThatPoint;
            int chainHeadIndex = chainHeadArray[chainNumberX];
            int parentIndexOfChainX = node[chainHeadIndex].parent;
            int chainSwitchingEdgeValue = costs[chainHeadIndex][parentIndexOfChainX];
            int valueToCompareWithMaxValue;
            if(chainSwitchingEdgeValue > chainXMaxUptoThatPointInTheChain)
            {
                valueToCompareWithMaxValue = chainSwitchingEdgeValue;
            }
            else
            {
                valueToCompareWithMaxValue = chainXMaxUptoThatPointInTheChain;
            }
            if(maxValue < valueToCompareWithMaxValue)
            {
                maxValue = valueToCompareWithMaxValue;
            }
            maxValue = returnMaxInThePath(parentIndexOfChainX, y, node, maxValue, chainHeadArray, costs);
        }
        else
        {
            int maxValueUptoThatPoint = node[x].maxUptoThatPoint;
            if(maxValue < maxValueUptoThatPoint)
            {
                maxValue = maxValueUptoThatPoint;
            }
        }
        return maxValue;
    }

    public static int getTheMaxValueInThePathBetweenTwoPoints(int x, int y, Node[] node, int maxValue, int[] chainHeadArray, int[][] costs)
    {
        int LCAValue = LCA(x, y, node);
        int range1 = returnMaxInThePath(x, LCAValue, node, maxValue, chainHeadArray, costs);
        int range2 = returnMaxInThePath(y, LCAValue, node, maxValue, chainHeadArray, costs);
        System.out.println("Range 1 : " + range1 + " Range 2 : " + range2);
        if(range1 > range2)
        {
            return range1;
        }
        else
        {
            return range2;
        }
    }


    public static void main(String[] args)
    {
        int numberOfTestCases;
        Scanner in = new Scanner(System.in);
        numberOfTestCases = in.nextInt();
        for(int i = 0; i < numberOfTestCases; i++)
        {
            int numberOfNodes = in.nextInt();
            int[][] costs = new int[numberOfNodes + 1][numberOfNodes + 1];
            Node[] node = new Node[numberOfNodes + 1]; //numberOfEdges -> No. of node edges since it is an undirected graph
            for(int j = 1; j <= numberOfNodes; j++)
            {
                node[j] = new Node();
                node[j].index = j;
                if(j == 1)
                {
                    node[j].parent = j;
                }
            }

            for(int j = 1; j < numberOfNodes; j++)
            {
                int oneEndOfEdge = in.nextInt();
                int otherEndOfEdge = in.nextInt();
                int edgeCost = in.nextInt();
                node[oneEndOfEdge].children.add(node[otherEndOfEdge]);
                node[otherEndOfEdge].children.add(node[oneEndOfEdge]);
                costs[oneEndOfEdge][otherEndOfEdge] = edgeCost;
                costs[otherEndOfEdge][oneEndOfEdge] = edgeCost;
            }

            //Since the given is an undirected Acyclic connected graph, it is ure that all nodes will be connected. Therefore, node[0] can be safely assumed as root.
            boolean[] visited = new boolean[numberOfNodes + 1];
            int currentIndex = 1;
            int level = -1;
            MaxLevelMaintainer maxLevelMaintainer = new MaxLevelMaintainer();
            maxLevelMaintainer.maxValue = -1;
            DFS(node, visited,currentIndex, level, maxLevelMaintainer);

            System.out.println("---------After DFS---------");
            for(int j = 1; j <= numberOfNodes; j++)
            {
                System.out.println("Node: " + j + " Level: " + node[j].level + " SubtreeSize: " + node[j].subtreeSize);
            }

            int heightOfTheTree = maxLevelMaintainer.maxValue + 1;
            int numberOfSections = (int)(Math.ceil(heightOfTheTree));
            boolean[] sectionAssigned = new boolean[numberOfNodes + 1];
            int leftMaximum = 0;
            for(int k = 1; k <= numberOfSections; k++)
            {
                int rightMaximum = (int)(Math.floor((k * Math.sqrt(heightOfTheTree)) - 1));
                for(int j = 1; j <= numberOfNodes; j++)
                {
                    if(!sectionAssigned[j])
                    {
                        int currentLevel = node[j].level;
                        if(currentLevel >= leftMaximum && currentLevel <= rightMaximum)
                        {
                            node[j].section = k;
                            sectionAssigned[j] = true;
                        }
                    }
                }
            }

            System.out.println("---------Section Assignment---------");
            for(int j = 1; j <= numberOfNodes; j++)
            {
                System.out.println("Node: " + j + " Section Assigned: " + node[j].section);
            }

            System.out.println("---------Ancestor Assignment---------");
            assignAncestors(node, numberOfNodes);
            for(int j = 1; j <= numberOfNodes; j++)
            {
                System.out.println("Node: " + j + " Ancestor: " + node[j].ancestorInPreviousSection);
            }

            // HeavyLightDecomposition Technique
            System.out.println("--------Heavy Light Decomposition---------");
            int chainNumber = 1;
            int[] chainHeadArray = new int[numberOfNodes + 1];
            //We initialize all the variables in chainHeadArray to -1 inorder to differentiate between Leafnodes and childNodes.
            for(int j = 1; j <= numberOfNodes; j++)
            {
                chainHeadArray[j] = -1;
            }
            int[] chainSize = new int[numberOfNodes + 1];
            int[] maximumValueOfChains = new int[numberOfNodes + 1];
            for(int j = 1; j <= numberOfNodes; j++)
            {
                maximumValueOfChains[j] = -1;
            }
            int currentIndexOfChain = 1;
            int numberOfChains = heavyLightDecomposition(node, numberOfNodes, chainHeadArray, chainNumber, currentIndexOfChain, chainSize, maximumValueOfChains, costs);
            System.out.println("Number of chains: " + numberOfChains);
            System.out.println("---------Maximum value of chains--------");
            for(int j = 1; j <= numberOfChains; j++)
            {
                System.out.println("The maximum value of chain " + j + " : " + maximumValueOfChains[j]);
            }

            //LCA implementation
            System.out.println("----------LCA Implementation---------");
            int exampleCheck1 = LCA(4,7,node);
            System.out.println(exampleCheck1);
            int exampleCheck2 = LCA(7,14,node);
            System.out.println(exampleCheck2);
            int exampleCheck3 = LCA(16,14,node);
            System.out.println(exampleCheck3);

            System.out.println("----------Maximum Value of Nodes (Upto that point in the chain)---------");
            for(int j = 1; j <= numberOfNodes; j++)
            {
                System.out.println("The maximum value of node " + j + " is: " + node[j].maxUptoThatPoint);
            }

            System.out.println("----------Heads of the chain----------");
            for(int j = 1; j <= numberOfChains; j++)
            {
                System.out.println("The head of chain " + j + " is: " + chainHeadArray[j]);
            }


            // Return Max value in the path implementation
            /*
            int exampleX1 = 9;
            int exampleY1 = 22;
            int LCAExample1 = LCA(8, 22, node);
            int maxValue = -1;
            int range1 = returnMaxInThePath(exampleX1, LCAExample1, node, maxValue, chainHeadArray, costs);
            int range2 = returnMaxInThePath(exampleY1, LCAExample1, node, maxValue, chainHeadArray, costs);
            System.out.println("Range 1 : " + range1 + " Range 2 : " + range2);
            */
            System.out.println("-------Max between two points implementation-------");
            int X1 = 9;
            int Y1 = 22;
            int maxValue = -1;
            int maxInThePath = getTheMaxValueInThePathBetweenTwoPoints(X1, Y1, node, maxValue, chainHeadArray, costs);
            System.out.println("The maximum value between the two points are: " + maxInThePath);

            int X2 = 10;
            int Y2 = 14;
            int maxInThePath2 = getTheMaxValueInThePathBetweenTwoPoints(X2, Y2, node, maxValue, chainHeadArray, costs);
            System.out.println("The maximum value between the two points are: " + maxInThePath2);
        }
    }
}
