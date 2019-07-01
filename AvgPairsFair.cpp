#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        ll numberOfTerms;
        cin >> numberOfTerms;
        vector< ll > values;
        vector< ll > frequency(2001);
        for(ll j = 0; j < numberOfTerms; j++)
        {
            ll value;
            cin >> value;
            values.push_back(value);
            frequency[value + 1000]++;
        }
        ll solution = 0;
        for(ll j = 0; j < 2000; j++)
        {
            for(ll k = 0; k < 2000; k++)
            {
                ll sumPair = j + k;
                if(sumPair % 2 == 0)
                {
                    ll sumPairAvg = sumPair / 2;
                    if(frequency[sumPairAvg] != 0 && frequency[j] != 0 && frequency[k] != 0)
                    {
                        if(j != k)
                        {
                            solution += (frequency[j] * frequency[k]);
                        }
                        else
                        {
                            solution += ((frequency[j] - 1) * frequency[j]);
                        }
                    }
                }
            }
        }
        solution = solution / 2;
        cout << solution << endl;
    }
    return 0;
}
