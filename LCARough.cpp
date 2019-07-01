#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector < ll > > nodes(2 * 100000 + 1);
vector< string > binaryValues(2 * 100000 + 2);
ll maxJumpLevel = 0;
ll maxLevel = 0;

/*
void orderLevelsByRootDFS(vector< bool > &visited, vector< ll > &level, vector< ll > &parent, ll levelNow, ll currentIndex, ll parentIndex)
{
    if(!visited[currentIndex] || ((levelNow + 1) < level[currentIndex]))
    {
        if(maxLevel < (levelNow + 1))
        {
            maxLevel = levelNow + 1;
        }
        visited[currentIndex] = true;
        parent[currentIndex] = parentIndex;
        level[currentIndex] = levelNow + 1;
        vector< ll >::iterator iter = nodes[currentIndex].begin();
        for(; iter != nodes[currentIndex].end(); iter++)
        {
            orderLevelsByRootDFS(visited, level, parent, levelNow + 1, *iter, currentIndex);
        }
    }
}
*/

void orderLevelsByRootDFS(vector< bool > &visited, vector< ll > &level, vector< ll > &parent, ll levelNow, ll currentIndex, ll parentIndex)
{
    if(maxLevel < (levelNow + 1))
    {
        maxLevel = levelNow + 1;
    }
    visited[currentIndex] = true;
    parent[currentIndex] = parentIndex;
    level[currentIndex] = levelNow + 1;
    vector< ll >::iterator iter = nodes[currentIndex].begin();
    for(; iter != nodes[currentIndex].end(); iter++)
    {
        if(!visited[*iter])
        {
            orderLevelsByRootDFS(visited, level, parent, levelNow + 1, *iter, currentIndex);
        }
    }
}

void setJumpLevels(vector< vector< ll > > &jumpLevels, vector< ll > &parent, ll N)
{
    for(ll j = 0; j <= maxJumpLevel; j++)
    {
        for(ll i = 0; i <= N; i++)
        {
            cout << "i: " << i << " j: " << j << " maxJumpLevel: " << maxJumpLevel << endl;
            if(j == 0)
            {
                cout << " Parent of " << i << " is " << parent[i] << endl;
                jumpLevels[i][j] = parent[i];
            }
            else
            {
                if(i == 1)
                {
                    cout << "Jumper: " << jumpLevels[i][j - 1] << " j - 1: " << (j - 1) << endl;
                }
                if(jumpLevels[i][j - 1] != -1)
                {
                    jumpLevels[i][j] = jumpLevels[jumpLevels[i][j - 1]][j - 1];
                }
                else
                {
                    jumpLevels[i][j] = -1;
                }
            }
            if(i == 1)
            {
                cout << "Jumpy: " << jumpLevels[i][j] << endl;
            }
        }
    }
}

void generateBinaryString()
{
    queue< string > stringQueues;
    binaryValues[0] = "0";
    binaryValues[1] = "1";
    stringQueues.push("1");
    ll i = 1;
    for(; i <= (2 * 100000);)
    {
        string stringValue = stringQueues.front();
        string stringCopy = stringValue;
        stringQueues.pop();
        string s1 = stringValue.append("0");
        string s2 = stringCopy.append("1");
        binaryValues[++i] = s1;
        binaryValues[++i] = s2;
        stringQueues.push(s1);
        stringQueues.push(s2);
    }
}

ll returnIndexAtLevel(ll fromLevel, ll toLevel, ll index, vector< vector< ll > > &jumpLevels)
{
    cout << "---------" << endl;
    cout << jumpLevels[1][0] << " " << jumpLevels[1][1] << endl;
    cout << "---------" << endl;
    ll difference = fromLevel - toLevel;
    string binaryValueOfDifference = binaryValues[difference];
    cout << "Diff String: " << binaryValueOfDifference << endl;
    ll length = binaryValueOfDifference.size();
    cout << "0: " << binaryValueOfDifference[0] << " 1: " << binaryValueOfDifference[1] << endl;
    for(ll i = 0; i <= length - 1; i++)
    {
        if(binaryValueOfDifference[i] == '1')
        {
            index = jumpLevels[index][length - 1 - i];
            cout << "The index is: " << index << " and i is: " << i << endl;
        }
    }
    return index;
}

