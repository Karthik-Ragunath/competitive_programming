#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//Strictly Increasing

int main()
{
    ll n;
    cin >> n;
    vector< ll > inputs(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    vector< ll > longestSubsequence(n);
    longestSubsequence[0] = inputs[0];
    ll longestSubsequeceIndex = 1;
    for(ll i = 1; i < n; i++)
    {
        // >= if equal elements are considered Increasing
        if(inputs[i] > longestSubsequence[longestSubsequeceIndex - 1])
        {
            longestSubsequence[longestSubsequeceIndex] = inputs[i];
            longestSubsequeceIndex++;
        }
        else
        {
            //upper_bound if equal elements are considered Increasing
            ll index = lower_bound(longestSubsequence.begin(), longestSubsequence.begin() + longestSubsequeceIndex, inputs[i]) - longestSubsequence.begin();
            // cout << "Index: " << index << endl;
            longestSubsequence[index] = inputs[i];
        }
    }
    cout << longestSubsequeceIndex << endl;
    return 0;
}
