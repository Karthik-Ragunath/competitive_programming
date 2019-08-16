#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll partition(vector< ll > &vec, ll lower, ll higher)
{
	ll pivot_index = higher;
	ll high = higher - 1;
	ll j = lower - 1; // j indicates last index of a vector element in lower array upto index processed
	for(ll i = lower; i <= high; i++)
	{
		if(vec[i] <= vec[pivot_index])
		{
			j++;
			ll value = vec[i];
			vec[i] = vec[j];
			vec[j] = value;
		}
	}
	j++;
	ll value = vec[pivot_index];
	vec[pivot_index] = vec[j];
	vec[j] = value;
	return j;
}

void quick_sort(vector< ll > &vec, ll lower, ll higher)
{
	if(lower < higher) // low == high denotes one element case which we do not want to process too :-)
	{
		ll pivot = partition(vec, lower, higher);
		cout << "lower: " << lower << " pivot: " << pivot << " higher: " << higher << "\n";
		// cout << "lower: " << lower << " pivot - 1: " << (pivot - 1) << "\n"; 
		quick_sort(vec, lower, pivot - 1);
		// cout << "pivot + 1: " << (pivot + 1) << " higher: " << higher << "\n"; 
		quick_sort(vec, pivot + 1, higher);
	}
	return; 
}

void print_vec(vector< ll > &vec)
{
	for(auto ele: vec)
	{
		cout << ele << " ";
	}
	cout << "\n";
}

int main()
{
	vector< ll > vec{89, 23, 45, 19, 45, 10, 35};
	ll vec_length = vec.size();
	quick_sort(vec, 0, vec_length - 1);
	print_vec(vec);
	return 0;
}