ll returnLCAValue(ll index1, ll index2, vector< ll > &level, vector< vector< ll > > &jumpLevels, vector< ll > &parent)
{
    ll level1 = level[index1];
    ll level2 = level[index2];
    cout << "Index1: " << index1 << " Index2: " << index2 << " Level1: " << level1 << " Level2: " << level2 << endl;
    ll desiredLevel;
    if(level1 != level2)
    {
        ll desiredLevelIndex;
        if(level1 > level2)
        {
            desiredLevelIndex = returnIndexAtLevel(level1, level2, index1, jumpLevels);
            index1 = desiredLevelIndex;
            desiredLevel = level2;
        }
        else
        {
            cout << "Index2 parent:" << jumpLevels[index2][0] << endl;
            desiredLevelIndex = returnIndexAtLevel(level2, level1, index2, jumpLevels);
            index2 = desiredLevelIndex;
            desiredLevel = level1;
        }
    }
    else
    {
        desiredLevel = level1;
    }
    if(index1 != index2)
    {
        string binaryValueOfIndex = binaryValues[desiredLevel];
        cout << "BinaryValueOfIndex: " << binaryValueOfIndex << endl;
        ll levelStringLength = binaryValueOfIndex.size();
        cout << "String Length: " << levelStringLength << endl;
        cout << "Index1: " << index1 << " Index2: " << index2 << endl;
        for(ll i = levelStringLength - 1; i >= 0; i--)
        {
            ll index1NewValue = jumpLevels[index1][i];
            ll index2NewValue = jumpLevels[index2][i];
            cout << "JumpLevel[4][0]: " << jumpLevels[4][0] << endl;
            cout << "New Values: Index1: " << index1NewValue << " Index2: " << index2NewValue << endl;
            if(index1NewValue != index2NewValue)
            {
                index1 = index1NewValue;
                index2 = index2NewValue;
            }
        }
        cout << "LCA: " << parent[index1] << endl;
        return parent[index1];
    }
    else
    {
        return index1;
    }
}

int main()
{
    ll N;
    cin >> N;
    for(ll i = 1; i < N; i++)
    {
        ll source, destination;
        cin >> source >> destination;
        nodes[source].push_back(destination);
        nodes[destination].push_back(source);
    }
    generateBinaryString();
    ll queries;
    cin >> queries;
    for(ll i = 0; i < queries; i++)
    {
        ll root = 0;
        cin >> root;
        cout << "-----Root: " << root << endl;
        vector< bool > visited(N + 1);
        vector< ll > level(N + 1);
        vector< ll > parent(N + 1, -1);
        cout << "Came Here Baby" << endl;
        maxLevel = 0;
        ll levelNow = 0;
        orderLevelsByRootDFS(visited, level, parent, levelNow, root, -1);
        maxJumpLevel = 0;
        for(ll j = 0; (1 << j) < maxLevel; j++)
        {
            maxJumpLevel++;
        }
        vector< vector< ll > > jumpLevels(N + 1, vector< ll >(maxJumpLevel + 1, -1)); //maxJumLevel + 1 because of string size which may lead us to -1 node. 4 -> 100 while accessing [4][2] null pointer exception occurs since array size is not defined till 2 though its value is always going to be 0.
        setJumpLevels(jumpLevels, parent, N);
        ll index1, index2;
        cin >> index1 >> index2;
        ll lcaValue = returnLCAValue(index1, index2, level, jumpLevels, parent);
        cout << lcaValue << endl;
    }
    return 0;
}
