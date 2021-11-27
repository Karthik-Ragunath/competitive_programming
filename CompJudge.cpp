#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int test;
    for(long long int m = 0; m < test; m++)
    {
        long long int n;
        cin >> n;
        long long int max1 = 0, sum1 = 0, max2 = 0, sum2 = 0;
        for(long long int i = 0; i < n; i++)
        {
            long long int number;
            cin >> number;
            if(number > max1)
            {
                max1 = number;
            }
            sum1 += number;
        }
        sum1 = sum1 - max1;
        for(long long int i = 0; i < n; i++)
        {
            long long int number;
            cin >> number;
            if(number > max2)
            {
                max2 = number;
            }
            sum2 += number;
        }
        sum2 = sum2 - max2;
        if(max1 < max2)
        {
            cout << "Alice" << endl;
        }
        else if(max2 < max1)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Draw" << endl;
        }
    }
    return 0;
}
