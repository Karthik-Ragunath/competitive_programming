#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "great" << "\n";
	string s1 = "great";
	string s2 = "now";
	// for(string::iterator iter_1 = s1.begin(), iter_2 = s2.begin(); iter_1 != s1.end() and iter_2 != s2.end(); iter_1++, iter_2++)
	// {
	// 	cout << "ch_1: " << *iter_1 << " " << "ch_2: " << *iter_2 << "\n"; 
	// }
	// for(auto iter_1 = s1.begin(), iter_2 = s2.begin(); iter_1 != s1.end() and iter_2 != s2.end(); iter_1++, iter_2++)
	// {
	// 	cout << "ch_1: " << *iter_1 << " " << "ch_2: " << *iter_2 << "\n"; 
	// }
	vector< string > words{"karthik", "ragunath", "is", "a", "good", "guy"};
	for(auto iter_1 = words.begin(); iter_1 != words.end(); iter_1++)
	{
		// if(iter_1 + 1 == words.end())
		// {
		// 	break;
		// }
		// auto iter_2 = next(iter_1);
		// cout << *iter_1 << "\n";
		// for(auto ch1 = (*iter_1).begin(); ch1 != (*iter_1).end(); ch1++)
		// {
		// 	cout << *ch1 << "\n";
		// }
		// for(auto ch_1 = (*iter_1).begin(), ch_2 = (*iter_2).begin(); ch_1 != (*iter_1).end() and ch_2 != (*iter_2).end(); ch_1++, ch_2++)
		// {
		// 	cout << "ch_1: " << *ch_1 << " " << "ch_2: " << *ch_2 << "\n";
		// }
		for(auto ch_1 = (*iter_1).begin(); ch_1 != (*iter_1).end(); ch_1++)
		{
			if(ch_1 + 1 == (*iter_1).end())
			{
				break;
			}
			auto ch_2 = ch_1 + 1;
			cout << "ch_1: " << *ch_1 << " " << "ch_2: " << *ch_2 << "\n";
		}
		cout << "-------------" << "\n";
	}
	// your code goes here
	return 0;
}