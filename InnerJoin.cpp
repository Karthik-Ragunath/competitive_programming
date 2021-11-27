#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll inputCountA, inputCountB;
    cin >> inputCountA >> inputCountB;
    unordered_set< ll > setA;
    unordered_set< ll > setB;
    for(ll i = 0; i < inputCountA; i++)
    {
        ll input;
        cin >> input;
        setA.insert(input);
    }
    vector< ll > solution;
    for(ll i = 0; i < inputCountB; i++)
    {
        ll input;
        cin >> input;
        unordered_set< ll >::iterator iter = setA.find(input);
        if(iter != setA.end())
        {
            solution.push_back(*iter);
        }
    }
    cout << "----Solution Inner Join---" << endl;
    vector< ll >::iterator iter = solution.begin();
    for(; iter != solution.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}
