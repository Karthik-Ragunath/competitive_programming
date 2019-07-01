// https://www.codechef.com/APRIL18B/problems/CUTPLANT
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll testcases;
	cin >> testcases;
	for(ll i = 0; i < testcases; i++)
	{
		ll count;
		cin >> count;
		vector< ll > actual(count);
		vector< ll > desired(count);
		for(ll i = 0; i < count; i++)
		{
			cin >> actual[i];
		}
		for(ll i = 0; i < count; i++)
		{
			cin >> desired[i];
		}
		deque< ll > cutter;
		ll solution = 0;
		for(ll i = 0; i < count; i++)
		{
			if(desired[i] > actual[i])
			{
				solution = -1;
				break;
			}
			while(!cutter.empty() && actual[i] < cutter.front()) //when value in center's actual height < prev vals desired (question specific condition)
			{
				cutter.pop_front();
			}
			while(!cutter.empty() && desired[i] > cutter.back())
			{
				cutter.pop_back();
			}
			if(actual[i] != desired[i])
			{
				if(cutter.empty() || desired[i] != cutter.back())
				{
					cutter.push_back(desired[i]); //Should be here
					solution++;
				}
			}
			// cutter.push_back(desired[i]); 
			/*
			Wont work for 
			5 6 7
			5 6 6 - Assumes that 6 already exists, therefore, desired[i] == cutter.back()
			*/
		}
		cout << solution << endl;
	}
	return 0;
}