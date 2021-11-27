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
    long long int indexValues[maxSize + 1];
    for(long long int i = 1; i <= maxSize; i++)
    {
        string temp = to_string(i);
        int tempLength = temp.length();
        int evenValues = 0;
        int oddValues = 0;
        for(int j = 0; j < tempLength; j++)
        {
            if(j % 2 == 0)
            {
                evenValues = evenValues + (int)(temp[j] - '0');
            }
            else
            {
                oddValues = oddValues + (int)(temp[j] - '0');
            }
        }
        indexValues[i] = abs(evenValues - oddValues);
        for(long long int j = 1; j <= i; j++)
        {
            if(indexValues[i] == indexValues[j])
            {
                dp[i] += (indexValues[i] * 2);
            }
            else
            {
                dp[i] += ((indexValues[i] + indexValues[j]) * 2);
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
