#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll sqrtValue = 32000;
vector<ll> primes;
ll size = 0;

void generatePrimes()
{
    vector < bool > actualPrimes(sqrtValue, true);
    actualPrimes[0] = false;
    actualPrimes[1] = false;
    for(ll i = 4; i <= sqrtValue; i += 2)
    {
        actualPrimes[i] = false;
    }
    ll locSqrtValue = sqrt(sqrtValue);
    for(ll i = 3; i <= locSqrtValue; i += 2)
    {
        if(actualPrimes[i])
        {
            for(ll j = i * i; j <= sqrtValue; j += (i * 2))
            {
                actualPrimes[j] = false;
            }
        }
    }
    primes.push_back(2);
    for(ll i = 3; i <= sqrtValue; i += 2)
    {
        if(actualPrimes[i])
        {
            primes.push_back(i);
        }
    }
}

ll gcd(ll a, ll b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

vector<ll> divisors(ll value)
{
    ll localSqrtValue = sqrt(value);
    vector<ll> solution;
    size = 0;
    for(ll i = 0; primes[i] <= localSqrtValue; i++)
    {
        if(value % primes[i] == 0)
        {
            solution.push_back(primes[i]);
            size++;
            while(value % primes[i] == 0)
            {
                value = value / primes[i];
            }
        }
    }
    if(value != 1)
    {
        solution.push_back(value);
        size++;
    }
    return solution;
}

int main()
{
    ll testcases;
    cin >> testcases;
    generatePrimes();
    for(ll k = 0; k < testcases; k++)
    {
        ll N, K;
        cin >> N >> K;
        vector<ll> elements(N);
        cin >> elements[0];
        ll gcdOfArray = elements[0];
        for(ll i = 1; i < N; i++)
        {
            cin >> elements[i];
            if(gcdOfArray > K)
            {
                gcdOfArray = gcd(gcdOfArray, elements[i]);
            }
        }
        if(gcdOfArray <= K)
        {
            cout << "YES" << endl;
        }
        else
        {
            vector< ll > gcdOfArrayDivisors = divisors(gcdOfArray);
            ll sizeOfGCDArrayDivisors = size;
            vector< ll > KDivisors = divisors(K);
            ll sizeOfKDivisors = size;
            if(sizeOfGCDArrayDivisors == sizeOfKDivisors)
            {
                bool solutionExists = true;
                for(ll i = 0; i < sizeOfKDivisors; i++)
                {
                    if(gcdOfArrayDivisors[i] != KDivisors[i])
                    {
                        solutionExists = false;
                        break;
                    }
                }
                if(solutionExists)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
