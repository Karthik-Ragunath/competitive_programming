#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector< ll > actual;
vector< ll > desired;
ll maxCountGlobal = 0;

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
        vector< ll > cutPoints;
        bool broken = false;
        for(ll i = 0; i < numberOfTerms; i++)
        {
            if(desired[i] > actual[i])
            {
                cout << "-1" << endl;
                broken = true;
                break;
            }
            else
            {
                if(actual[i] < minActual)
                {
                    minActual = actual[i];
                }
                if(desired[i] > maxDesired)
                {
                    maxDesired = desired[i];
                }
                if(minActual < maxDesired)
                {
                    cutPoints.push_back(i);
                    minActual = actual[i];
                    maxDesired = desired[i];
                }
            }
        }
        if(broken)
        {
            continue;
        }
        ll cutPointsSize = cutPoints.size();
        ll leftMin = 0;
        ll numberOfCuts = 0;
        for(ll i = 0; i < cutPointsSize; i++)
        {
            ll rightMax = cutPoints[i];
            map< ll, ll >  mappy;
            for(ll j = leftMin; j < rightMax; j++)
            {
                ll value = desired[j];
                if(value == actual[j])
                {
                    continue;
                }
                map< ll, ll >::iterator iter = mappy.find(value);
                if(iter != mappy.end())
                {
                    iter -> second = iter -> second + 1;
                }
                else
                {
                    mappy.insert(make_pair(value, 1));
                }
            }
            numberOfCuts += mappy.size();
            leftMin = rightMax;
        }
        map< ll, ll >  mappy;
        for(ll j = leftMin; j < numberOfTerms; j++)
        {
            ll value = desired[j];
            if(value == actual[j])
            {
                continue;
            }
            map< ll, ll >::iterator iter = mappy.find(value);
            if(iter != mappy.end())
            {
                iter -> second = iter -> second + 1;
            }
            else
            {
                mappy.insert(make_pair(value, 1));
            }
        }
        numberOfCuts += mappy.size();
        cout << numberOfCuts << endl;
    }
    return 0;
}
