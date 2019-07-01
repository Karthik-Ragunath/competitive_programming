#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	stack< ll > stacks;
	stacks.push(6);
	stacks.push(7);
	ll top = stacks.top();
	cout << top << endl;
	stacks.pop();
	cout << stacks.top() << endl;
	// your code goes here
	return 0;
}
