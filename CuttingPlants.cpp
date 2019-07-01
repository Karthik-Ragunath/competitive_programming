#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector< ll > actual;
vector< ll > desired;
vector< ll > actualMin;
vector< ll > desiredMax;
ll maxCountGlobal = 0;

void divideAndConquer(ll leftIndex, ll rightIndex)
{
    ll maxCount = 0;
    ll maxValue = 0;
    ll maxIndex = -1;
    bool leftPossible = true;
    bool rightPossible = true;
    for(ll i = leftIndex; i <= rightIndex; i++)
    {
        if(desired[i] > maxValue)
        {
            maxValue = desired[i];
            maxCount = 0;
            maxIndex = i;
        }
        else if(desired[i] == maxValue)
        {
            maxCount++;
        }
    }
    maxCountGlobal += maxCount;
    if(rightIndex - leftIndex + 1 == maxCount)
    {
        return 0;
    }
    if(maxIndex == leftIndex || (leftIndex + 1) == maxIndex)
    {
        leftPossible = false;
    }
    if(maxIndex == rightIndex || (rightIndex - 1) == maxIndex)
    {
        rightPossible = false;
    }
    if(!rightPossible && !leftPossible)
    {
        return 0;
    }
    divideAndConquer()
}

int main()
{
    int testcases;
    cin >> testcases;
    for(ll h = 0; h < testcases; h++)
    {
        ll numberOfTerms;
        cin >> numberOfTerms;
        actual.clear();
        desired.clear();
        actualMin.clear();
        desiredMax.clear();
        for(ll j = 0; j < numberOfTerms; j++)
        {
            ll value;
            cin >> value;
            actual.push_back(value);
        }
        for(ll j = 0; j < numberOfTerms; j++)
        {
            ll value;
            cin >> value;
            desired.push_back(value);
        }
        ll maxDesired = 0;
        ll minActual = 1000000001;
        bool leftSet = false;
        ll leftIndex = 0;
        for(ll i = 0; i < numberOfTerms; i++)
        {
            if(desired[i] > actual[i])
            {
                cout << "-1" << endl;
                break;
            }
            else
            {
                if(!leftSet)
                {
                    leftIndex = i;
                    leftSet = true;
                }
                if(actaul[i] < minActual)
                {
                    minActual = actual[i];
                }
                if(minActual < maxDesired)
                {
                    divideAndConquer(leftIndex, i - 1);
                    leftSet = false;
                    minActual = actual[i];
                    maxDesired = 0;
                }
            }
            if(desired[i] > maxDesired)
            {
                maxDesired = desired[i];
            }
            actualMin.push_back(minActual);
            desiredMax.push_back(maxDesired);
        }
    }
    return 0;
}
