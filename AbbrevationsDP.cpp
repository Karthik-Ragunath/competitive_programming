#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll m = 0; m < testcases; m++)
    {
        string stringA;
        string stringB;
        cin >> stringA;
        cin >> stringB;
        ll lengthOfStringA = stringA.size();
        ll lengthOfStringB = stringB.size();
        vector< vector< bool > > dp(lengthOfStringA + 1, vector< bool >(lengthOfStringB + 1));
        dp[0][0] = true;
        for(ll i = 0; i < lengthOfStringA; i++)
        {
            for(ll j = 0; j <= lengthOfStringB; j++)
            {
                if(dp[i][j])
                {
                    if(j < lengthOfStringB)
                    {
                        // cout << "i: " << i << " j: " << j << endl;
                        ll stringAAscii = (ll)(stringA[i]);
                        char actualChar = stringA[i];
                        if(stringAAscii >= 97)
                        {
                            ll newAscii = stringAAscii - 32;
                            actualChar = (char)(newAscii);
                        }
                        if(actualChar == stringB[j])
                        {
                            dp[i + 1][j + 1] = true;
                        }
                    }
                    ll stringAAscii = (ll)(stringA[i]);
                    if(stringAAscii >= 97)
                    {
                        dp[i + 1][j] = true;
                    }
                }
            }
        }
        if(dp[lengthOfStringA][lengthOfStringB])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
