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
            // cout << "Swapped Max Index: " << i << endl;
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
            // cout << "Swapped Min Index: " << i << endl;
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
        vector< ll > minKElements;
        vector< ll > maxKElements;
        ll twiceK = (2 * K);
        ll playerASum = 0;
        ll playerBSum = 0;
        if(twiceK > N)
        {
            K = N / 2;
            twiceK = (K * 2);
        }
        // cout << "TwiceK: " << twiceK << endl;
        for(ll i = 0; i < N; i++)
        {
            ll value;
            cin >> value;
            // cout << "Value: " << value << endl;
            input.push_back(value);
            if(i < twiceK)
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
                // cout << "MaxK: " << maxKElements[0] << endl;
                orderInMaxKElements(maxKElements, size);
                // cout << "PO1" << " Size: " << size << endl;
                if(i >= twiceK)
                {
                    // cout << "Max:" << maxKElements[0] << endl;
                    maxKElements.pop_back();
                }
            }
            else
            {
                playerBSum += value;
                minKElements.push_back(value);
                // cout << "MinK: " << minKElements[0] << endl;
                orderInMinKElements(minKElements, size);
                // cout << "PO2" << " Size: " << size << endl;
                if(i >= twiceK)
                {
                    // cout << "Min:" << minKElements[0] << endl;
                    minKElements.pop_back();
                }
            }
        }
        ll minSum = 0;
        ll maxSum = 0;
        // for(ll i = 0; i < twiceK; i++)
        // {
        //     if(i % 2)
        //     {
        //         maxSum = maxSum + maxKElements[i / 2];
        //     }
        //     else
        //     {
        //         minSum = minSum + minKElements[i / 2];
        //     }
        // }
        for(ll i = 0; i < K; i++)
        {
            if(maxKElements[i] > minKElements[i])
            {
                maxSum = maxSum + maxKElements[i];
                minSum = minSum + minKElements[i];
            }
            else
            {
                break;
            }
        }
        // cout << "MaxSum: " << maxSum << endl;
        // cout << "MinSum: " << minSum << endl;
        playerASum = playerASum - maxSum + minSum;
        playerBSum = playerBSum - minSum + maxSum;
        // cout << "PlayerA: " << playerASum << " PlayerB: " << playerBSum << endl;
        if(playerBSum > playerASum)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
