#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <array>
#include <queue>
#include <sstream>
using namespace std;

//Connected Directed Acyclic graph
class Node
{
    public:
        int value;
        int index;
        int parent;
        int level;
        vector<Node> children;
};

int maxLevel = -1;

void dfs(Node node[], int level, vector<bool> &visited, int currentIndex, vector<int> &nodeLevels, vector<int> &parentNodes)
{
    if(visited[currentIndex] != true)
    {
        nodeLevels[currentIndex] = level + 1;
        node[currentIndex].level = level + 1;
        if(node[currentIndex].level > maxLevel)
        {
            maxLevel = node[currentIndex].level;
        }
        visited[currentIndex] = true;
        vector<Node>::iterator itr= node[currentIndex].children.begin();
        for(;itr != node[currentIndex].children.end();)
        {
            int childIndex = itr -> index;
            if(visited[childIndex] != true)
            {
                node[childIndex].parent = node[currentIndex].index;
                parentNodes[childIndex] = node[currentIndex].index;
                dfs(node, level + 1, visited, childIndex, nodeLevels, parentNodes);
                ++itr;
            }
            else
            {
                itr = node[currentIndex].children.erase(itr);
            }
        }
    }
}

void setJumpLevelsOfNodes(vector<int> &parents, vector<vector<int>> &jumpLevels)
{
    cout << "---------setJumpLevelOfNodes----------" << endl;
    int numberOfNodes = jumpLevels.size();
    int heightOfTheTree = jumpLevels[0].size();
    cout << "Number of nodes: " << numberOfNodes << " Height of the tree: " << heightOfTheTree << endl;
    for(int i = 0; i < numberOfNodes; i++)
    {
        jumpLevels[i][0] = parents[i];
    }
    for(int j = 1; j < heightOfTheTree; j++)
    {
        for(int i = 1; i < numberOfNodes; i++)
        {
            if(jumpLevels[i][j - 1] != -1)
            {
                jumpLevels[i][j] = jumpLevels[jumpLevels[i][j - 1]][j - 1];
            }
        }
    }
    cout << "-----------**********-----------" << endl;
}

void printNodeLevels(vector<int> nodeLevels, int numberOfNodes)
{
    cout << "----------Print Node Levels-------------" << endl;
    for(int i = 0; i < numberOfNodes; i++)
    {
        cout << "Node level of " << i << " is " << nodeLevels[i] << endl;
    }
    cout << "Node levels are printed" << endl;
}

void printJumpLevels(vector<vector<int>> &jumpLevels)
{
    cout << "----------printJumpLevels----------" << endl;
    int numberOfNodes = jumpLevels.size();
    int heightOfTheTree = jumpLevels[0].size();
    for(int j = 0; j < heightOfTheTree; j++)
    {
        for(int i = 0; i < numberOfNodes; i++)
        {
            cout << "i: " << i << " j: " << j << " jumpLevels: " << jumpLevels[i][j] << endl;
        }
    }
    cout << "------*********---------" << endl;
}

void printParents(Node node[], int numberOfNodes)
{
    cout << "Print parents" << endl;
    for(int i = 0; i < numberOfNodes; i++)
    {
        cout << "parent of node " << i << " is: " << node[i].parent << endl;
    }
    cout << "-------********-------" << endl;
}

void generateBinaryValues(long long int n, vector<string> &binaryValues)
{
    cout << "------Inside generate binary values---------" << endl;
    queue<string> binaryQueue;
    binaryQueue.push("1");
    for(int i = 1; i <= n; i++)
    {
        string s1 = binaryQueue.front();
        binaryQueue.pop();
        cout << "String: " << s1 << endl;
        binaryValues[i] = s1;
        string s2 = s1;
        binaryQueue.push(s1.append("0"));
        binaryQueue.push(s2.append("1"));
    }
    cout << "---------***************-----------" << endl;
}

void printBinaryValues(int n, vector<string> binaryValues)
{
    cout << "---------Print Binary Values---------" << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << "Binary value of " << i << " is " << binaryValues[i] << endl;
    }
    cout << "----------***********------------" << endl;
}

