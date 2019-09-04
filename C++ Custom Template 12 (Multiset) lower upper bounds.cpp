// C++ program to demonstrate 
// multiset::erase() method 

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

	// Initialise the multiset 
	multiset<int> multi_set; 
	multiset<int>::iterator ms_iterator; 

	// Add values to the multiset 
	for (int i = 1; i < 10; i++) { 
		multi_set.insert(i); 
	} 
  	multi_set.insert(2);
  	multi_set.insert(2);
  	multi_set.insert(2);

	cout << "Original multiset: "; 

	for (ms_iterator = multi_set.begin(); 
		ms_iterator != multi_set.end(); 
		++ms_iterator) 

		cout 
			<< ' ' << *ms_iterator; 
	cout << '\n'; 

	ms_iterator = multi_set.begin(); 
	ms_iterator++; 
  	auto iter = multi_set.upper_bound(9);
  	if(iter != multi_set.end())
    {
    	int distance_val = distance(multi_set.begin(), iter);
      	cout << "distance measure: " << distance_val << "\n";
    }
  	auto new_iter = multi_set.upper_bound(9);
  	cout << "upper bound val: " << *new_iter << "\n";
  	auto new_iter_lower =  multi_set.lower_bound(9);
  	cout << "lower bound val: " << *new_iter_lower << "\n";

	// Passing the iterator for the position 
	// at which the value is to be erased 
	multi_set.erase(ms_iterator); 

	cout << "Modified multiset: "; 

	for (ms_iterator = multi_set.begin(); 
		ms_iterator != multi_set.end(); 
		++ms_iterator) 

		cout << ' ' << *ms_iterator; 
	cout << '\n'; 

	return 0; 
} 
