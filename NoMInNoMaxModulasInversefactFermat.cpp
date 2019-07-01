#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector< ll > factorialVector(5000 + 1);
vector< ll > inverseFactorialVector(5000 + 1);

ll mod = 1000000007;
ll primeMod1 = 500000003;
ll primeMod2 = 2;

ll power(ll a, ll b)
{
	ll x = 1, y = a;
	while (b > 0)
    {
		if (b % 2)
        {
			x = (x * y) % mod;
		}
		y = (y * y) % mod;
		b /= 2;
	}
	return x % mod;
}

ll modularInverse(ll n)
{
	return power(n, mod-2) % mod;
}

ll powerMod(ll a, ll b, ll modInv)
{
	ll x = 1, y = a;
	while (b > 0)
	{
		if (b % 2)
		{
			x = (x * y) % modInv;
		}
		y = (y * y) % modInv;
		b /= 2;
	}
	return x % modInv;
}

ll inverseModular(ll n, ll p)
{
	return powerMod(n, p - 2, p) % p;
}

ll calculateInverse(ll value)
{
    ll mod1 = inverseModular(value, primeMod1);
	ll mod2 = inverseModular(value, primeMod2);
	ll mod3 = inverseModular(primeMod2, primeMod1);
    ll valueInter = (mod1 - mod2) * mod3;
	ll interMod = valueInter % primeMod1 + ((valueInter % primeMod1) < 0 ? primeMod1 : 0);
	ll valueNow = (mod2 + primeMod2 * interMod) % (mod - 1);
    return valueNow;
}

void calculateFactorial()
{
    factorialVector[0] = 1;
    inverseFactorialVector[0] = 1;
    for(ll i = 1; i <= 5000; i++)
    {
        factorialVector[i] = (factorialVector[i - 1] * i) % (mod - 1);
    }
	// ll mod1 = inverseModular(factorialVector[5000], primeMod1);
	// ll mod2 = inverseModular(factorialVector[5000], primeMod2);
	// ll mod3 = inverseModular(primeMod2, primeMod1);
	// ll valueInter = (mod1 - mod2) * mod3;
	// ll interMod = valueInter % primeMod1 + ((valueInter % primeMod1) < 0 ? primeMod1 : 0);
	// ll value = (mod2 + primeMod2 * interMod) % (mod - 1);
	// // inverseFactorialVector[5000] = modularInverse(factorialVector[5000]) % (mod - 1);
	// inverseFactorialVector[5000] = value;
    inverseFactorialVector[0] = 1;
    for(ll i = 1; i <= 5000; i++)
    {
        inverseFactorialVector[i] = (inverseFactorialVector[i - 1] * calculateInverse(i)) % (mod - 1);
    }
}

ll nCr(ll n, ll r)
{
    ll denominatorInverse = (inverseFactorialVector[n - r] * inverseFactorialVector[r]) % (mod - 1);
    ll combinationsCounter = (factorialVector[n] * denominatorInverse) % (mod - 1);
    return combinationsCounter % (mod - 1);
}

ll combinationsCount(ll smaller, ll larger, ll N, ll K)
{
    ll maxPossibleOnOneSide = K - 2;
    ll solution = 0;
    for(ll i = 1, j = maxPossibleOnOneSide; i <= (K - 2); i++, j--)
    {
        if(i <= smaller)
        {
            if(j <= larger)
            {
                // cout << "n: " << smaller << " r: " << i;
                ll solution1 = nCr(smaller, i) % (mod - 1);
                // cout << " solution: " << solution1 << endl;
                // cout << "n: " << larger << " r: " << j;
                ll solution2 = nCr(larger, j) % (mod - 1);
                // cout << " solution: " << solution2 << endl;
                solution = (solution + ((solution1 * solution2) % (mod - 1))) % (mod - 1);
            }
            else
            {
                continue;
            }
        }
        else
        {
            break;
        }
    }
    // if(N != K)
    // {
    //     return ((solution * factorialVector[K - 2]) % mod);
    // }
    // else
    // {
    //     return solution;
    // }
    return solution % (mod - 1);
}

void printSolutionVect(vector< ll > &input, vector< ll > &solutionVect, ll N)
{
    for(ll i = 1; i < (N - 1); i++)
    {
        cout << "Solution at " << i << " : " << solutionVect[i] << " input[i]: " << input[i] << endl;
    }
}

ll getSolution(vector< ll > &input, vector< ll > &solutionVect, ll N)
{
    ll solution = 1;
    for(ll i = 1; i < (N - 1); i++)
    {
        solution = (solution * (power(input[i], solutionVect[i]) % mod)) % mod;
    }
    return solution % mod;
}

int main()
{
    ll testcases;
    cin >> testcases;
    calculateFactorial();
    for(ll n = 0; n < testcases; n++)
    {
        ll N, K;
        cin >> N >> K;
        vector< ll > input(N);
        vector< ll > count(N);
        for(ll i = 0; i < N; i++)
        {
            cin >> input[i];
        }
        sort(input.begin(), input.end());
        vector< ll > solutionVect(N);
        for(ll i = 1, j = (N - 2); i < (N - 1); i++, j--)
        {
            if(j < i)
            {
                break;
            }
            else
            {
                ll numberOfTermsOnLeft = i;
                ll numberOfTermsOnRight = N - 1 - i;
                // cout << "i: " << i << " numberOfTermsOnLeft: " << numberOfTermsOnLeft << " numberOfTermsOnRight: " << numberOfTermsOnRight << endl;
                if(numberOfTermsOnLeft <= numberOfTermsOnRight)
                {
                    ll numberOfCombinations = combinationsCount(numberOfTermsOnLeft, numberOfTermsOnRight, N, K) % (mod - 1);
                    solutionVect[numberOfTermsOnLeft] = numberOfCombinations % (mod - 1);
                    solutionVect[numberOfTermsOnRight] = numberOfCombinations % (mod - 1);
                }
                else
                {
                    ll numberOfCombinations = combinationsCount(numberOfTermsOnRight, numberOfTermsOnLeft, N, K) % (mod - 1);
                    solutionVect[numberOfTermsOnLeft] = numberOfCombinations;
                    solutionVect[numberOfTermsOnRight] = numberOfCombinations;
                }
            }
        }
        // printSolutionVect(input, solutionVect, N);
        ll answer = (getSolution(input, solutionVect, N) % mod);
        cout << (answer % mod) << endl;
    }
    return 0;
}
