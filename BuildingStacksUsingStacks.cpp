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
    stack< ll > buildingStack11;
    ll maximum1 = inputs[n - 1];
    buildingStack1.push(n - 1);
    for(ll i = n - 2; i >= 0; i--)
    {
        while(!buildingStack1.empty() && inputs[buildingStack1.top()] >= inputs[i])
        {
            buildingStack1.pop();
            cout << "Popped" << endl;
        }
        if(buildingStack1.empty())
        {
            ll value = (n - i) * inputs[i];
            if(value > maximum1)
            {
                maximum1 = value;
            }
        }
        else
        {
            ll value = (buildingStack1.top() - i) * inputs[i];
            cout << "Value : " << value << endl;
            if(value > maximum1)
            {
                maximum1 = value;
            }
        }
        buildingStack1.push(i);
    }
    cout << maximum1 << endl;
    return 0;
}
