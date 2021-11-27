import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Node
{
    int parent;
    int edgeCost;
    int index;
    int subtreeSize = 1;
    int level;
    int section;
    ArrayList<Node> children = new ArrayList<Node>();
    int ancestorInPreviousSection;
    int chainIndex;
    int positionInChainIndex;
}

class MaxLevelMaintainer
{
    int maxValue;
}

class QTREE
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

    public static void LCA(int x, int y, Node[] node)
    {
        //Inorder to ensure that both x and y are in the same section
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
    }

    public static int heavyLightDecomposition(Node[] node, int numberOfNodes, int[] chainHeadArray, int chainNumber, int currentIndex, int[] chainSize)
    {
        if(chainHeadArray[chainNumber] == -1)
        {
            chainHeadArray[chainNumber] = currentIndex;
        }
        node[currentIndex].chainIndex = chainNumber;
        node[currentindex].positionInChainIndex = chainSize[chainNumber];
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
            chainNumber = heavyLightDecomposition(node, numberOfNodes, chainHeadArray, chainNumber, specialChildIndex, chainSize);
        }

        if(childrenPresent)
        {
            for(int i = 0; i < numberOfChildrenOfCurrentNode; i++)
            {
                if(i != specialChildIndex)
                {
                    chainNumber++;
                    Node childNode = node[currentIndex].children.get(i);
                    int indexOfChildNode = childNode.index;
                    chainNumber = currentChaiheavyLightDecomposition(node, numberOfNodes, chainHeadArray, chainNumber, indexOfChildNode, chainSize);
                }
            }
        }
        return chainNumber;
    }

    public static void main(String[] args)
    {
        int numberOfTestCases;
        Scanner in = new Scanner(System.in);
        numberOfTestCases = in.nextInt();
        for(int i = 0; i < numberOfTestCases; i++)
        {
            int numberOfNodes = in.nextInt();
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
                node[oneEndOfEdge].edgeCost = edgeCost;
                node[otherEndOfEdge].edgeCost = edgeCost;
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

            // HeavyLightDecomposition
            int chainNumber = 1;
            int[] chainHeadArray = new int[numberOfNodes + 1];
            //We initialize all the variables in chainHeadArray to -1 inorder to differentiate between Leafnodes and childNodes.
            for(int j = 1; j <= numberOfNodes; j++)
            {
                chainHeadArray[j] = -1;
            }
            int[] chainSize = new int[numberOfNodes + 1];
            int currentIndexOfChain = 1;
            int numberOfChains = heavyLightDecomposition(node, numberOfNodes, chainHeadArray, chainNumber, currentIndexOfChain, chainSize);
        }
    }
}
