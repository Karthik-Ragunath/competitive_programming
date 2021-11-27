#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N;
        cin >> N;
        vector< ll > input(N);
        vector< ll > sum(N);
        vector< ll > actualValue(N);
        for(ll i = 0; i < N; i++)
        {
            cin >> input[i];
        }
        actualValue[0] = -1 * input[0];
        sum[0] = -1 * input[0];
        for(ll i = 1; i < N; i++)
        {
            if(actualValue[i - 1] < 0)
            {
                ll prevValueChecker = input[i] + actualValue[i - 1];
                if(prevValueChecker <= 0)
                {
                    actualValue[i - 1] = input[i - 1];
                    if((i - 1) != 0)
                    {
                        sum[i - 1] = sum[i - 2] + actualValue[i - 1];
                        // cout << "sum[" << (i - 1) << "]: " << sum[i - 1] << endl;
                    }
                    else
                    {
                        sum[i - 1] = input[i - 1];
                        // cout << "sum[0]: " << sum[i - 1] << endl;
                    }
                }
            }
            // cout << "actualValue[" << i - 1 << "]: " << actualValue[i - 1] << endl;
            if(actualValue[i - 1] < 0)
            {
                actualValue[i] = input[i];
                sum[i] = actualValue[i - 1] + actualValue[i];
            }
            else
            {
                ll tempValue = -1 * input[i];
                if((tempValue + actualValue[i - 1]) > 0 && (tempValue + sum[i - 1]) > 0)
                {
                    actualValue[i] = tempValue;
                    sum[i] = sum[i - 1] + actualValue[i];

                    // cout << "actualValue[" << i << "]: " << actualValue[i] << endl;
                    // cout << "sum[" << i << "]: " << sum[i] << endl;
                }
                else
                {
                    actualValue[i] = input[i];
                    sum[i] = sum[i - 1] + actualValue[i];
                }
            }
        }
        for(ll i = 0; i < N; i++)
        {
            cout << actualValue[i] << " ";
        }
        cout << endl;
    }
}
