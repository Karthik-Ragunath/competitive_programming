#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll testcases;
	cin >> testcases;
	for(ll i = 0; i < testcases; i++)
	{
		string s1, s2 = "", s3 = "";
		cin >> s1;
		for(auto iter = s1.begin(); iter != s1.end(); iter++)
		{
			if(*iter == '4')
			{
				s2 += '3';
				s3 += '1';
			}
			else
			{
				s2 += *iter;
				s3 += '0';
			}
		}
		string s2_trimmed = s2.erase(0, s2.find_first_not_of('0'));
		string s3_trimmed = s3.erase(0, s3.find_first_not_of('0'));
		cout << "Case #" << (i + 1) << ": " << s2_trimmed << " " << s3_trimmed << endl;
	}
	return 0;
}