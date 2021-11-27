#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


long long int diamondsCount(long long int value)
{
    long long int oddSum = 0;
    long long int evenSum = 0;
    while(value / 10 > 0)
    {
        int temp = value % 10;
        if(temp % 2 == 0)
        {
            evenSum += temp;
        }
        else
        {
            oddSum += temp;
        }
        value /= 10;
    }
    if(value % 2 == 0)
    {
        evenSum += value;
    }
    else
    {
        oddSum += value;
    }
    return abs(evenSum - oddSum);
}

int main()
{
    int testcases;
    long long int dp[2000001];
    long long int sum[2000001];
    long long int ans[1000001];
    for(int i = 0; i < 2000001; i++)
    {
        dp[i] = diamondsCount(i);
        cout << dp[i] << endl;
    }
    sum[0] = 0;
    for(int i = 1; i < 2000001; i++)
    {
        sum[i] = sum[i - 1] + dp[i];
    }
    ans[1] = 2;
    for(int i = 2; i < 1000001; i++)
    {
        ans[i] = ans[i - 1] + 2 * (sum[2 * i - 1] - sum[i]) + dp[2 * i];
    }
    cin >> testcases;
    for(int i = 0; i < testcases; i++)
    {
        int numberOfRooms;
        cin >> numberOfRooms;
        cout << ans[numberOfRooms] << endl;
    }
    return 0;
}
