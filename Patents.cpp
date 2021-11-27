#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long int testcases;
    cin >> testcases;
    for(long long int m = 0; m < testcases; m++)
    {
        long long int N, M, X, K;
        string s;
        cin >> N >> M >> X >> K;
        cin >> s;
        long long int odd = 0, even = 0;
        for(long long int i = 0; i < K; i++)
        {
            if(s[i] == 'E')
            {
                even++;
            }
            else
            {
                odd++;
            }
        }

        long long int evenDays, oddDays;
        long long int evenWorkForce, oddWorkForce;
        evenDays = M / 2;
        oddDays = M / 2 + M % 2;

        if(even <= X)
        {
            evenWorkForce = even;
        }
        else
        {
            evenWorkForce = X;
        }

        if(odd <= X)
        {
            oddWorkForce = odd;
        }
        else
        {
            oddWorkForce = X;
        }

        long long int evenWorkDone = evenDays * evenWorkForce;
        long long int oddWorkDone = oddDays * oddWorkForce;
        long long int totalWorkDone = oddWorkDone + evenWorkDone;
        if(totalWorkDone >= N)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
