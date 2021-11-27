#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll visitedCount = 0;

void dfs(vector< bool > &visited, vector< vector< ll > > &children, ll index)
{
    visited[index] = true;
    visitedCount++;
    vector< ll >::iterator iter = children[index].begin();
    for(;iter != children[index].end(); iter++)
    {
        if(!visited[*iter])
        {
            dfs(visited, children, *iter);
        }
    }
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll numberOfTerms, numberOfQueries;
        cin >> numberOfTerms >> numberOfQueries;
        vector< bool > visited(numberOfTerms + 1, false);
        vector< vector < ll > > children(numberOfTerms + 1);
        for(ll i = 0; i < numberOfQueries; i++)
        {
            ll node1Index, node2Index;
            cin >> node1Index >> node2Index;
            children[node1Index].push_back(node2Index);
            children[node2Index].push_back(node1Index);
        }
        vector< ll > solution;
        ll numberOfRoutes = 0;
        for(ll i = 1; i <= numberOfTerms; i++)
        {
            if(!visited[i])
            {
                numberOfRoutes++;
                visitedCount = 0;
                dfs(visited, children, i);
                solution.push_back(visitedCount);
            }
        }
        vector< ll >::iterator iter = solution.begin();
        ll numberOfCaptains = 1;
        for(; iter != solution.end(); iter++)
        {
            numberOfCaptains = (numberOfCaptains * (*iter)) % 1000000007;
        }
        cout << numberOfRoutes << " " << numberOfCaptains << endl;
    }
}
