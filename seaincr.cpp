#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector< ll > > rangeIndex(1000001);

void createFenwickTree(ll startingIndex, ll endingIndex, vector< ll > &fenwickTree, ll maximumValue)
{
    // for(ll i = startingIndex; i <= endingIndex;)
    // {
    //     while(i <= endingIndex)
    //     {
    //         fenwickTree[i] = max(fenwickTree[i], maximumValue);
    //         i += (i & -i);
    //     }
    // }
    ll i = startingIndex;
    while(i <= endingIndex)
    {
        fenwickTree[i] = max(fenwickTree[i], maximumValue);
        i += (i & -i);
    }
}

void updateDAG(ll index, vector< ll > &max, ll maxValue, vector< ll > &fenwickTree, ll n)
{
    if(maxValue > max[index])
    {
        // cout << "Index: " << index << endl;
        vector< ll >::iterator iter = rangeIndex[index].begin();
        for(; iter != rangeIndex[index].end(); iter++)
        {
            ll indexValue = *iter;
            // cout << "Index Value: " << indexValue << endl;
            updateDAG(indexValue, max, maxValue + 1, fenwickTree, n);
        }
        max[index] = maxValue;
        createFenwickTree(index, n, fenwickTree, maxValue);
    }
}

ll fenwickTreeRangeQuery(ll endingIndex, vector< ll > &fenwickTree, vector< ll > &max)
{
    ll exists = endingIndex;
    ll maxVal = 0;
    while(exists > 0)
    {
        ll valueNow = fenwickTree[exists];
        if(valueNow > maxVal)
        {
            maxVal = valueNow;
        }
        exists -= (exists & -exists);
    }
    return maxVal;
}

void printLast(vector< ll > &input, vector< ll > &last, ll n)
{
    cout << "----printLast----" << endl;
    for(ll i = 1; i <= n; i++)
    {
        cout << "Last of " << input[i] << " is " << last[input[i]] << endl;
    }
    cout << "----Function Ender----" << endl;
}

void printRangeIndex(ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        cout << "Range of " << i << " : ";
        vector< ll >::iterator iter = rangeIndex[i].begin();
        for(; iter != rangeIndex[i].end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    for(ll l = 0; l < testcases; l++)
    {
        ll n, q;
        cin >> n >> q;
        vector< ll > last(1000001);
        vector< ll > input(n + 1);
        vector< vector < pair< ll, ll > > > queries(n + 1);
        for(ll i = 1; i <= n + 1; i++)
        {
            rangeIndex[i].clear();
        }
        for(ll i = 1; i <= n; i++)
        {
            ll value;
            cin >> value;
            last[value] = i;
            input[i] = value;
            ll prev = 0;
            for(ll j = value - 1; j >= 1; j--)
            {
                if(last[j] > prev) //Since DAG is applied to all elements on the right irrespective of given range
                {
                    prev = last[j];
                    rangeIndex[prev].push_back(i);
                }
            }
        }
        // printLast(input, last, n);
        // printRangeIndex(n);
        for(ll i = 1; i <= q; i++)
        {
            ll startIndex, endIndex;
            cin >> startIndex >> endIndex;
            queries[startIndex].push_back(make_pair(endIndex, i));
        }

        vector< ll > solutionVect(q + 1);
        vector< ll > fenwickTree(1000001);
        vector< ll > max(1000001);
        // for(ll i = 1; i < 1000000; i++)
        // {
        //     vector< pair< ll, ll > >::iterator iter = queries[i].begin();
        //     bool shouldDAG = true;
        //     for(; iter != queries[i].end(); iter++)
        //     {
        //         vector< ll > max(10000001);
        //         vector< ll > fenwickTree(1000001);
        //         if(shouldDAG)
        //         {
        //             ll maxValue = 1;
        //             updateDAG(i, max, maxValue);
        //             createFenwickTree(0, n, fenwickTree, max);
        //             shouldDAG = false;
        //         }
        //         ll endIndex = iter -> first;
        //         ll solutionNumber = iter -> second;
        //         ll solution = fenwickTreeRangeQuery(endIndex, fenwickTree, max);
        //         solutionVect[solutionNumber] = solution;
        //     }
        // }

        for(ll i = n; i >= 1; i--)
        {
            updateDAG(i, max, 1, fenwickTree, n);
            vector< pair< ll, ll > >::iterator iter = queries[i].begin();
            for(; iter != queries[i].end(); iter++)
            {
                ll endIndex = iter -> first;
                ll solutionNumber = iter -> second;
                ll solution = fenwickTreeRangeQuery(endIndex, fenwickTree, max);
                solutionVect[solutionNumber] = solution;
            }
        }
        for(ll i = 1; i <= q; i++)
        {
            cout << solutionVect[i] << endl;
        }
    }
    return 0;
}
