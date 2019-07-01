#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// class CompareNodes
// {
//     public:
//         bool operator()(const pair< ll, ll > &pair1, const pair< ll, ll > &pair2)
//         {
//             if(pair1.second < pair2.second)
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
// };

class CompareNodes
{
    public:
        bool operator()(const pair< ll, ll > &pair1, const pair< ll, ll > &pair2)
        {
            if(pair1.second <= pair2.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

void printSets(set< pair< ll, ll >, CompareNodes > &graphEdges)
{
    cout << "------Begin------" << endl;
    set< pair< ll, ll >, CompareNodes >::iterator iter = graphEdges.begin();
    for(; iter != graphEdges.end(); iter++)
    {
        cout << "Index: " << iter -> first << " Weight: " << iter -> second << endl;
    }
}

int main()
{
    ll nodes, edges;
    cin >> nodes >> edges;
    vector< ll > colorIds(nodes + 1);
    vector< vector< ll > > graphEdges(nodes + 1);

    for(ll i = 0; i < edges; i++)
    {
        ll fromNode, toNode;
        cin >> fromNode >> toNode;
        graphEdges[fromNode].push_back(toNode);
        graphEdges[toNode].push_back(fromNode);
    }
    for(ll i = 1; i <= nodes; i++)
    {
        cin >> colorIds[i];
    }

    // Dijkstra algorithm
    ll startNodeIndex;
    cin >> startNodeIndex;
    vector< ll > weights(nodes + 1, 1000000000);
    vector< ll > visited(nodes + 1);
    set< pair< ll, ll >, CompareNodes > graphEdgesSets;
    graphEdgesSets.insert(make_pair(startNodeIndex, 0));
    weights[startNodeIndex] = 0;

    ll requiredColor = colorIds[startNodeIndex];
    ll solution = -1;

    while(!graphEdgesSets.empty())
    {
        set< pair< ll, ll >, CompareNodes >::iterator iter = graphEdgesSets.begin();
        ll index = iter -> first;
        ll currentWeightValue = iter -> second;
        // cout << "Index: " << index << " " << "CurrentWeight: " << currentWeightValue << endl;
        visited[index] = true;
        if(index != startNodeIndex)
        {
            if(colorIds[index] == requiredColor)
            {
                solution = currentWeightValue;
                break;
            }
        }
        vector< ll >::iterator vectIter = graphEdges[index].begin();
        for(; vectIter != graphEdges[index].end(); vectIter++)
        {
            ll childIndex = *vectIter;
            if(!visited[childIndex])
            {
                if(currentWeightValue + 1 < weights[childIndex])
                {
                    set< pair< ll, ll >, CompareNodes >::iterator graphEdgesFindIter = graphEdgesSets.find(make_pair(childIndex, weights[childIndex]));
                    if(graphEdgesFindIter != graphEdgesSets.end())
                    {
                        graphEdgesSets.erase(graphEdgesFindIter);
                    }
                    // cout << "ChildIndex: " << childIndex << " " << "Weight Value: " << (currentWeightValue + 1) << endl;
                    graphEdgesSets.insert(make_pair(childIndex, currentWeightValue + 1));
                    weights[childIndex] = currentWeightValue + 1;
                }
            }
            // cout << "ChildIndex: " << childIndex << " " << "Weight Value: " << weights[childIndex] << endl;
        }
        graphEdgesSets.erase(graphEdgesSets.begin());
        // printSets(graphEdgesSets);
    }
    cout << solution << endl;
}
