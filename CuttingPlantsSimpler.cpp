#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll N;
    cin >> N;
    vector< ll > dequeDS;
    ll solution = 0;
    for(ll i = 0; i < N; i++)
    {
        ll value;
        cin >> value;
        while(!dequeDS.empty() && dequeDS.back() > value)
        {
            dequeDS.pop_back();
        }
        if(!dequeDS.empty())
        {
            ll valueBack = dequeDS.back();
            if(value != valueBack)
            {
                dequeDS.push_back(value);
                solution++;
            }
        }
        else
        {
            dequeDS.push_back(value);
            solution++;
        }
    }
    cout << solution << endl;
    return 0;
}
