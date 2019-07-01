#include <bits/stdc++.h>
using namespace std;
#define ll long long int

map<ll, ll> mappy;
ll sqrtValue;
ll solution = 0;

class CompareNodesVector
{
    public:
        bool operator()(const pair< ll, pair< ll, ll > > &node1, const pair< ll, pair< ll, ll > > &node2)
        {
            if(node1.first / sqrtValue != node2.first / sqrtValue)
            {
                return node1.first / sqrtValue < node2.first / sqrtValue;
            }
            return node1.second.first < node2.second.first;
        }
};

void add(ll index)
{
    map<ll, ll>::iterator iter = mappy.find(index);
    if(iter != mappy.end())
    {
        iter -> second = iter -> second + 1;
        if(iter -> second == index)
        {
            solution++;
        }
    }
    else
    {
        mappy.insert(make_pair(index, 1));
        if(index == 1)
        {
            solution++;
        }
    }
}

void remove(ll index)
{
    map<ll, ll>::iterator iter = mappy.find(index);
    if(iter != mappy.end())
    {
        if(iter -> second == index)
        {
            solution--;
        }
        iter -> second -= 1;
    }
    else
    {
        mappy.insert(make_pair(index, -1));
    }
}

int main()
{
    ll numberOfTerms;
    ll queries;
    cin >> numberOfTerms;
    cin >> queries;
    vector< ll > values;
    vector< pair< ll, pair < ll, ll > > > vectorPairs;
    sqrtValue = sqrt(numberOfTerms);
    values.push_back(-1);
    for(ll i = 0; i < numberOfTerms; i++)
    {
        ll value;
        cin >> value;
        values.push_back(value);
    }
    for(ll i = 0; i < queries; i++)
    {
        ll queryLeft, queryRight;
        cin >> queryLeft >> queryRight;
        vectorPairs.push_back(make_pair(queryLeft, make_pair(queryRight, i)));
    }
    sort(vectorPairs.begin(), vectorPairs.end(), CompareNodesVector());
    ll currentLeft = 0;
    ll currentRight = 0;
    vector< ll > solutionVect(queries);
    for(ll i = 0; i < queries; i++)
    {
        ll leftValue = vectorPairs[i].first;
        ll rightValue = vectorPairs[i].second.first;

        // cout << "Current Left: " << currentLeft << endl;
        // cout << "Current Right: " << currentRight << endl;
        // cout << "Left Value: " << leftValue << endl;
        // cout << "Right Value: " << rightValue << endl;

        if(currentLeft < leftValue)
        {
            while(currentLeft < leftValue)
            {
                remove(values[currentLeft]);
                currentLeft++;
            }
        }
        else
        {
            while(currentLeft > leftValue)
            {
                add(values[currentLeft - 1]); //Because this value is already included in solution.
                currentLeft--;
            }
        }

        if(currentRight < rightValue)
        {
            while(currentRight < rightValue)
            {
                add(values[currentRight + 1]);//Because this value is already included in solution.
                currentRight++;
            }
        }
        else
        {
            while(currentRight > rightValue)
            {
                remove(values[currentRight]);
                currentRight--;
            }
        }
        solutionVect[vectorPairs[i].second.second] = solution;
    }

    for(ll i = 0; i < queries; i++)
    {
        cout << solutionVect[i] << endl;
    }
    return 0;
}
