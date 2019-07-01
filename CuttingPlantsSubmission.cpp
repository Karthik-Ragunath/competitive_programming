// https://www.codechef.com/APRIL18B/problems/CUTPLANT
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        ll numberOfTerms;
        cin >> numberOfTerms;
        vector< ll > actualValues;
        vector< ll > desiredValues;
        vector< ll > dequeDS;
        ll solution = 0;
        for(ll j = 0; j < numberOfTerms; j++)
        {
            ll value;
            cin >> value;
            actualValues.push_back(value);
        }
        for(ll j = 0; j < numberOfTerms; j++)
        {
            ll value;
            cin >> value;
            desiredValues.push_back(value);
        }
        bool broken = false;
        for(ll j = 0; j < numberOfTerms; j++)
        {
            if(actualValues[j] < desiredValues[j])
            {
                cout << "-1" << endl;
                broken = true;
                break;
            }
            else
            {
                while(!dequeDS.empty() && dequeDS.front() > actualValues[j])
                {
                    dequeDS.erase(dequeDS.begin());
                }
                while(!dequeDS.empty() && dequeDS.back() < desiredValues[j])
                {
                    dequeDS.pop_back();
                }
                if(actualValues[j] != desiredValues[j])
                {
                    if(dequeDS.empty() || desiredValues[j] < dequeDS.back()) //Only if already an element exists and current element is equal to previous element, solution does not gets increased (Current element cannot be greater than previous element due to previous conditions)
                    {
                        dequeDS.push_back(desiredValues[j]);
                        solution++;
                    }
                }
            }
        }
        if(!broken)
        {
            cout << solution << endl;
        }
    }
    return 0;
}
