#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class CompareHeapNodes
{
	public: 
		bool operator()(const ll val_1, const ll val_2) const
		{
			return val_1 > val_2;			
		}
};

int main() {
	vector< ll > vec{2,3,5,1,10,7};
	make_heap(vec.begin(), vec.end());
	ll head = vec.front();
	pop_heap(vec.begin(), vec.end());
	vec.pop_back();
	vec.push_back(100);
	push_heap(vec.begin(), vec.end());
	cout << "head: " << vec.front() << "\n";
	
	vector< ll > new_vec{3,5,1,49,100,10};
	make_heap(new_vec.begin(), new_vec.end(), CompareHeapNodes());
	cout << "new head: " << new_vec.front() << "\n";
	// your code goes here
	return 0;
}