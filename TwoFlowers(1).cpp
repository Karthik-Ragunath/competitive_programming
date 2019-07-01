#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector< ll > > inputArray(2000, vector< ll >(2000));
vector< vector< bool > > visited(2000, vector< bool >(2000));
vector< vector< bool > > islandIndex(2000, vector< ll >(2000));
vector< set< ll > > childrenIslands(2000);
ll islandNumber = 0;
ll rowSize;
ll columnSize;

void dfs(ll row, ll column)
{
    visited[row][column] = true;
    islandIndex[row][column] = islandNumber;
    if(column + 1< columnSize)
    {
        dfs(row, column + 1);
    }
    if(row + 1 < rowSize)
    {
        dfs(row + 1, column);
    }
    if(column != 0)
    {
        dfs(row, column - 1);
    }
    if(row != 0)
    {
        dfs(row - 1, column);
    }
    return;
}

void islandGraphFormation()
{
    for(ll i = 0; i < rowSize; i++)
    {
        for(ll j = 0; j < columnSize; j++)
        {
            if(j + 1 < columnSize)
            {
                if(inputArray[i][j] != inputArray[i][j + 1])
                {
                    childrenIslands[islandIndex[i][j]].insert(islandIndex[i][j + 1]);
                }
            }
            if(j != 0)
            {
                if(inputArray[i][j] != inputArray[i][j - 1])
                {
                    childrenIslands[islandIndex[i][j]].insert(islandIndex[i][j - 1]);
                }
            }
            if(i + 1 < rowSize)
            {
                if(inputArray[i][j] != inputArray[i + 1][j])
                {
                    childrenIslands[islandIndex[i][j]].insert(islandIndex[i + 1][j]);
                }
            }
            if(i != 0)
            {
                if(inputArray[i][j] != inputArray[i - 1][j])
                {
                    childrenIslands[islandIndex[i][j]].insert(islandIndex[i - 1][j]);
                }
            }
        }
    }
    return;
}

ll returnLargestArea()
{

}

int main()
{
    cin >> rowSize >> columnSize;
    for(ll i = 0; i < rowSize; i++)
    {
        for(ll j = 0; j < columnSize; j++)
        {
            cin >> inputArray[i][j];
        }
    }

    for(ll i = 0; i < rowSize; i++)
    {
        for(ll j = 0; j < columnSize; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j);
                islandNumber++;
            }
        }
    }

    islandGraphFormation();
    ll solution = returnLargestArea();
    return 0;
}
