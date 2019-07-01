#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	vector< pair< int, int > > vec(3);
	vec[0] = make_pair(1,2);
	vec[1] = make_pair(2,3);
	vec[2] = make_pair(3,4);
	for(auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << iter -> first << " " << iter -> second << " ";
	}
	cout << endl;
	fill(vec.begin(), vec.end(), make_pair(0, 0));
	for(auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << iter -> first << " " << iter -> second << " ";
	}
	// your code goes here
	return 0;
}