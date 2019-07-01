#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

class Node
{
    public:
        int value;
        int parent;
};

class DFSNode
{
    public:
        int value;
        int index;
        vector<int> children;
};

int dfsCyclesCount = 0;

void dfs(vector<DFSNode> &dfsNodes, int parentIndex, int currentNodeIndex, vector<bool> &visited)
{
    visited[currentNodeIndex] = true;
    if(dfsNodes[currentNodeIndex].children.empty() != true)
    {
        vector<int>::iterator it = dfsNodes[currentNodeIndex].children.begin();
        for(;it != dfsNodes[currentNodeIndex].children.end();)
        {
            if(*it != parentIndex)
            {
                if(visited[*it] == true)
                {
                    vector<int>::iterator position = find(dfsNodes[*it].children.begin(), dfsNodes[*it].children.end(), currentNodeIndex);
                    if(position != dfsNodes[*it].children.end())
                    {
                        dfsNodes[*it].children.erase(position);
                    }
                    it = dfsNodes[currentNodeIndex].children.erase(it);
                    dfsCyclesCount++;
                }
                else
                {
                    dfs(dfsNodes, currentNodeIndex, *it, visited);
                    ++it;
                }
            }
            else
            {
                it = dfsNodes[currentNodeIndex].children.erase(it);
            }
        }
    }
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int j = 0; j < testcases; j++)
    {
        int inputSize;
        cin >> inputSize;
        vector<Node> inputValues(inputSize);
        int numberOfQueries;
        cin >> numberOfQueries;
        int cyclesCount = 0;
        // vector<int> input2(input);
        //Using Disjoint groups

        for(int i = 0; i < inputSize; i++)
        {
            inputValues[i].value = i + 1;
            inputValues[i].parent = i;
        }
        for(int i = 0; i < numberOfQueries; i++)
        {
            int first, second;
            cin >> first >> second;
            int parentValue1 = inputValues[first].parent;
            while(inputValues[parentValue1].parent != parentValue1)
            {
                parentValue1 = inputValues[parentValue1].parent;
            }
            int parentValue2 = inputValues[second].parent;
            while(inputValues[parentValue2].parent != parentValue2)
            {
                parentValue2 = inputValues[parentValue2].parent;
            }
            if(parentValue1 == parentValue2)
            {
                cyclesCount++;
            }
            else
            {
                inputValues[parentValue2].parent = parentValue1;
            }
        }
        cout << cyclesCount << endl;

        //Uisng DFS
        vector<DFSNode> dfsNodes(inputSize);
        for(int i = 0; i < inputSize; i++)
        {
            dfsNodes[i].value = i;
            dfsNodes[i].index = i;
        }
        for(int i = 0; i < numberOfQueries; i++)
        {
            int first, second;
            cin >> first >> second;
            dfsNodes[first].children.push_back(second);
            dfsNodes[second].children.push_back(first);
        }
        vector<bool> visited(inputSize, false);
        for(int i = 0; i < inputSize; i++)
        {
            if(visited[i] == false)
            {
                dfs(dfsNodes, -1, i, visited);
            }
        }
        cout << dfsCyclesCount << endl;
    }
}
