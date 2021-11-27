#include <bits/stdc++.h>
using namespace std;

class SortVector
{
	public:
		bool operator() (const pair< int, pair< int, int > > &node1, const pair< int, pair< int, int > > &node2)
		{
			if(node1.first > node2.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

int main()
{
    vector< pair<int, int> > vectorA;
    vectorA.push_back(make_pair(1,2));
    vectorA.push_back(make_pair(3,4));
    vectorA.push_back(make_pair(5,6));
    vector< pair<int,int> >::iterator iter = vectorA.begin();
    for(; iter != vectorA.end(); iter++)
    {
        iter -> first = iter -> first + 1;
        iter -> second = iter -> second + 1;
    }
    vector< pair<int,int> >::iterator itr = vectorA.begin();
    for(; itr != vectorA.end(); itr++)
    {
        cout << itr -> first << " " << itr -> second << endl;
    }

    cout << "--------Pair of pairs---------" << endl;
    vector< pair< int, pair< int, int > > >vectorB;
    vectorB.push_back(make_pair(1, make_pair(2, 3)));
    vectorB.push_back(make_pair(100, make_pair(101, 102)));
    vectorB.push_back(make_pair(200, make_pair(201, 202)));
    vectorB.push_back(make_pair(50, make_pair(51, 52)));
    vectorB.push_back(make_pair(150, make_pair(151, 152)));
    sort(vectorB.begin(), vectorB.end(), SortVector());
    vector< pair< int, pair< int, int > > >::iterator it = vectorB.begin();
    for(; it != vectorB.end(); it++)
    {
        cout << it -> first << " " << it -> second.first << " " << it -> second.second << endl;
    }
    return 0;
}
