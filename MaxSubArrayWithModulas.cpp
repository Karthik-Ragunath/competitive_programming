#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        ll n, modulas;
        cin >> n >> modulas;
        vector< ll > inputs(n);
        vector< ll > sum(n);
        for(ll i = 0; i < n; i++)
        {
            cin >> inputs[i];
        }
        sum[0] = inputs[0] % modulas;
        ll maximumSubArraySum = sum[0];
        set< ll > treeSet;
        treeSet.insert(sum[0]);
        for(ll i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + inputs[i];
            sum[i] = sum[i] % modulas;
            maximumSubArraySum = max(maximumSubArraySum, sum[i]);
            set< ll >::iterator itr = treeSet.lower_bound(sum[i]);
            if(itr != treeSet.end())
            {
                maximumSubArraySum = max((sum[i] - *itr + modulas) % modulas, maximumSubArraySum);
            }
            treeSet.insert(sum[i]);
        }
        cout << maximumSubArraySum << endl;
    }
    return 0;
}
