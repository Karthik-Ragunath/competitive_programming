#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int testcases;
	cin >> testcases;
	for(ll i = 0; i < testcases; i++)
	{
		ll reply_count;
		cin >> reply_count;
		int greater = 0;
		int f = 0, af = 0;
		for(ll i = 0; i < reply_count; i++)
		{
			int type, g1, g2;
			cin >> type >> g1 >> g2;
			if(type == 1)
			{
				// cout << "mile1" << "\n";
				cout << "YES" << "\n";
				f = g1;
				af = g2;
				if(f > af)
				{
					greater = 1;
				}
				else if(af > f)
				{
					greater = 2;
				}
				else
				{
					greater = 0;
				}
			}
			else
			{
				if(g1 == g2)
				{
					// cout << "mile2" << "\n";
					cout << "YES" << "\n";
					greater = 0;
				}
				else if(greater == 1)
				{
					if(g1 >= f and g2 < f)
					{
						// cout << "mile3" << "\n";
						cout << "YES" << "\n";
						f = g1;
						af = g2;
						greater = 1;
					}
					else if(g2 >= f and g1 < f)
					{
						// cout << "mile4" << "\n";
						cout << "YES" << "\n";
						f = g2;
						af = g1;
						greater = 1;
					}
					else
					{
						// cout << "mile5" << "\n";
						cout << "NO" << "\n";
						greater = 0;
					}
				}
				else if(greater == 2)
				{
					if(g1 >= af and g2 < af)
					{
						// cout << "mile6" << "\n";
						cout << "YES" << "\n";
						af = g1;
						f = g2;
						greater = 2;
					}
					else if(g2 >= af and g1 < af)
					{
						// cout << "mile7" << "\n";
						cout << "YES" << "\n";
						af = g2;
						f = g1;
						greater = 2;
					}
					else
					{
						// cout << "mile8" << "\n";
						cout << "NO" << "\n";
						greater = 0;
					}
				}
				else
				{
					// cout << "mile9" << "\n";
					cout << "NO" << "\n";
					greater = 0;
				}
			}
		}
	}
	return 0;
}