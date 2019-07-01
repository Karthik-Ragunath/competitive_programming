#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void createFenwickTree(vector< ll > &fenwickTree, ll index, ll endingIndex, ll value)
{
    for(; index <= endingIndex;)
    {
        fenwickTree[index] += value;
        index += (index & -index);
    }
}

void updateFenwickTree(vector< ll > &fenwickTree, ll index, ll endingIndex, ll value)
{
    for(; index <= endingIndex;)
    {
        fenwickTree[index] += value;
        index += (index & -index);
    }
}

ll rangeQuery(vector< ll > &fenwickTree, ll endIndex)
{
    ll sum = 0;
    for(ll index = endIndex; index > 0;)
    {
        sum += fenwickTree[index];
        index -= (index & -index);
    }
    return sum;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector< ll > values(n + 1);
    vector< ll > fenwickTree(n + 1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> values[i];
        createFenwickTree(fenwickTree, i, n, values[i]);
    }
    for(ll i = 0; i < q; i++)
    {
        ll type;
        cin >> type;
        if(type == 1)
        {
            ll index, value;
            cin >> index >> value;
            ll difference = value - values[index];
            values[index] = value;
            updateFenwickTree(fenwickTree, index, n, difference);
        }
        else
        {
            ll startRange, endRange;
            cin >> startRange >> endRange;
            ll solution = rangeQuery(fenwickTree, endRange) - rangeQuery(fenwickTree, startRange - 1);
            cout << solution << endl;
        }
    }
    return 0;
}
