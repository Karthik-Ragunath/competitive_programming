#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll j = 0; j < testcases; j++)
    {
        ll input;
        cin >> input;
        ll powerOfNumerator = input / 2;
        string numeratorString = "1";
        for(ll i = 0; i < powerOfNumerator; i++)
        {
            numeratorString += "0";
        }
        cout << "1" << " " << numeratorString << endl;
    }
    return 0;
}
