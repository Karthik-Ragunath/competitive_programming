#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n, queries;
    cin >> n;
    cin >> queries;
    int xorValues[queries + 1];
    long long int xorDp[queries + 1];
    xorDp[0] = 0;
    xorValues[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        xorValues[i] = value;
        xorDp[i] = xorValues[i] ^ xorDp[i - 1];
    }
    for(int i = 1; i <= queries; i++)
    {
        int queryType;
        cin >> queryType;
        if(queryType == 1)
        {
            int index;
            int indexValue;
            cin >> index;
            cin >> indexValue;
            xorValues[index] = indexValue;
            for(int j = index; j <= n; j++)
            {
                xorDp[j] = xorValues[j] ^ xorDp[j - 1];
            }
        }
        else
        {
            int maxIndex;
            long long int subArrayValueToBeFound;
            cin >> maxIndex;
            cin >> subArrayValueToBeFound;
            int count = 0;
            for(int j = maxIndex; j >= 1; j--)
            {
                long long int valueChecker = xorDp[j] ^ xorDp[0];
                if(valueChecker == subArrayValueToBeFound)
                {
                    count += 1;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}
