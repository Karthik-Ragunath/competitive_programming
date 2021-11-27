// https://www.hackerrank.com/challenges/max-array-sum/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll inputCount;
    cin >> inputCount;
    vector< ll > dp(inputCount);
    ll firstValue;
    cin >> firstValue;
    dp[0] = firstValue;
    for(ll i = 1; i < inputCount; i++)
    {
        ll input;
        cin >> input;
        if(i != 1)
        {
            dp[i] = max(input, max(dp[i - 2] + input, max(dp[i - 2], dp[i - 1])));
        }
        else
        {
            dp[i] = max(dp[i - 1], input);
        }
    }
    cout << dp[inputCount - 1] << endl;
    return 0;
}
