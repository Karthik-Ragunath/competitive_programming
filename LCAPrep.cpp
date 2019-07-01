#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector< ll > > nodes(2 * 100000 + 1);
vector< ll > queries(2 * 100000 + 1);
vector< ll > levels(2 * 100000 + 1);
vector< ll > visited(2 * 100000 + 1);
vector< ll > parents(2 * 100000 + 1);
ll maxLevel = 0;
ll maxNumberOfJumpLevels = 0;
vector< string > binaryStrings(2 * 100000 + 3);

void dfs(ll currentIndex, ll currentLevel)
{
    visited[currentIndex] = true;
    levels[currentIndex] = currentLevel + 1;
    //cout << "Current Index: " << currentIndex << " CurrentLevel: " << levels[currentIndex] << endl;
    if(maxLevel < levels[currentIndex])
    {
        maxLevel = levels[currentIndex];
    }
    vector< ll >::iterator childrenNodesIter = nodes[currentIndex].begin();
    for(; childrenNodesIter != nodes[currentIndex].end(); childrenNodesIter++)
    {
        // cout << "Parent Index: " << currentIndex << " Children Index: " << *childrenNodesIter << endl;
        if(!visited[*childrenNodesIter])
        {
            parents[*childrenNodesIter] = currentIndex;
            dfs(*childrenNodesIter, currentLevel + 1);
        }
    }
}

void setJumpLevels(ll N, vector< vector< ll > > &jumpLevels)
{
    for(ll i = 1; i <= N; i++)
    {
        //cout << "i: " << i << " " << parents[i] << endl;
        jumpLevels[i][0] = parents[i];
    }
    for(ll j = 1; j < maxNumberOfJumpLevels; j++)
    {
        for(ll i = 1; i <= N; i++)
        {
            if(jumpLevels[i][j - 1] != -1)
            {
                jumpLevels[i][j] = jumpLevels[jumpLevels[i][j - 1]][j - 1];
                //cout << "i: " << i << " j: " << j << " jumpLevels[i][j]: " << jumpLevels[i][j] << endl;
            }
        }
    }
}

void generateStrings()
{
    binaryStrings[0] = "0";
    binaryStrings[1] = "1";
    queue< string > headQueue;
    headQueue.push("1");
    ll count = 1;
    while(true)
    {
        string s1 = headQueue.front();
        string s2 = s1;
        headQueue.pop();
        s1 = s1 + '0';
        s2 = s2 + '1';
        binaryStrings[count + 1] = s1;
        binaryStrings[count + 2] = s2;
        count += 2;
        if(count > (2 * 100000))
        {
            break;
        }
        headQueue.push(s1);
        headQueue.push(s2);
    }
}

void swap(ll &u, ll &v)
{
    ll temp = u;
    u = v;
    v = temp;
}

ll LCA(ll u, ll v, ll N, vector< vector< ll > > &jumpLevels)
{
    ll uLevel = levels[u];
    ll vLevel = levels[v];
    // cout << "U Level: " << uLevel << " V Level: " << vLevel << endl;
    if(uLevel > vLevel)
    {
        swap(u, v);
        swap(uLevel, vLevel);
    }
    if(uLevel != vLevel)
    {
        //cout << "Not same level" << endl;
        ll levelDiff = vLevel - uLevel;
        string stringValOfLevelDiff = binaryStrings[levelDiff];
        ll stringLength = stringValOfLevelDiff.size();
        ll greaterValue = v;
        for(ll i = 0, j = stringLength - 1; i < stringLength; i++, j--)
        {
            if(stringValOfLevelDiff[i] == '1')
            {
                greaterValue = jumpLevels[greaterValue][j];
            }
        }
        v = greaterValue;
    }
    if(u != v)
    {
        string desiredString = binaryStrings[uLevel];
        //cout << "Desired String: " << desiredString << endl;
        ll desiredLength = desiredString.size();
        for(ll i = 0, j = desiredLength - 1; i < desiredLength; i++, j--)
        {
            ll tempU = jumpLevels[u][j];
            ll tempV = jumpLevels[v][j];
            // cout << "J: " << j << " U: " << u << " V: " << v << " levelU: " << jumpLevels[u][j] << " levelV: " << jumpLevels[v][j] << endl;
            if(tempU != tempV)
            {
                u = tempU;
                v = tempV;
            }
        }
        ll lca = parents[u];
        return lca;
    }
    else
    {
        return u;
    }
}

void setMaxNumberOfJumpLevels()
{
    ll i;
    //cout << "Max Level: " << maxLevel << endl;
    for(i = 0; (1 << i) <= maxLevel; i++);
    maxNumberOfJumpLevels = i + 1;
}

int main()
{
    ll N;
    cin >> N;
    for(ll n = 1; n < N; n++)
    {
        ll vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        nodes[vertex1].push_back(vertex2);
        nodes[vertex2].push_back(vertex1);
    }
    ll currentIndex = 1;
    ll currentLevel = -1;
    parents[1] = -1;
    dfs(currentIndex, currentLevel);
    setMaxNumberOfJumpLevels();
    vector< vector< ll > > jumpLevels(N + 1, vector< ll >(maxNumberOfJumpLevels));
    setJumpLevels(N, jumpLevels);
    generateStrings();
    ll Q;
    cin >> Q;
    for(ll n = 1; n <= Q; n++)
    {
        ll r, u, v;
        cin >> r >> u >> v;
        ll lca = LCA(u, v, N, jumpLevels);
        cout << lca << endl;
    }
    return 0;
}
