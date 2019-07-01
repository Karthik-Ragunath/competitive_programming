#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll l = 0; l < testcases; l++)
    {
        ll N;
        cin >> N;
        for(ll i = 1; i <= N; i++)
        {
            if(i % 3 == 0 && i % 5 == 0)
            {
                cout << "FizzBuzz" << endl;
            }
            else if(i % 3 == 0)
            {
                cout << "Fizz" << endl;
            }
            else if(i % 5 == 0)
            {
                cout << "Buzz" << endl;
            }
            else
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}
