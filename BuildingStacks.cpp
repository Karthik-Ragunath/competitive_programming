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
    vector< ll > buildingStack;
    ll maximum = inputs[0];
    for(ll i = 1; i < n; i++)
    {
        ll currentInputIndex = i;
        while(!buildingStack.empty() && inputs[buildingStack.back()] > inputs[i])
        {
            buildingStack.pop_back();
        }
        while(!buildingStack.empty() && inputs[buildingStack.back()] == inputs[i])
        {
            currentInputIndex = buildingStack.back();
            buildingStack.pop_back();
        }
        if(buildingStack.empty())
        {
            ll value = (i + 1) * inputs[i];
            if(value > maximum)
            {
                maximum = value;
            }
        }
        else
        {
            ll value = (i - buildingStack.back()) * inputs[i];
            if(value > maximum)
            {
                maximum = value;
            }
        }
        buildingStack.push_back(currentInputIndex);
    }
    cout << maximum << endl;
    return 0;
}
