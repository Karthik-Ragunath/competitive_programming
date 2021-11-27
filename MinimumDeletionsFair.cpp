#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll computeGCD(ll a, ll b)
{
    if(a == 0)
    {
        return b;
    }
    return computeGCD(b % a, a);
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N;
        cin >> N;
        vector< ll > terms;
        ll gcd;
        cin >> gcd;
        for(ll i = 1; i < N; i++)
        {
            ll value;
            cin >> value;
            gcd = computeGCD(gcd, value);
        }
        if(gcd > 1)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}
