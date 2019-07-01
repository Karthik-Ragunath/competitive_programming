#include <bits/stdc++.h>
using namespace std;
#define ll long long input

class ChildrenNode
{
    public:
        vector< ll > children;
        vector< ll > weight;
}

class CompareNodes
{
    public:
        bool operator()(const pair< ll, ll > &pair1, const pair< ll, ll > &pair2)
        {
            if(pair1.second > pair2.second)
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
    ll N, M, K;
    cin >> N >> M >> K;
    vector< ll > specialNodes;
    specialNodes.push_back(-1);
    for(ll i = 1; i <= K; i++)
    {
        ll value;
        cin >> value;
        specialNodes.push_back(value);
    }
    vector< ChildrenNode > childrenNode(N + 1);
    for(ll i = 0; i < M; i++)
    {
        ll node1, node2, weight;
        childrenNode[node1].children.push_back(node2);
        childrenNode[node2].children.push_back(node1);
        childrenNode[node1].weight.push_back(weight);
        childrenNode[node2].weight.push_back(weight);
    }
    for(ll i = 1; i <= K; i++)
    {
        ll specialNode = specialNodes[i];
        vector< ll > distance((N + 1), -1);
        distance[specialNode] = 0;
        priority_queue< pair< ll, ll >, vector< pair < ll, ll > >, CompareNodes > distancePairsPriorityQueue;
        distancePairsPriorityQueue.push(make_pair(specialNode, 0));
        while(!distancePairsPriorityQueue.empty())
        {
            pair< ll, ll > topPair = distancePairsPriorityQueue.top();
            vector< ll >::iterator iter = childrenNode[topPair.first].children.begin();
            vector< ll >::iterator weightIter = childrenNode[topPair.first].weight.begin();
            for(; iter != childrenNode[topPair.first].children.end(); iter++, weightIter++)
            {
                ll childrenIndex = *iter;
                ll calculatedWeight = distance[topPair.first] + (*weightIter);
                if(distance[childrenIndex] == -1)
                {
                    distance[childrenIndex] = calculatedWeight;
                }
                else
                {
                    if(calculatedWeight < distance[childrenIndex])
                    {
                        distance[childrenIndex] = calculatedWeight;
                    }
                }
            }
        }
    }
    return 0;
}
