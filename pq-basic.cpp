#include <bits/stdc++.h>
using namespace std;

class CompareNodes
{
	public:
		bool operator()(const int val1, const int val2)
		{
			if(val1 > val2)
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
	vector< int > a{8, 4, 6, 12};
	priority_queue< int, vector< int >, CompareNodes > pq;
	for(auto val: a)
	{
		pq.push(val);
	}
	int sum = 0;
	while(pq.size() >= 2)
	{
		int temp = pq.top() + pq.top();
		pq.pop();
		pq.pop();
		sum += temp;
		pq.push(temp);
	}
	cout << sum << "\n";
	return 0;
}