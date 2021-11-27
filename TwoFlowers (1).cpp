#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector< ll > > inputArray(2000, vector< ll >(2000));
vector< vector< bool > > visited(2000, vector< bool >(2000));
vector< vector< ll > > islandIndex(2000, vector< ll >(2000));
vector< set< ll > > childrenIslands(4000000);
vector< ll > islandSize(4000000);
vector< ll > islandValue(4000000);
ll islandArea = 0;
ll islandNumber = 0;
ll rowSize;
ll columnSize;
bool breakTheLoop = false;
ll solution = 0;

void dfs(ll row, ll column, ll value)
{
    if(inputArray[row][column] == value && !visited[row][column])
    {
        visited[row][column] = true;
        islandIndex[row][column] = islandNumber;
        islandSize[islandNumber]++;
        if((column + 1) < columnSize)
        {
            dfs(row, (column + 1), value);
        }
        if((row + 1) < rowSize)
        {
            dfs((row + 1), column, value);
        }
        if(column != 0)
        {
            dfs(row, (column - 1), value);
        }
        if(row != 0)
        {
            dfs((row - 1), column, value);
        }
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

void islandDFS(ll value1, ll value2, ll currentValue, ll index, vector< bool > &visitedIsland, ll currentIslandStartingNumber)
{
    visitedIsland[index] = true;
    islandArea += islandSize[index];
    cout << "Island Area: " << islandArea << " Index: " << index << endl;
    set< ll >::iterator childIter = childrenIslands[index].begin();
    for(; childIter != childrenIslands[index].end(); childIter++)
    {
        ll childIslandIndex = *childIter;
        ll childIslandValue = islandValue[childIslandIndex];
        cout << "Sub childIsland index: " << childIslandIndex << " Sub childIsland value: " << childIslandValue << endl;
        if(childIslandIndex < currentIslandStartingNumber)
        {
            if((currentValue == 1 && childIslandValue == value1) || (currentValue == 2 && childIslandValue == value2))
            {
                islandArea = 0;
                breakTheLoop = true;
                return;
            }
            else
            {
                continue;
            }
        }
        else if(visitedIsland[childIslandIndex])
        {
            continue;
        }
        else
        {
            if(currentValue == 1)
            {
                if(islandValue[childIslandIndex] == value1)
                {
                    islandDFS(value1, value2, 2, childIslandIndex, visitedIsland, currentIslandStartingNumber);
                }
                if(breakTheLoop)
                {
                    return;
                }
            }
            else
            {
                if(islandValue[childIslandIndex] == value2)
                {
                    islandDFS(value1, value2, 1, childIslandIndex, visitedIsland, currentIslandStartingNumber);
                }
                if(breakTheLoop)
                {
                    return;
                }
            }
        }
    }
    return;
}

ll returnLargestArea()
{
    for(ll i = 0; i < islandNumber; i++)
    {
        set< ll >::iterator setIter = childrenIslands[i].begin();
        set< ll > previousIslandValues;
        unordered_map< ll, ll > islandValueSizePair;
        cout << "Island Number: " << i << endl;

        for(; setIter != childrenIslands[i].end(); setIter++)
        {
            vector< bool > visitedIsland(islandNumber);
            visitedIsland[i] = true;
            ll childIslandIndex = *setIter;
            ll childIslandValue = islandValue[childIslandIndex];
            cout << "ChildIndex: " << childIslandIndex << " childIslandValue: " << childIslandValue << endl;
            if(childIslandIndex < i)
            {
                previousIslandValues.insert(childIslandValue);
            }
            else
            {
                if(!visitedIsland[childIslandIndex])
                {
                    set< ll >::iterator previousIslandValuesIter = previousIslandValues.find(childIslandValue);
                    if(previousIslandValuesIter == previousIslandValues.end())
                    {
                        ll currentValue = 1;
                        breakTheLoop = false;
                        islandArea = 0;
                        islandDFS(islandValue[i], childIslandValue, currentValue, childIslandIndex, visitedIsland, i);
                        unordered_map< ll, ll >::iterator unorderedIter = islandValueSizePair.find(childIslandValue);
                        if(unorderedIter != islandValueSizePair.end())
                        {
                            ll alreadyFoundSize = unorderedIter -> second;
                            ll newValue = islandArea + alreadyFoundSize;
                            islandValueSizePair.erase(unorderedIter);
                            islandValueSizePair.insert(make_pair(childIslandValue, newValue));
                        }
                        else
                        {
                            islandValueSizePair.insert(make_pair(childIslandValue, islandArea));
                        }
                    }
                    else
                    {
                        visitedIsland[childIslandIndex] = true;
                    }
                }
            }
        }
        unordered_map< ll, ll >::iterator unorderedIter = islandValueSizePair.begin();
        for(; unorderedIter != islandValueSizePair.end(); unorderedIter++)
        {
            ll value = unorderedIter -> second;
            ll grossValue = value + islandSize[i];
            if(solution < grossValue)
            {
                solution = grossValue;
            }
        }
    }
    return solution;
}

void printIslandDetails()
{
    cout << "*---Details Begin---*" << endl;
    cout << "Number of islands: " << islandNumber << endl;
    for(ll i = 0; i < islandNumber; i++)
    {
        cout << "Island size of island " << i << " is " << islandSize[i] << endl;
    }
    cout << "*---------*" << endl;
    cout << "Island Index" << endl;
    for(ll i = 0; i < rowSize; i++)
    {
        for(ll j = 0; j < columnSize; j++)
        {
            cout << islandIndex[i][j] << " ";
        }
        cout << endl;
    }
    cout << "*---------*" << endl;
    for(ll i = 0; i < islandNumber; i++)
    {
        set< ll >::iterator setIter = childrenIslands[i].begin();
        cout << "Island No. " << i << endl;
        for(; setIter != childrenIslands[i].end(); setIter++)
        {
            cout << "Child: " << *setIter << endl;
        }
    }
    cout << "*---Details End---*" << endl;
}

void printIslandIndex()
{
    cout << "*---------*" << endl;
    cout << "Island Index" << endl;
    for(ll i = 0; i < rowSize; i++)
    {
        for(ll j = 0; j < columnSize; j++)
        {
            cout << islandIndex[i][j] << " ";
        }
        cout << endl;
    }
    cout << "*---------*" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
                dfs(i, j, inputArray[i][j]);
                islandValue[islandNumber] = inputArray[i][j];
                islandNumber++;
            }
        }
    }
    islandGraphFormation();
    // printIslandDetails();
    printIslandIndex();
    ll solution = returnLargestArea();
    cout << solution << endl;
    return 0;
}
