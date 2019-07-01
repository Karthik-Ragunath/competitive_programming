#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll N;
    cin >> N;
    set< ll > setter;
    for(ll n = 0; n < N; n++)
    {
        ll temp;
        cin >> temp;
        setter.insert(temp);
    }
    ll size = setter.size();
    cout << size << endl;
    return 0;
}
