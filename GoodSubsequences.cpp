#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll fastExp(ll base, ll expo)
{
    ll result = 1;
    while(expo > 0)
    {
        if(expo % 2 == 1)
        {
            result *= base;
        }
        base = base * base;
        expo /= 2;
    }
    return result;
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        ll N, divisor;
        cin >> N >> divisor;
        vector< ll > input(N);
        for(ll i = 0; i < N; i++)
        {
            cin >> input[i];
        }
        ll count = 0;
        for(ll i = 0; i < N; i++)
        {
            if(input[i] % divisor == 0)
            {
                count++;
            }
        }
        ll fastExponential = fastExp(2, count);
        ll solution = fastExponential - 1;
        cout << solution << endl;
    }
    return 0;
}
