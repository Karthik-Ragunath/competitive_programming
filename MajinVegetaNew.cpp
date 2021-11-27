#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< ll > primeDivisors(1000001);
ll sqrtValue = 1000;
vector<ll> primes(1000001, true);

void generatePrimes()
{
    primes[0] = false;
    primes[1] = false;
    for(ll i = 4; i <= 1000000; i += 2)
    {
        primes[i] = false;
        primeDivisors[i]++;
    }
    for(ll i = 3; i <= 1000000; i += 2)
    {
        if(primes[i])
        {
            for(ll j = i * 2; j <= 1000000; j += i)
            {
                primes[j] = false;
                primeDivisors[j]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    generatePrimes();
    for(ll k = 0; k < testcases; k++)
    {
        ll n, m;
        cin >> n >> m;
        ll solution = 0;
        for(ll i = n; i < m; i++)
        {
        	if(i == 1)
        	{
        	    continue;
        	}
            if(primeDivisors[i] == 0 || primeDivisors[i] == 1)
            {
                solution += 1;
            }
            else
            {
                solution += primeDivisors[i];
            }
        }
         cout << solution << endl;
    }
    return 0;
}
