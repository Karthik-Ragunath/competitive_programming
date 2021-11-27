#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll minValue = 100000000000;

class Comparator
{
    public:
        bool operator()(pair< ll, ll > pair1, pair< ll, ll > pair2)
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

ll returnParent(ll index, vector< ll > &parent)
{
    if(parent[index] == index)
    {
        return index;
    }
    parent[index] = returnParent(parent[index], parent);
    return parent[index];
}

bool unionFind(ll source, ll destination, vector< ll > &parent, vector< ll > &rank)
{
    ll sourceParent = returnParent(source, parent);
    ll destinationParent = returnParent(destination, parent);
    if(sourceParent != destinationParent)
    {
        if(rank[destinationParent] > rank[sourceParent])
        {
            rank[destinationParent] += 1;
            parent[sourceParent] = destinationParent;
        }
        else
        {
            rank[sourceParent] += 1;
            parent[destinationParent] = sourceParent;
        }
        return false;
    }
    else
    {
        return true;
    }
}

void maxSpanningTreeConstruct(vector< pair< ll, ll > > &pairs, ll N, vector< ll > &parent, vector< ll > &rank, vector< vector< pair< ll, ll > > > &maxSpanningTree)
{
    ll numberOfTerms = N * N;
    ll numberOfEdges = 0;
    for(ll i = 0; i < numberOfTerms && numberOfEdges < (N - 1); i++)
    {
        ll source = pairs[i].first / N;
        ll destination = pairs[i].first % N;
        if(!unionFind(source, destination, parent, rank))
        {
            maxSpanningTree[source].push_back(make_pair(destination, pairs[i].second));
            maxSpanningTree[destination].push_back(make_pair(source, pairs[i].second));
            numberOfEdges += 1;
        }
    }
}

void computeMinCutAdjacencyMatrix(vector< vector< pair< ll, ll > > > &maxSpanningTree, ll N, vector< vector< ll > > &adjacencyMatrixMinCut, ll currentIndex, vector< bool > &visited, vector< ll > &stackVector, ll allPairsIndex)
{
    vector< pair< ll, ll > >::iterator maxSpanIter = maxSpanningTree[currentIndex].begin();
    for(; maxSpanIter != maxSpanningTree[currentIndex].end(); maxSpanIter++)
    {
        ll destinationIndex = maxSpanIter -> first;
        if(!visited[destinationIndex])
        {
            ll weight = maxSpanIter -> second;
            if(!stackVector.empty())
            {
                if(weight < stackVector.back())
                {
                    stackVector.push_back(weight);
                }
                else
                {
                    stackVector.push_back(stackVector.back());
                }
            }
            else
            {
                stackVector.push_back(weight);
            }
            visited[destinationIndex] = true;
            adjacencyMatrixMinCut[allPairsIndex][destinationIndex] = stackVector.back();
            computeMinCutAdjacencyMatrix(maxSpanningTree, N, adjacencyMatrixMinCut, destinationIndex, visited, stackVector, allPairsIndex);
            stackVector.erase(stackVector.end() - 1);
        }
    }
}

ll findSolution(vector< vector< ll > > &adjacencyMatrixOriginal, vector< vector< ll > > &adjacencyMatrixMinCut, ll N)
{
    ll solution = 0;
    for(ll i = 0; i < N; i++)
    {
        for(ll j = 0; j < N; j++)
        {
            solution += (adjacencyMatrixMinCut[i][j] - adjacencyMatrixOriginal[i][j]);
        }
    }
    return solution;
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N;
        cin >> N;
        //2D Array cannot be sorted
        vector< pair< ll, ll > > pairs(N * N);
        vector< vector< ll > > adjacencyMatrixOriginal(N, vector< ll >(N));
        vector< vector< ll > > adjacencyMatrixMinCut(N, vector< ll >(N));
        vector< ll > parent(N);
        vector< ll > rank(N);
        vector< vector< pair< ll, ll > > > maxSpanningTree(N);

        for(ll i = 0; i < N; i++)
        {
            parent[i] = i;
            rank[i] = 1;
            for(ll j = 0; j < N; j++)
            {
                ll index = N * i + j;
                pairs[index].first = index;
                cin >> pairs[index].second;
                adjacencyMatrixOriginal[i][j] = pairs[index].second;
            }
        }

        sort(pairs.begin(), pairs.end(), Comparator());
        maxSpanningTreeConstruct(pairs, N, parent, rank, maxSpanningTree);

        for(ll i = 0; i < N; i++)
        {
            vector< bool > visited(N);
            vector< ll > stackVector;
            stackVector.push_back(minValue);
            visited[i] = true;
            computeMinCutAdjacencyMatrix(maxSpanningTree, N, adjacencyMatrixMinCut, i, visited, stackVector, i);
        }

        ll solution = findSolution(adjacencyMatrixOriginal, adjacencyMatrixMinCut, N);
        cout << solution << endl;
    }
    return 0;
}
