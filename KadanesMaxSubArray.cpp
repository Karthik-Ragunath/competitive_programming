// https://www.hackerrank.com/challenges/maxsubarray/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll l = 0; l < testcases; l++)
    {
        ll n;
        cin >> n;
        vector< ll > inputs(n + 1);
        for(ll i = 1; i <= n; i++)
        {
            cin >> inputs[i];
        }

        //Kadanes ALgorithm
        ll solution = -1000000;
        vector< ll > solutionVect(n + 1);

        for(ll i = 1; i <= n; i++)
        {
            solutionVect[i] = max((solutionVect[i - 1] + inputs[i]), inputs[i]);
            if(solutionVect[i] > solution)
            {
                solution = solutionVect[i];
            }
        }
        cout << solution << " ";

        //Maximum Subsequence
        ll maximumSubsequence = inputs[1];
        for(ll i = 2; i <= n; i++)
        {
            ll tempMaximumSubsequence = max((maximumSubsequence + inputs[i]), inputs[i]);
            maximumSubsequence = max(tempMaximumSubsequence, maximumSubsequence);
        }
        cout << maximumSubsequence << endl;
    }
    return 0;
}
