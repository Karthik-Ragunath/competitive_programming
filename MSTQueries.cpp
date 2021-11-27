// https://www.codechef.com/problems/MSTQS
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector < ll > unionRank(2001);
vector < ll > parent(2001);
ll minSpanningTreeWeight = 0;
ll edgesVisited = 0;

class Edge
{
    public:
        ll source;
        ll destination;
        ll weight;
};

list < Edge > minSpanningTreeEdges;
list < Edge >::iterator itr[200001];
vector < bool > masked(200001);
vector < vector < ll > > edges2D(2001, vector < ll > (2001, -1));
vector< Edge > edges;

class CompareNodes
{
    public:
        bool operator()(const Edge &e1, const Edge &e2)
        {
            if(e1.weight < e2.weight)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

void initUnionFind(ll N)
{
    for(ll i = 1; i <= N; i++)
    {
        parent[i] = i;
        unionRank[i] = 1;
    }
    minSpanningTreeWeight = 0;
    edgesVisited = 0;
}

ll findParent(ll nodeIndex)
{
    if(parent[nodeIndex] == nodeIndex)
    {
        return nodeIndex;
    }
    ll parentValue = findParent(parent[nodeIndex]);
    parent[nodeIndex] = parentValue;
    return parentValue;
}

bool unionFind(ll node1Index, ll node2Index)
{
    ll node1Parent = findParent(node1Index);
    ll node2Parent = findParent(node2Index);
    if(node1Parent == node2Parent)
    {
        return false;
    }
    else
    {
        if(unionRank[node1Parent] > unionRank[node2Parent])
        {
            parent[node2Parent] = node1Parent;
            unionRank[node1Parent] += unionRank[node2Parent];
        }
        else
        {
            parent[node1Parent] = node2Parent;
            unionRank[node2Parent] += unionRank[node1Parent];
        }
        return true;
    }
}

void kruskalVector(vector< Edge > &edges, ll numberOfNodes)
{
    vector< Edge >::iterator iter = edges.begin();
    for(; iter != edges.end() && edgesVisited < numberOfNodes; iter++)
    {
        ll source = iter -> source;
        ll destination = iter -> destination;
        if(unionFind(source, destination))
        {
            ll weight = iter -> weight;
            minSpanningTreeWeight += weight;
            Edge e;
            e.source = source;
            e.destination = destination;
            e.weight = weight;
            minSpanningTreeEdges.push_back(e);
            edgesVisited++;
        }
    }
}

void printOut(ll N)
{
    cout << "-------Print Parents-------" << endl;
    for(ll i = 1; i <= N; i++)
    {
        cout << "Parent of " << i << " is: " << parent[i] << endl;
    }
    cout << "-------*************-------" << endl;
    cout << "Minimum Spanning Tree Weight: " << minSpanningTreeWeight << endl;
}

void kruskalList(list< Edge > &edges, ll numberOfNodes)
{
    list< Edge >::iterator iter = edges.begin();
    for(; iter != edges.end() && edgesVisited < numberOfNodes; iter++)
    {
        ll source = iter -> source;
        ll destination = iter -> destination;
        if(unionFind(source, destination))
        {
            ll weight = iter -> weight;
            minSpanningTreeWeight += weight;
            edgesVisited++;
        }
    }
}

void swap(ll &valueA, ll &valueB)
{
    ll temp = valueB;
    valueB = valueA;
    valueA = temp;
}

int main()
{
    ll N, M, Q;
    cin >> N >> M >> Q;
    // cout << "edges2D[2000][2000]: " << edges2D[2000][2000] << endl;
    for(ll i = 1; i <= M; i++)
    {
        Edge e;
        ll source, destination, weight;
        cin >> source >> destination >> weight;
        if(source > destination)
        {
            swap(source, destination);
        }
        edges2D[source][destination] = i; //To Act as unique key
        e.source = source;
        e.destination = destination;
        e.weight = weight;
        edges.push_back(e);
    }
    // cout << "Edges Size: " << edges.size() << endl;
    sort(edges.begin(), edges.end(), CompareNodes());
    initUnionFind(N);
    kruskalVector(edges, N);
    // printOut(N);
    bool needsRefreshing = false;
    for(ll i = 0; i < Q; i++)
    {
        ll queryType;
        cin >> queryType;
        // cout << "QueryType: " << queryType << endl;
        if(queryType == 1)
        {
            ll u, v;
            cin >> u >> v;
            if(u > v)
            {
                swap(u, v);
            }
            ll uniqueIndexOfEdgeUV = edges2D[u][v]; //Get the unique key
            if(!masked[uniqueIndexOfEdgeUV])
            {
                Edge e;
                e.source = u;
                e.destination = v;
                e.weight = 0;
                minSpanningTreeEdges.push_front(e);
                masked[uniqueIndexOfEdgeUV] = true; //Masked to not worry about previous value of itr[uniqueKey] and also to avoid unnecessary computations like zeroing on same element which is already zeroed.
                itr[uniqueIndexOfEdgeUV] = minSpanningTreeEdges.begin(); //Iterator with unique key as index to erase element in list in O(1) time.
                needsRefreshing = true;
            }
        }
        else if(queryType == 2)
        {
            ll u, v;
            cin >> u >> v;
            if(u > v)
            {
                swap(u, v);
            }
            ll uniqueIndexOfEdgeUV = edges2D[u][v];
            if(masked[uniqueIndexOfEdgeUV])
            {
                minSpanningTreeEdges.erase(itr[uniqueIndexOfEdgeUV]);
                masked[uniqueIndexOfEdgeUV] = false;
                needsRefreshing = true;
            }
        }
        else
        {
            if(needsRefreshing)
            {
                initUnionFind(N);
                kruskalList(minSpanningTreeEdges, N);
                needsRefreshing = false;
            }
            cout << minSpanningTreeWeight << endl;
        }
    }
    return 0;
}