int LCA(long long int num1, long long int num2, vector<int> nodeLevels, vector<string> binaryValues, vector <vector<int>> jumpLevels)
{
    cout << "----------Inside LCA function---------" << endl;
    cout << "Node level of " << num1 << " : " << nodeLevels[num1] << " ; Node levels of " << num2 << " : " << nodeLevels[num2] << endl;
    if(nodeLevels[num2] > nodeLevels[num1])
    {
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }
    int difference = nodeLevels[num1] - nodeLevels[num2];
    cout << "Difference: " << difference << endl;
    if (difference != 0)
    {
        int currentNodeValue = num1;
        cout << "CurrentNodeValue : " << currentNodeValue << endl;
        string binaryFormOfDifference = binaryValues[difference];
        int binaryStringLength = binaryFormOfDifference.length();
        cout << "Binary form of difference: " << binaryFormOfDifference << endl;
        cout << "Binary string length: " << binaryStringLength << endl;
        for(int i = binaryStringLength - 1, j = 0; i >= 0; i--, j++)
        {
            int positionValue = binaryFormOfDifference[j] - '0';
            cout << "i : " << i << " positionValue: " << positionValue << endl;
            if(positionValue == 1)
            {
                cout << "i is " << i << endl;
                currentNodeValue = jumpLevels[currentNodeValue][i];
                cout << "Current Node Value: " << currentNodeValue << endl;
            }
        }
        num1 = currentNodeValue;
        cout << "num1 node index after bringing num1 and num2 to same level: " << num1 << endl;
    }
    if (num1 != num2)
    {
        string binaryValueOfPresentLevel = binaryValues[num1];
        int lengthOfBinaryValueOfPresentLevel = binaryValueOfPresentLevel.length();
        int currentNodeValueNum1 = num1;
        int currentNodeValueNum2 = num2;
        for(int i = lengthOfBinaryValueOfPresentLevel - 1; i >= 0; i--)
        {
            int jumpValueNum1 = jumpLevels[currentNodeValueNum1][i];
            if(jumpValueNum1 != -1)
            {
                int jumpValueNum2 = jumpLevels[currentNodeValueNum2][i];
                if (jumpValueNum1 != jumpValueNum2)
                {
                    currentNodeValueNum1 = jumpValueNum1;
                    currentNodeValueNum2 = jumpValueNum2;
                }
            }
        }
        int lca = jumpLevels[currentNodeValueNum1][0];
        return lca;
    }
    else
    {
        cout << "num1 and num2 nodeLevels are same: " << num1 << endl;
        return num1;
    }
    cout << "-----------**************-------------" << endl;
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    Node *node = new Node[numberOfNodes];

    for(int i = 0; i < numberOfNodes; i++)
    {
        int value;
        cin >> value;
        node[i].index = i;
        node[i].value = value;
    }

    for(int i = 0; i < numberOfEdges; i++)
    {
        int fromIndex, toIndex;
        cin >> fromIndex >> toIndex;
        node[fromIndex].children.push_back(node[toIndex]);
        node[toIndex].children.push_back(node[fromIndex]);
    }

    vector<bool> visited(numberOfNodes);
    vector<int> nodeLevels(numberOfNodes);
    vector<int> parentNodes(numberOfNodes);
    node[0].parent = -1;
    parentNodes[0] = -1;
    int level = -1, currentIndex = 0;
    dfs(node, level, visited, currentIndex, nodeLevels, parentNodes);
    //printParents(node, numberOfNodes);
    int heightOfTheTree = maxLevel + 1;
    cout << "Height of the tree: " << heightOfTheTree << endl;
    vector< vector<int>> jumpLevels(numberOfNodes, vector<int>(heightOfTheTree, -1));
    //Creates an array equivalent jumpLevels[numberOfNodes][heightOfTheTree] = {- 1};
    //printJumpLevels(jumpLevels);
    setJumpLevelsOfNodes(parentNodes, jumpLevels);
    //printJumpLevels(jumpLevels);
    vector<string> binaryValues(numberOfNodes + 1);
    binaryValues[0] = "0";
    generateBinaryValues(numberOfNodes, binaryValues);
    //printBinaryValues(numberOfNodes, binaryValues);
    //printNodeLevels(nodeLevels, numberOfNodes);
    long long int num1, num2;
    cin >> num1 >> num2;
    cout << "Num1: " << num1 << " Num2: " << num2 << endl;
    cout << "Node 12 level 2: " << jumpLevels[12][1] << endl;
    int lca = LCA(num1, num2, nodeLevels, binaryValues, jumpLevels);
    cout << lca << endl;
    return 0;
}
