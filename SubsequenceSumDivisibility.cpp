#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        ll N, divisor;
        cin >> N >> divisor;
        vector< ll > input(N);
        for(ll i = 0; i < N; i++)
        {
            cin >> input[i];
        }
        vector< vector< ll > > dp(N, vector< ll >(divisor));
        dp[0][0] += 1;
        dp[0][input[0] % divisor] += 1;
        for(ll i = 1; i < N; i++)
        {
            for(ll k = 0; k < divisor; k++)
            {
                dp[i][k] = dp[i - 1][k];
            }
            for(ll k = 0; k < divisor; k++)
            {
                dp[i][(input[i] + k) % divisor] += dp[i - 1][k];
            }
        }
        ll solution = dp[N - 1][0] - 1;
        cout << solution << endl;
    }
    return 0;
}
