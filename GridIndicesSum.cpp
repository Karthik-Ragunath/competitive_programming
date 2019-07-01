#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    long long int maxSize = 1000000;
    long long int dp[maxSize + 1] = {0};
    for(long long int i = 1; i <= maxSize; i++)
    {
        for(long long int j = 1; j <= i; j++)
        {
            if(i == j)
            {
                dp[i] += (i * 2);
            }
            else
            {
                dp[i] += ((i + j) * 2);
            }
        }
        dp[i] += dp[i - 1];
    }
    long long int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++)
    {
        long long int value;
        cin >> value;
        cout << dp[value] << endl;
    }
    return 0;
}
