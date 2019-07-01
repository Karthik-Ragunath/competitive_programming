// https://www.hackerrank.com/challenges/largest-rectangle/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector< ll > inputs(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    stack< ll > buildingStack;
    ll maximum = 0;
    for(ll i = 0; i < n; i++)
    {
        while(!buildingStack.empty() && inputs[i] < inputs[buildingStack.top()])
        {
            ll index = buildingStack.top();
            buildingStack.pop();
            if(buildingStack.empty())
            {
                ll value = i * inputs[index];
                if(value > maximum)
                {
                    maximum = value;
                }
            }
            else
            {
                ll value = (i - buildingStack.top() - 1) * inputs[index];
                if(value > maximum)
                {
                    maximum = value;
                }
            }
        }
        buildingStack.push(i);
    }
    while(!buildingStack.empty())
    {
        ll index = buildingStack.top();
        buildingStack.pop();
        if(buildingStack.empty())
        {
            ll value = n * inputs[index];
            if(value > maximum)
            {
                maximum = value;
            }
        }
        else
        {
            ll value = (n - buildingStack.top() - 1) * inputs[index];
            if(value > maximum)
            {
                maximum = value;
            }
        }
    }
    cout << maximum << endl;
    return 0;
}
