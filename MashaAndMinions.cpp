#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        ll N;
        cin >> N;
        vector< ll > power(N);
        vector< ll > endurance(N);
        for(ll i = 0; i < N; i++)
        {
            cin >> power[i];
        }
        for(ll i = 0; i < N; i++)
        {
            cin >> endurance[i];
        }
        
    }
    return 0;
}
