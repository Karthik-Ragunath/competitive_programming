#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll inputCount;
    cin >> inputCount;
    vector< ll > inputs(inputCount);
    for(ll i = 0; i < inputCount; i++)
    {
        cin >> inputs[i];
    }
    vector< ll > greedy(inputCount);
    for(ll i = 0; i < inputCount; i++)
    {
        if(i != 0 && i != inputCount - 1)
        {
            if(inputs[i] <= inputs[i - 1] && inputs[i] <= inputs[i + 1])
            {
                greedy[i] = 1;
            }
        }
        else if(i == 0)
        {
            if(i + 1 < inputCount)
            {
                if(inputs[i] <= inputs[i + 1])
                {
                    greedy[i] = 1;
                }
            }
            else
            {
                greedy[i] = 1;
            }
        }
        else if(i == inputCount - 1)
        {
            if(i - 1 >= 0)
            {
                if(inputs[i - 1] >= inputs[i])
                {
                    greedy[i] = 1;
                }
            }
            else
            {
                greedy[i] = 1;
            }
        }
    }

    for(ll i = 0; i < inputCount; i++)
    {
        if(i != 0)
        {
            if(inputs[i] > inputs[i - 1])
            {
                greedy[i] = max(greedy[i - 1] + 1, greedy[i]);
            }
        }
    }

    for(ll i = inputCount - 1; i >= 0; i--)
    {
        if(i != inputCount - 1)
        {
            if(inputs[i] > inputs[i + 1])
            {
                greedy[i] = max(greedy[i + 1] + 1, greedy[i]);
            }
        }
    }

    ll sum = 0;
    for(ll i = 0; i < inputCount; i++)
    {
        sum += greedy[i];
    }
    cout << sum << endl;
    return 0;
}
