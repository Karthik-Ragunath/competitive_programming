#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        ll A, B;
        ll valA, valB;
        cin >> A >> B;
        ll tensOfA = A / 10;
        ll tensOfB = B / 10;

        ll digitA = (A % 10);
        if(digitA <= 2)
        {
            valA = 3;
        }
        else if(digitA <= 3)
        {
            valA = 2;
        }
        else if(digitA <= 9)
        {
            valA = 1;
        }

        ll digitB = (B % 10);
        if(digitB < 2)
        {
            valB = 0;
        }
        else if(digitB < 3)
        {
            valB = 1;
        }
        else if(digitB < 9)
        {
            valB = 2;
        }
        else
        {
            valB = 3;
        }


        tensOfA = tensOfA + 1;
        if(tensOfA == tensOfB)
        {
            ll solution = valA + valB;
            cout << solution << endl;
            continue;
        }
        if(tensOfB > tensOfA)
        {
            ll solution = (tensOfB - tensOfA) * 3 + valA + valB;
            cout << solution << endl;
            continue;
        }
        if(tensOfA > tensOfB)
        {
            if(digitA <= 2)
            {
                valA = 0;
            }
            else if(digitA <= 3)
            {
                valA = 1;
            }
            else if(digitA <= 9)
            {
                valA = 2;
            }
            else
            {
                valA = 3;
            }
            ll solution = valB - valA;
            cout << solution << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}
