#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector< vector< vector< ll > > > permutes(3);
void permute()
{
    for(ll i = 1; i <= 3; i++)
    {
        vector< ll > v;
        vector< vector< ll > > pushV;
        for(ll j = 0; j < i; j++)
        {
            v.push_back(j + 1);
        }
        ll counter = 0;
        do
        {
            pushV.push_back(v);
            counter++;
        }while(next_permutation(v.begin(), v.end()));
        permutes[i - 1] = (pushV);
    }
}

int main()
{
    permute();
    cout << permutes[2][0][0];
    cout << permutes[2][0][1];
    cout << permutes[2][0][2];

        cout << permutes[2][1][0];
    cout << permutes[2][1][1];
    cout << permutes[2][1][2];
    return 0;
}
