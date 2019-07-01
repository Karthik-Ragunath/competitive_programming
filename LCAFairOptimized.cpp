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
            if(j == 0)
            {
                jumpLevels[i][j] = parent[i];
            }
            else
            {
                if(jumpLevels[i][j - 1] != -1)
                {
                    jumpLevels[i][j] = jumpLevels[jumpLevels[i][j - 1]][j - 1];
                }
                else
                {
                    jumpLevels[i][j] = -1;
                }
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
    ll difference = fromLevel - toLevel;
    string binaryValueOfDifference = binaryValues[difference];
    ll length = binaryValueOfDifference.size();
    for(ll i = 0; i <= length - 1; i++)
    {
        if(binaryValueOfDifference[i] == '1')
        {
            index = jumpLevels[index][length - 1 - i];
        }
    }
    return index;
}

ll returnLCAValue(ll index1, ll index2, vector< ll > &level, vector< vector< ll > > &jumpLevels, vector< ll > &parent)
{
    ll level1 = level[index1];
    ll level2 = level[index2];
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
        ll levelStringLength = binaryValueOfIndex.size();
        for(ll i = levelStringLength - 1; i >= 0; i--)
        {
            ll index1NewValue = jumpLevels[index1][i];
            ll index2NewValue = jumpLevels[index2][i];
            if(index1NewValue != index2NewValue)
            {
                index1 = index1NewValue;
                index2 = index2NewValue;
            }
        }
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
    vector< ll > u(queries);
    vector< ll > v(queries);
    vector< ll > solution(queries);
    vector< pair< ll, ll > > indexKeyPair;
    for(ll i = 0; i < queries; i++)
    {
        ll root;
        cin >> root;
        indexKeyPair.push_back(make_pair(i, root));
        cin >> u[i];
        cin >> v[i];
    }
    sort(indexKeyPair.begin(), indexKeyPair.end(), CompareNodes());
    vector< bool > visited(N + 1);
    vector< ll > level(N + 1);
    vector< ll > parent(N + 1, -1);
    vector< vector< ll > > jumpLevels(N + 1, vector< ll >(33, -1)); //maxJumLevel + 1 because of string size which may lead us to -1 node. 4 -> 100 while accessing [4][2] null pointer exception occurs since array size is not defined till 2 though its value is always going to be 0.

    for(ll i = 0; i < queries; i++)
    {
        if(i != 0 && indexKeyPair[i - 1].second == indexKeyPair[i].second)
        {
            ll index = indexKeyPair[i].first;
            ll root = indexKeyPair[i].second;
            ll index1 = u[index];
            ll index2 = v[index];
            ll lcaValue = returnLCAValue(index1, index2, level, jumpLevels, parent);
            solution[index] = lcaValue;
        }
        else
        {
            level.empty();
            for(ll l = 0; l < (N + 1); l++)
            {
                visited[l] = false;
            }
            for(ll l = 0; l < (N + 1); l++)
            {
                parent[l] = -1;
            }
            for(ll l = 0; l < (N + 1); l++)
            {
                for(ll m = 0; m < 33; m++)
                {
                    jumpLevels[l][m] = -1;
                }
            }
            maxLevel = 0;
            ll levelNow = 0;
            ll index = indexKeyPair[i].first;
            ll root = indexKeyPair[i].second;
            ll index1 = u[index];
            ll index2 = v[index];
            orderLevelsByRootDFS(visited, level, parent, levelNow, root, -1);
            maxJumpLevel = 0;
            for(ll j = 0; (1 << j) < maxLevel; j++)
            {
                maxJumpLevel++;
            }
            setJumpLevels(jumpLevels, parent, N);
            ll lcaValue = returnLCAValue(index1, index2, level, jumpLevels, parent);
            solution[index] = lcaValue;
        }
    }

    for(ll i = 0; i < queries; i++)
    {
        cout << solution[i] << endl;
    }
    return 0;
}
