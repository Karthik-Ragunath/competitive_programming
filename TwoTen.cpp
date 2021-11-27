#include <bits/stdc++.h>
using namespace std;
# define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll input;
        cin >> input;
        if(input % 10 == 0)
        {
            cout << "0" << endl;
        }
        else if(input % 5 == 0)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}
