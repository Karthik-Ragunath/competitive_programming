#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

class Node
{
    public:
        int index;
        int priorityValue;
        int parent;
        vector<int> children;
        vector<int> edgeWeight;
};

class AlternateNode
{
    public:
        int priorityValue;
        int index;
};

class CompareNodes
{
    public:
        bool operator()(Node &node1, Node &node2)
        {
            if(node1.priorityValue > node2.priorityValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class CompareNodesAlternate
{
    public:
        bool operator() (const AlternateNode &node1, const AlternateNode &node2)
        {
            if(node1.priorityValue > node2.priorityValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class CompareNodesSet
{
    public:
        bool operator()(const Node &node1, const Node &node2)
        {
            if(node1.priorityValue > node2.priorityValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class CompareNodesVector
{
    public:
        bool operator()(const AlternateNode &node1, const AlternateNode &node2)
        {
            if(node1.priorityValue > node2.priorityValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class CompareNodeVector
{
    public:
        bool operator() (const Node &node1, const Node &node2)
        {
            if(node1.priorityValue > node2.priorityValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<Node> nodes(vertices);
    map<int, int> priorityMap;
    for(int i = 0; i < vertices; i++)
    {
        nodes[i].index = i;
        if(i == 0)
        {
            nodes[i].priorityValue = 0;
            priorityMap[i] = 0;
        }
        else
        {
            nodes[i].priorityValue = 1000;
            priorityMap[i] = 1000;
        }
    }

    for(int i = 0; i < edges; i++)
    {
        int first, second, value;
        cin >> first >> second >> value;
        nodes[first].children.push_back(second);
        nodes[second].children.push_back(first);
        nodes[first].edgeWeight.push_back(value);
        nodes[second].edgeWeight.push_back(value);
    }

    map<int, int>::iterator it = priorityMap.begin();
    for(;it != priorityMap.end(); it++)
    {
        cout << it -> first << " " << it -> second << endl;
    }

    priority_queue<Node, vector<Node>, CompareNodes> pq;
    for(int i = 0; i < vertices; i++)
    {
        pq.push(nodes[i]);
    }

    while(!pq.empty())
    {
        Node temp = pq.top();
        pq.pop();
        cout << temp.index << endl;
    }

    set<Node, CompareNodesSet> nodeSet;
    for(int i = 0; i < vertices; i++)
    {
        nodeSet.insert(nodes[i]);
    }

    set<Node, CompareNodesSet>::iterator itr = nodeSet.begin();
    for(;itr != nodeSet.end(); itr++)
    {
        cout << itr -> priorityValue << " Set" << endl;
    }

    cout << "---------Vector Section---------" << endl;
    vector<AlternateNode> nodeVector;
    AlternateNode temp1, temp2, temp3, temp4;
    temp1.index = 1;
    temp1.priorityValue = 0;
    temp2.index = 2;
    temp2.priorityValue = 5;
    temp3.index = 3;
    temp3.priorityValue = 2;
    temp4.index = 4;
    temp4.priorityValue = 1;
    nodeVector.push_back(temp1);
    nodeVector.push_back(temp2);
    nodeVector.push_back(temp3);
    nodeVector.push_back(temp4);

    sort(nodeVector.begin(), nodeVector.end(), CompareNodesVector());

    for(vector<AlternateNode>::iterator iter = nodeVector.begin(); iter != nodeVector.end(); iter++)
    {
        cout << iter -> index << endl;
    }

    cout << "------Back to Primms--------" << endl;

    /*
    vector<bool> visited(vertices, false);
    int rootIndex = -1;
    for(int i = 0; i < vertices; i++)
    {
        if(i == 0)
        {
            set<Node, CompareNodesSet>::iterator itr = nodeSet.begin();
            int nodeIndex = itr -> index;
            visited[nodeIndex] = true;
            rootIndex = nodeIndex;
            vector<int>::iterator childIter = itr -> children.begin();
            vector<int>::iterator weightIter = itr -> edgeWeight.begin();
            for(;childIter != itr -> children.end(); childIter++)
            {
                int tempIndex = *childIter;

            }
        }
        else
        {

        }
    }
    */

    /*
    vector<Node> nodeVectors;
    for(int i = 0; i < vertices; i++)
    {
        nodeVectors.push_back(nodes[i]);
    }
    sort(nodeVectors.begin(), nodeVectors.end(), CompareNodeVector());
    set<AlternateNode, CompareNodesSet> alterSet;
    vector<Node>::iterator nodesIter = nodeVectors.begin();
    for(;nodesIter != nodeVectors.end(); nodesIter++)
    {
        AlternateNode temp;
        temp.index = nodesIter -> index;
        temp.priorityValue = nodesIter -> priorityValue;
        alterSet.insert(temp);
    }
    */

    vector<bool> pqueueVisited(vertices, false);
    priority_queue<AlternateNode, vector<AlternateNode>, CompareNodesAlternate> pqueue;
    for(int i = 0; i < vertices; i++)
    {
        AlternateNode temp;
        temp.index = nodes[i].index;
        temp.priorityValue = nodes[i].priorityValue;
        pqueue.push(temp);
    }

    vector<Node> pqueueVector;
    for(int i = 0; i < vertices; i++)
    {
        pqueueVector.push_back(nodes[i]);
    }

    vector<AlternateNode> solutionVector;
    for(int i = 0; i < vertices; i++)
    {
        int tempIndex;
        AlternateNode top;
        while(true)
        {
            top = pqueue.top();
            tempIndex = top.index;
            if(!pqueueVisited[tempIndex])
            {
                solutionVector.push_back(top);
                pqueueVisited[tempIndex] = true;
                break;
            }
            else
            {
                pqueue.pop();
            }
        }
        vector<int>::iterator edgeWeightIter = pqueueVector[tempIndex].edgeWeight.begin();
        for(vector<int>::iterator childIter = pqueueVector[tempIndex].children.begin(); childIter != pqueueVector[tempIndex].children.end(); childIter++)
        {
            int temporaryIndex = *childIter;
            int temporaryWeight = *edgeWeightIter;
            if(!pqueueVisited[temporaryIndex])
            {
                AlternateNode temporary;
                temporary.index = temporaryIndex;
                temporary.priorityValue = temporaryWeight;
                pqueue.push(temporary);
            }
            edgeWeightIter++;
        }
        pqueue.pop();
    }

    int solution = 0;
    for(int i = 0; i < vertices; i++)
    {
    	cout << solutionVector[i].index << " Value: " << solutionVector[i].priorityValue << endl;
    	solution = solution + solutionVector[i].priorityValue;
    }
    cout << solution << endl;
    return 0;
}
