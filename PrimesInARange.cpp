#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector< bool > primes(10000001, true);
vector< ll > fenwickTree(10000001);

void createFenwickTree(ll index)
{
    for(; index <= 10000000;)
    {
        fenwickTree[index] += 1;
        index += (index & -index);
    }
}

ll rangePrimeCount(ll index)
{
    ll sum = 0;
    for(; index > 0;)
    {
        sum += fenwickTree[index];
        index -= (index & -index);
    }
    return sum;
}

void generatePrimes()
{
    for(ll i = 4; i <= 10000000; i += 2)
    {
        primes[i] = false;
    }
    primes[0] = false;
    primes[1] = false;
    for(ll i = 3; i <= sqrt(10000000); i += 2)
    {
        if(primes[i])
        {
            for(ll j = i * i; j <= 10000000; j += (i * 2))
            {
                primes[j] = false;
            }
        }
    }
}

void generateFenwickTree()
{
    createFenwickTree(2);
    for(ll i = 3; i <= 10000000; i += 2)
    {
        if(primes[i])
        {
            createFenwickTree(i);
        }
    }
}

int main()
{
    generatePrimes();
    generateFenwickTree();
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        ll startIndex, endIndex;
        cin >> startIndex >> endIndex;
        ll solution = rangePrimeCount(endIndex) - rangePrimeCount(startIndex - 1);
        cout << solution << endl;
    }
    return 0;
}
