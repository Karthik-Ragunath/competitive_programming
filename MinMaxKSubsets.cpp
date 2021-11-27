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
        ll N, K, size;
        cin >> N >> K;
        vector< ll > input;
        vector< ll > minKElements(K + 1);
        vector< ll > maxKElements(K + 1);
        ll twiceK = (2 * K);
        ll playerASum = 0;
        ll playerBSum = 0;
        if(twiceK > N)
        {
            K = N / 2;
            twiceK = (newK * 2);
        }
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
                playerASum += value;
                maxKElements.push_back(value);
                orderInMaxKElements(maxKElements, size);
                maxKElements.erase(maxKElements.end());
            }
            else
            {
                playerBSum += value;
                minKElements.push_back(value);
                orderInMinKElements(minKElements, size);
                minKElements.erase(minKElements.end());
            }
        }
        ll minSum = 0;
        ll maxSum = 0;
        for(ll i = 0; i < N && i < twiceK; i++)
        {
            if(i % 2)
            {
                maxSum = maxSum + maxKElements[i / 2];
            }
            else
            {
                minSum = minSum + minKElements[i / 2];
            }
        }

    }
    return 0;
}
