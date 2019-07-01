#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N;
        cin >> N;
        ll solution = 0;
        for(ll i = 0; i < N; i++)
        {
            ll value;
            cin >> value;
            solution = solution ^ (2 * value);
        }
        cout << solution << endl;
    }
    return 0;
}
