#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class ChildrenNode
{
    public:
        vector< ll > children;
        vector< ll > weight;
};

class CompareNodes
{
    public:
        bool operator()(const pair< ll, ll > &pair1, const pair< ll, ll > &pair2)
        {
            if(pair1.second < pair2.second)
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
    set< ll > specialNodesSet;
    specialNodes.push_back(-1);
    for(ll i = 1; i <= K; i++)
    {
        ll value;
        cin >> value;
        specialNodes.push_back(value);
        specialNodesSet.insert(value);
    }
    vector< ChildrenNode > childrenNode(N + 1);
    for(ll i = 0; i < M; i++)
    {
        ll node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        // cout << "Node1: " << node1 << " Node2: " << node2 << " Weight: " << weight << endl;
        childrenNode[node1].children.push_back(node2);
        childrenNode[node2].children.push_back(node1);
        childrenNode[node1].weight.push_back(weight);
        childrenNode[node2].weight.push_back(weight);
    }
    ll solutionWeight = 100000000000;
    for(ll i = 1; i < K; i++)
    {
        ll specialNode = specialNodes[i];
        vector< ll > distance((N + 1), -1);
        distance[specialNode] = 0;
        set< pair< ll, ll >, CompareNodes > distancePairsSet;
        // distancePairsSet.insert(make_pair(specialNode, 0));
        // cout << "The Special Node is: " << specialNode << endl;
        // cout << "Children Size: " << childrenNode[specialNode].children.size() << endl;
        // cout << "Weights Size: " << childrenNode[specialNode].weight.size() << endl;
        vector< ll >::iterator itr = childrenNode[specialNode].children.begin();
        vector< ll >::iterator weightItr = childrenNode[specialNode].weight.begin();
        vector< bool > visited(N + 1);
        for(; itr != childrenNode[specialNode].children.end(); itr++, weightItr++)
        {
            ll childIndex = *itr;
            ll weightValue = (*weightItr);
            distance[childIndex] = weightValue;
            // cout << "ChildIndex: " << childIndex << " WeightValue: " << weightValue << endl;
            distancePairsSet.insert(make_pair(childIndex, weightValue));
        }
        visited[specialNode] = true;
        while(!distancePairsSet.empty())
        {
            set< pair< ll, ll >, CompareNodes >::iterator topPairIter = distancePairsSet.begin();
            ll currentNode = topPairIter -> first;
            ll currentWeight = topPairIter -> second;
            // cout << "Current Node: " << currentNode << " CurrentWeight: " << currentWeight << endl;
            vector< ll >::iterator iter = childrenNode[currentNode].children.begin();
            vector< ll >::iterator weightIter = childrenNode[currentNode].weight.begin();
            set< ll >::iterator setIter = specialNodesSet.find(currentNode);
            if(setIter != specialNodesSet.end())
            {
                if(currentWeight < solutionWeight)
                {
                    solutionWeight = currentWeight;
                }
                break;
            }

            if(currentWeight > solutionWeight)
            {
                break;
            }

            for(; iter != childrenNode[currentNode].children.end(); iter++, weightIter++)
            {
                ll childrenIndex = *iter;
                if(!visited[childrenIndex])
                {
                    ll calculatedWeight = distance[currentNode] + (*weightIter);
                    if(distance[childrenIndex] == -1)
                    {
                        //Not in the set.
                        distance[childrenIndex] = calculatedWeight;
                        distancePairsSet.insert(make_pair(childrenIndex, distance[childrenIndex]));
                    }
                    else
                    {
                        //Already in set but not yet choosen since someother weighted edge in the set has weight less than it.
                        if(calculatedWeight < distance[childrenIndex])
                        {
                            distance[childrenIndex] = calculatedWeight;
                            set< pair< ll, ll >, CompareNodes >::iterator findIter = distancePairsSet.find(make_pair(childrenIndex, distance[childrenIndex]));
                            if(findIter != distancePairsSet.end())
                            {
                                distancePairsSet.erase(findIter);
                                distancePairsSet.insert(make_pair(childrenIndex, distance[childrenIndex]));
                            }
                            else
                            {
                                distancePairsSet.insert(make_pair(childrenIndex, distance[childrenIndex]));
                            }
                        }
                    }
                }
            }

            distancePairsSet.erase(distancePairsSet.begin());
            visited[currentNode] = true;
        }
    }
    cout << solutionWeight << endl;
    return 0;
}
