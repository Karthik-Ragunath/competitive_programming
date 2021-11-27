#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector< ll > input(n);
    ll maximumValue = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector< ll > buildingStack;
    for(ll i = 0; i < n; i++)
    {
        if((!buildingStack.empty() && input[buildingStack.back()] <= input[i]) || buildingStack.empty())
        {
            // cout << "Push Back" << i << endl;
            buildingStack.push_back(i);
        }
        else
        {
            while(!buildingStack.empty() && input[buildingStack.back()] > input[i])
            {
                ll index = buildingStack.back();
                ll value = (i - index) * input[index];
                if(value > maximumValue)
                {
                    maximumValue = value;
                    // cout << index << " " << maximumValue << endl;
                }
                buildingStack.pop_back();
            }
            buildingStack.push_back(i);
        }
    }
    while(!buildingStack.empty())
    {
        ll index = buildingStack.back();
        ll value = (n - index) * input[index];
        if(value > maximumValue)
        {
            maximumValue = value;
            // cout << index << " " << maximumValue << endl;
        }
        buildingStack.pop_back();
    }
    cout << maximumValue << endl;
    return 0;
}
