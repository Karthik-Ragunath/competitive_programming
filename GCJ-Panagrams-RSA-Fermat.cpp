#include<bits/stdc++.h>
using namespace std;
#define ll long long int

pair< ll, ll > fermat_factors(ll prime_number)
{
	double a = ceil(sqrt(prime_number));
	double b = a * a -  prime_number;
	while(sqrt(b) != ceil(sqrt(b)))
	{
		a = a + 1;
		b = a * a - prime_number;
	}
	return make_pair((ll)a, (ll)b);
}

int main()
{
	ll test;
	cin >> test;
	for(ll i = 0; i < test; i++)
	{
		ll upper_limit, n;
		cin >> upper_limit >> n;
		unordered_map< ll, pair< ll, ll > > prime_pair_dict;
		set< ll > primes_set;
		vector< ll > input_vec;
		for(ll j = 0; j < n; j++)
		{
			ll val;
			cin >> val;
			input_vec.push_back(val);
			pair< ll, ll > factors = fermat_factors(val);
			ll p1, p2;
			if(factors.first > factors.second)
			{
				p1 = factors.first - factors.second;
			}
			else
			{
				p1 = factors.second - factors.first;
			}
			p2 = factors.first + factors.second;
			primes_set.insert(p1);
			primes_set.insert(p2);
			prime_pair_dict[val] = make_pair(p1, p2);
		}
		string string_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		auto str_iter = string_alpha.begin();
		unordered_map< ll, char > prime_alpha_dict;
		for(auto iter1 = primes_set.begin(); iter1 != primes_set.end(); iter1++, str_iter++)
		{
			prime_alpha_dict[*iter1] = *str_iter;
		}
		string solution = "";
		for(ll i = 0; i < n; i++)
		{
			pair< ll, ll > p_pair = prime_pair_dict[input_vec[i]];
			char a = prime_alpha_dict[p_pair.first];
			solution += a;
			if(i == (n - 1))
			{
				char b = prime_alpha_dict[p_pair.second];
				solution += b;
			}
		}
		cout << solution << endl;
	}
	return 0;
}