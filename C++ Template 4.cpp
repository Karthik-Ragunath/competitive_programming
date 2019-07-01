#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	set<int> setA;
	setA.insert(2);
	setA.insert(78);
	setA.insert(1);
	setA.insert(76);
	set<int>::iterator itr = setA.begin();
	cout << *itr << endl;
	cout << "Size: " << setA.size() << endl;
	setA.erase(1);
	set<int>::iterator itr1 = setA.begin();
	cout << *itr1 << endl;
	cout << "Size: " << setA.size() << endl;
	vector< vector<int> > twoDArray(5, vector<int>(4, -1));
	cout << "Row Count: " << twoDArray.size() << endl;
	cout << "Column Size: " << twoDArray[0].size() << endl;
	// your code goes here
	return 0;
}
