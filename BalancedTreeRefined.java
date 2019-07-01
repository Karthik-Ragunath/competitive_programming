import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

class Node
{
    int index;
    ArrayList<Node> children = new ArrayList<Node>();
    long weight;
    long cumulativeWeight;
    int level;
    int section;
    int parent;
    int ancestorInPreviousSection;
}

class MaxLevelMaintainer
{
    int value;
}

class BalancedForestRefined
{
    public static long dfs(Node[] treeConnections, int currentNodeIndex, int level, MaxLevelMaintainer maxLevelMaintainer, boolean[] visited)
    {
        treeConnections[currentNodeIndex].level = ++level;
        if(treeConnections[currentNodeIndex].level > maxLevelMaintainer.value)
        {
            maxLevelMaintainer.value = treeConnections[currentNodeIndex].level;
        }
        visited[currentNodeIndex] = true;
        Iterator childrenIterator = treeConnections[currentNodeIndex].children.iterator();
        while(childrenIterator.hasNext())
        {
            Node childNode = (Node)(childrenIterator.next());
            int nextNodeIndex = childNode.index;
            if(visited[nextNodeIndex] == true)
            {
                childrenIterator.remove();
            }
            else
            {
                treeConnections[nextNodeIndex].parent = currentNodeIndex;
                treeConnections[currentNodeIndex].cumulativeWeight = treeConnections[currentNodeIndex].cumulativeWeight + dfs(treeConnections, nextNodeIndex, level, maxLevelMaintainer, visited);
            }
        }
        return treeConnections[currentNodeIndex].cumulativeWeight;
    }

    //Finding LCA Implementation:
    public static int LCA(Node[] treeConnections, int x, int y)
    {
        while(treeConnections[x].ancestorInPreviousSection != treeConnections[y].ancestorInPreviousSection)
        {
            if(treeConnections[x].level > treeConnections[y].level)
            {
                x = treeConnections[x].ancestorInPreviousSection;
            }
            else
            {
                y = treeConnections[y].ancestorInPreviousSection;
            }
        }

        while(x != y)
        {
            if(treeConnections[x].level > treeConnections[y].level)
            {
                x = treeConnections[x].parent;
            }
            else
            {
                y = treeConnections[y].parent;
            }
        }

        return x;
    }

