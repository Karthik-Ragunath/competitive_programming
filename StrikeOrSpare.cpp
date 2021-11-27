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
        if(input % 2 == 0)
        {
            ll powerOfNumerator = input / 2;
            string numeratorString = "";
            for(ll i = 0; i < powerOfNumerator; i++)
            {
                numeratorString += "1";
            }
            cout << numeratorString << " " << "1" << endl;
        }
        else
        {
            ll powerOfNumerator = input / 2 + 1;
            string numeratorString = "";
            for(ll i = 0; i < powerOfNumerator; i++)
            {
                numeratorString += "1";
            }
            cout << numeratorString << " " << "1" << endl;
        }
    }
    return 0;
}
