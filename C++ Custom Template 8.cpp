#include <bits/stdc++.h>
using namespace std;

class CompareSet
{
	public:
		bool operator() (const pair<int, int> &pair1, const pair<int, int> &pair2)
		{
			if(pair1.first > pair2.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

int main() {
	set< pair<int,int>, CompareSet > setA;
	setA.insert(make_pair(3,4));
	setA.insert(make_pair(4,5));
	setA.insert(make_pair(6,7));
	setA.insert(make_pair(1,3));
	set< pair<int, int>, CompareSet >::iterator itr = setA.begin();
	for(;itr != setA.end(); itr++)
	{
		cout << "First: " << itr -> first << " Second: " << itr -> second << endl;
	}
	// your code goes here
	return 0;
}
