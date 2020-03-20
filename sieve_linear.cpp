#include< bits/stdc++.h >
#define ll long long int

int main()
{
	// find all primes less than n
	ll n;
	cin >> n;
	vector< ll > primes;
	vector< ll > min_factors(n + 1);
	// assume min_factor[i] = 0 when that number is processed indicates that it is zero.
	for(ll i = 2; i <= n; i++)
	{
		if(min_factors[i] == 0)
		{
			primes.push_back(i);
			min_factors[i] = i;
		}
		for(ll j = 0; j < primes.size() and primes[j] <= min_factors[i] and i * primes[j] <= n; j++)
		{
			min_factors[i * primes[j]] = primes[j];
		}
	}
	return 0;
}