#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll sqrtValue;
ll solution = 0;

class CompareNodesVector
{
    public:
        bool operator()(const pair< ll, ll > &node1, const pair< ll, ll > &node2)
        {
            if(node1.first / sqrtValue != node2.first / sqrtValue)
            {
                return node1.first / sqrtValue < node2.first / sqrtValue;
            }
            return node1.second < node2.second;
        }
};

void add(vector< ll > &frequency, ll index)
{
    frequency[index]++;
    if(frequency[index] == index)
    {
        solution++;
    }
}

void remove(vector< ll > &frequency, ll index)
{
    if(frequency[index] == index)
    {
        solution--;
    }
    frequency[index]--;
}

int main()
{
    ll numberOfTerms;
    ll queries;
    cin >> numberOfTerms;
    cin >> queries;
    vector< ll > values;
    vector< pair< ll, ll > > vectorPairs;
    vector< ll > frequency(numberOfTerms + 1);
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
        vectorPairs.push_back(make_pair(queryLeft, queryRight));
    }
    sort(vectorPairs.begin(), vectorPairs.end(), CompareNodesVector());
    ll currentLeft = 0;
    ll currentRight = 0;
    for(ll i = 0; i < queries; i++)
    {
        ll leftValue = vectorPairs[i].first;
        ll rightValue = vectorPairs[i].second;

        // cout << "Current Left: " << currentLeft << endl;
        // cout << "Current Right: " << currentRight << endl;
        // cout << "Left Value: " << leftValue << endl;
        // cout << "Right Value: " << rightValue << endl;

        if(currentLeft < leftValue)
        {
            while(currentLeft < leftValue)
            {
                remove(frequency, values[currentLeft]);
                currentLeft++;
            }
        }
        else
        {
            while(currentLeft > leftValue)
            {
                add(frequency, values[currentLeft - 1]); //Because this value is already included in solution.
                currentLeft--;
            }
        }

        if(currentRight < rightValue)
        {
            while(currentRight < rightValue)
            {
                add(frequency, values[currentRight + 1]);//Because this value is already included in solution.
                currentRight++;
            }
        }
        else
        {
            while(currentRight > rightValue)
            {
                remove(frequency, values[currentRight]);
                currentRight--;
            }
        }
        cout << solution << endl;
    }
    return 0;
}
