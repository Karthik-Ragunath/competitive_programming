#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


class Node
{
    public:
        int value;
        vector<Node> children;
        Node *specialChild;
        Node *superChild;
};

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    Node node[numberOfNodes];
    Node *superNodes = new Node[numberOfNodes];
    for(int i = 0; i < numberOfNodes; i++)
    {
        node[i].value = i;
        node[i].superChild = new Node();
        node[i].superChild -> value = 9 * (i + 1);
        if(i != numberOfNodes - 1)
        {
            node[i].specialChild = &node[i + 1];
        }
        for(int j = 0; j <= i; j++)
        {
            node[i].children.push_back(node[j]);
        }
    }

    for(int i = 0; i < numberOfNodes; i++)
    {
        superNodes[i].value = 10 * (i + 1);
        if(i != numberOfNodes - 1)
        {
            superNodes[i].specialChild = &superNodes[i + 1];
        }
    }

    for(int i = 0; i < numberOfNodes; i++)
    {
        // cout << node[i].value;
        cout << node[i].superChild -> value << endl;
        if(i != numberOfNodes - 1)
        {
            cout << node[i].specialChild -> value << endl;
        }
        for(int j = 0; j < node[i].children.size(); j++)
        {
            cout << node[i].children[j].value << endl;
        }
    }

    cout << "-------Super Nodes--------" << endl;

    for(int i = 0; i < numberOfNodes; i++)
    {
        if(i != (numberOfNodes - 1))
        {
            cout << superNodes[i].specialChild -> value << endl;
        }
    }
    return 0;
}
