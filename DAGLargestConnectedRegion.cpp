#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxRegionSize = 0;

void connectedDAG(vector< vector< ll > > &graph, vector< vector< bool > > &visited, ll row, ll column, ll maxRows, ll maxColumns)
{
    maxRegionSize++;
    visited[row][column] = true;
    if(!visited[row - 1][column] && graph[row - 1][column] == 1)
    {
        connectedDAG(graph, visited, row - 1, column, maxRows, maxColumns);
    }
    if(!visited[row + 1][column] && graph[row + 1][column] == 1)
    {
        connectedDAG(graph, visited, row + 1, column, maxRows, maxColumns);
    }
    if(!visited[row][column + 1] && graph[row][column + 1] == 1)
    {
        connectedDAG(graph, visited, row, column + 1, maxRows, maxColumns);
    }
    if(!visited[row][column - 1] && graph[row][column - 1] == 1)
    {
        connectedDAG(graph, visited, row, column - 1, maxRows, maxColumns);
    }
    if(!visited[row + 1][column + 1] && graph[row + 1][column + 1] == 1)
    {
        connectedDAG(graph, visited, row + 1, column + 1, maxRows, maxColumns);
    }
    if(!visited[row - 1][column - 1] && graph[row - 1][column - 1] == 1)
    {
        connectedDAG(graph, visited, row - 1, column - 1, maxRows, maxColumns);
    }
    if(!visited[row - 1][column + 1] && graph[row - 1][column + 1] == 1)
    {
        connectedDAG(graph, visited, row - 1, column + 1, maxRows, maxColumns);
    }
    if(!visited[row + 1][column - 1] && graph[row + 1][column - 1] == 1)
    {
        connectedDAG(graph, visited, row + 1, column - 1, maxRows, maxColumns);
    }
}

int main()
{
    ll rows, columns;
    cin >> rows >> columns;
    vector< vector< ll > > graph(rows + 2, vector< ll >(columns + 2));
    vector< vector< bool > > visited(rows + 2, vector< bool >(columns + 2));
    for(ll i = 1; i <= rows; i++)
    {
        for(ll j = 1; j <= columns; j++)
        {
            cin >> graph[i][j];
        }
    }
    ll solution = 0;
    for(ll i = 1; i <= rows; i++)
    {
        for(ll j = 1; j <= columns; j++)
        {
            if(!visited[i][j] && graph[i][j] == 1)
            {
                connectedDAG(graph, visited, i, j, rows, columns);
                if(maxRegionSize > solution)
                {
                    solution = maxRegionSize;
                }
                maxRegionSize = 0;
            }
        }
    }
    cout << solution << endl;
    return 0;
}