    public static void main(String[] args)
    {
        int testcases;
        Scanner in = new Scanner(System.in);
        testcases = in.nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int numberOfCoins = in.nextInt();
            long[] weightOfCoins = new long[numberOfCoins];

            boolean[] visited = new boolean[numberOfCoins + 1];

            Node[] treeConnections = new Node[numberOfCoins + 1];

            //Creating Nodes and assigning weigts and cumulative weights
            for(int j = 1; j <= numberOfCoins; j++)
            {
                long weight = in.nextLong();
                treeConnections[j] = new Node();
                treeConnections[j].weight = weight;
                treeConnections[j].index = j;
                treeConnections[j].cumulativeWeight = weight;
                if (j == 1)
                {
                    treeConnections[j].parent = 1;
                }
            }

            //Tree Creation Part
            for(int j = 1; j <= numberOfCoins - 1; j++)
            {
                int parentIndex = in.nextInt();
                int childIndex = in.nextInt();
                treeConnections[parentIndex].children.add(treeConnections[childIndex]);
                treeConnections[childIndex].children.add(treeConnections[parentIndex]);
            }


            MaxLevelMaintainer maxLevelMaintainer = new MaxLevelMaintainer();
            maxLevelMaintainer.value = -1;
            //DFS part -> Current node's weight plus the weight of the nodes in its subtrees are assigned as cumulative weight of a node.
            long cumulativeWeightOfTheWholeTree = dfs(treeConnections, 1, -1, maxLevelMaintainer, visited);

            //Next:
            //Remove all possible combinations of two nodes and find whether they form three trees in which two of those trees have the same weight.
            //Also try the possibility of cutting only once and creating two trees which have the same weight.
            //Use Lowest Comman Ancestor (Levelling Algorithm) inorder to check whether removed nodes, say, X and Y are such that
                //X is the LCA of Y and inturn root (1) is the LCA of X.
                    //In this case, Y = Y, X = X - Y, 1 = 1 - X
                //1 is LCA of X and Y and X is not the LCA of Y.
                    //In this case, 1 = (1 - X - Y), X = X, Y = Y
                //Cut X such that X = (1 - X), and hence new node to be added with a weight of X creates the required configuration.

            // LCA algorithm:
            // Dividing into sections:
            boolean[] levelsAssigned = new boolean[numberOfCoins + 1];
            int maximumNumberOfLevel = maxLevelMaintainer.value + 1;
            int numberOfSections = (int)(Math.ceil(Math.sqrt(maximumNumberOfLevel)));
            int leftMaximum = 0;
            for(double j = 1; j <= numberOfSections; j++)
            {
                int rightMaximum = (int)(Math.floor(((j * Math.sqrt(maximumNumberOfLevel)) - 1)));
                for(int k = 1; k <= numberOfCoins; k++)
                {
                    if(!levelsAssigned[k])
                    {
                        if(treeConnections[k].level >= leftMaximum && treeConnections[k].level <= rightMaximum)
                        {
                            treeConnections[k].section = (int)j;
                            levelsAssigned[k] = true;
                        }
                    }
                }
                leftMaximum = rightMaximum + 1;
            }

            //Assigning Ancestor in previous section values:
            for(int j = 1; j <= numberOfCoins; j++)
            {
                if(treeConnections[j].section == 1)
                {
                    treeConnections[j].ancestorInPreviousSection = 1;
                }
                else
                {
                    int k = j;
                    while(treeConnections[treeConnections[k].parent].section == treeConnections[k].section)
                    {
                        k = treeConnections[k].parent;
                    }
                    treeConnections[j].ancestorInPreviousSection = treeConnections[k].parent;
                }
            }

            //Finding LCA:
            //int lcaValue = LCA(treeConnections, x, y);

            boolean flagship = false;
            long minimumSolution = 10000000000L;
            for(int j = 2; j <= numberOfCoins; j++)
            {
                long cumulativeWeightOfTheGivenNode = treeConnections[j].cumulativeWeight;
                long reducedWeight = cumulativeWeightOfTheWholeTree - cumulativeWeightOfTheGivenNode;
                if(reducedWeight == cumulativeWeightOfTheGivenNode)
                {
                    long solution = cumulativeWeightOfTheGivenNode;
                    if (solution <= minimumSolution)
                    {
                        minimumSolution = solution;
                    }
                    flagship = true;
                }
                for(int k = j + 1; k <= numberOfCoins; k++)
                {
                    int lcaValue = LCA(treeConnections, j, k);
                    long tempWeight = treeConnections[k].cumulativeWeight;
                    if (lcaValue == j || lcaValue == k)
                    {
                        long firstTreeWeight;
                        if (lcaValue == j)
                        {
                            firstTreeWeight = cumulativeWeightOfTheWholeTree - cumulativeWeightOfTheGivenNode;
                        }
                        else
                        {
                            firstTreeWeight = cumulativeWeightOfTheWholeTree - tempWeight;
                        }
                        long secondTreeWeight;
                        long thirdTreeWeight;
                        if (lcaValue == j)
                        {
                            secondTreeWeight = cumulativeWeightOfTheGivenNode - tempWeight;
                            thirdTreeWeight = tempWeight;
                        }
                        else
                        {
                            secondTreeWeight = tempWeight - cumulativeWeightOfTheGivenNode;
                            thirdTreeWeight = cumulativeWeightOfTheGivenNode;
                        }

                        if (firstTreeWeight == secondTreeWeight || secondTreeWeight == thirdTreeWeight || thirdTreeWeight == firstTreeWeight)
                        {
                            if (firstTreeWeight == secondTreeWeight)
                            {
                                if (thirdTreeWeight <= firstTreeWeight)
                                {
                                    long solution = firstTreeWeight - thirdTreeWeight;
                                    if (solution < minimumSolution)
                                    {
                                        minimumSolution = solution;
                                    }
                                    flagship = true;
                                }
                            }
                            else if (secondTreeWeight == thirdTreeWeight)
                            {
                                if (firstTreeWeight <= secondTreeWeight)
                                {
                                    long solution = secondTreeWeight - firstTreeWeight;
                                    if (solution < minimumSolution)
                                    {
                                        minimumSolution = solution;
                                    }
                                    flagship = true;
                                }
                            }
                            else
                            {
                                if(secondTreeWeight <= thirdTreeWeight)
                                {
                                    long solution = thirdTreeWeight - secondTreeWeight;
                                    if (solution < minimumSolution)
                                    {
                                        minimumSolution = solution;
                                    }
                                    flagship = true;
                                }
                            }
                        }
                    }
                    else
                    {
                        long firstTreeWeight = cumulativeWeightOfTheWholeTree - cumulativeWeightOfTheGivenNode - tempWeight;
                        long secondTreeWeight = cumulativeWeightOfTheGivenNode;
                        long thirdTreeWeight = tempWeight;

                        if (firstTreeWeight == secondTreeWeight || secondTreeWeight == thirdTreeWeight || thirdTreeWeight == firstTreeWeight)
                        {
                            if (firstTreeWeight == secondTreeWeight)
                            {
                                if (thirdTreeWeight <= firstTreeWeight)
                                {
                                    long solution = firstTreeWeight - thirdTreeWeight;
                                    if (solution < minimumSolution)
                                    {
                                        minimumSolution = solution;
                                    }
                                    flagship = true;
                                }
                            }
                            else if (secondTreeWeight == thirdTreeWeight)
                            {
                                if (firstTreeWeight <= secondTreeWeight)
                                {
                                    long solution = secondTreeWeight - firstTreeWeight;
                                    if (solution < minimumSolution)
                                    {
                                        minimumSolution = solution;
                                    }
                                    flagship = true;
                                }
                            }
                            else
                            {
                                if(secondTreeWeight <= thirdTreeWeight)
                                {
                                    long solution = thirdTreeWeight - secondTreeWeight;
                                    if (solution < minimumSolution)
                                    {
                                        minimumSolution = solution;
                                    }
                                    flagship = true;
                                }
                            }
                        }
                    }
                }
            }
            if (flagship == false)
            {
                System.out.println("-1");
            }
            else
            {
                System.out.println(minimumSolution);
            }
        }
    }
}
