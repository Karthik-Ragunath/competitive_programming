#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, k;
    cin >> n >> k;
    vector< ll > inputs(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    sort(inputs.begin(), inputs.end());
    ll minDifference = 1000000001;
    for(ll i = k - 1; i < n; i++)
    {
        ll differenceNow = inputs[i] - inputs[i - (k - 1)];
        if(differenceNow < minDifference)
        {
            minDifference = differenceNow;
        }
    }
    cout << minDifference << endl;
    return 0;
}
