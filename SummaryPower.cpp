#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        ll N, K;
        cin >> N >> K;
        string inputString;
        cin >> inputString;
        ll minValue = min(K, N - K);
        ll solution = 0;
        for(ll i = 1; i < N; i++)
        {
            if(inputString[i] != inputString[i - 1])
            {
                if(i < N - K)
                {
                    if(i < minValue)
                    {
                        solution += i;
                    }
                    else
                    {
                        solution += minValue;
                    }
                }
                else
                {
                    ll temp = N - i;
                    if(temp < minValue)
                    {
                        solution += temp;
                    }
                    else
                    {
                        solution += minValue;
                    }
                }
            }
        }
        cout << solution << endl;
    }
    return 0;
}
