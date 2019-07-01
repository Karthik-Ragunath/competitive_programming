#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N;
        cin >> N;
        vector< ll > terms;
        bool solutionCanStillExceed = true;
        for(ll i = 0; i < N; i++)
        {
            ll value;
            cin >> value;
            terms.push_back(value);
        }
        sort(terms.begin(), terms.end());
        stack< ll > gcdStack;
        gcdStack.push(terms[0]);
        for(ll i = 1; i < N; i++)
        {
            if(solutionCanStillExceed)
            {
                if(!gcdStack.empty())
                {
                    ll top = gcdStack.top();
                    if(terms[i] % top != 0)
                    {
                        solutionCanStillExceed = false;
                    }
                    else
                    {
                        gcdStack.push(terms[i]);
                    }
                }
                if(!solutionCanStillExceed)
                {
                    while(!gcdStack.empty() && (terms[i] % gcdStack.top() != 0))
                    {
                        gcdStack.pop();
                    }
                }
            }
            else
            {
                while(!gcdStack.empty() && (terms[i] % gcdStack.top() != 0))
                {
                    gcdStack.pop();
                }
            }
        }
        ll gcdStackSize = gcdStack.size();
        if(gcdStackSize == N)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << gcdStack.size() << endl;
        }
    }
    return 0;
}
