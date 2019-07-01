#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void orderInMaxKElements(vector< ll> &maxKElements, ll size)
{
    for(ll i = size; i > 0; i--)
    {
        if(maxKElements[i] > maxKElements[i - 1])
        {
            ll temp = maxKElements[i];
            maxKElements[i] = maxKElements[i - 1];
            maxKElements[i - 1] = temp;
        }
        else
        {
            break;
        }
    }
}

void orderInMinKElements(vector< ll> &minKElements, ll size)
{
    for(ll i = size; i > 0; i--)
    {
        if(minKElements[i] < minKElements[i - 1])
        {
            ll temp = minKElements[i];
            minKElements[i] = minKElements[i - 1];
            minKElements[i - 1] = temp;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N, K;
        cin >> N >> K;
        vector< ll > input;
        vector< ll > minKElements(K + 1);
        vector< ll > maxKElements(K + 1);
        ll twiceK = (2 * K);
        for(ll i = 0; i < N && i < twiceK; i++)
        {
            ll value;
            cin >> value;
            input.push_back(value);
            ll size = i / 2;
            if(i % 2 == 0)
            {
                minKElements.push_back(value);
                orderInMinKElements(minKElements, size);
            }
            else
            {
                maxKElements.push_back(value);
                orderInMaxKElements(maxKElements, size);
            }
        }
        for(ll i = twiceK; i < N; i++)
        {
            ll value;
            cin >> value;
            input.push_back(value);
            if(i % 2 == 0)
            {
                minKElements.push_back(value);
                orderInMinKElements(minKElements, K);
                minKElements.erase(minKElements.end());
            }
            else
            {
                maxKElements.push_back(value);
                orderInMaxKElements(maxKElements, K);
                maxKElements.erase(maxKElements.end());
            }
        }
        ll size;
        for(ll i = 0; i < N; i++)
        {
            ll value;
            cin >> value;
            input.push_back(value);
            if(i < N && i < twiceK)
            {
                size = i / 2;
            }
            else
            {
                size = K;
            }
            if(i % 2 == 0)
            {
                minKElements.push_back(value);
                orderInMinKElements(minKElements, size);
                minKElements.erase(minKElements.end());
            }
            else
            {
                maxKElements.push_back(value);
                orderInMaxKElements(maxKElements, size);
                maxKElements.erase(maxKElements.end());
            }
        }
    }
    return 0;
}
