#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> input;
vector<bool> primes(100001, true);
vector<ll> segmentTree((4 * 100000 + 1), 0);

void generatePrimes()
{
    primes[0] = false;
    primes[1] = false;
    for(ll i = 4; i <= 100000; i += 2)
    {
        primes[i] = false;
    }
    ll sqrtValue = sqrt(100000);
    for(ll i = 3; i <= sqrtValue; i += 2)
    {
        if(primes[i])
        {
            for(ll j = i * i; j <= 100000; j += (i * 2))
            {
                primes[j] = false;
            }
        }
    }
}

ll buildSegmentTree(ll left, ll right, ll position)
{
    if(left == right)
    {
        if(primes[input[left]])
        {
            segmentTree[position] = 1;
            return segmentTree[position];
        }
        else
        {
            segmentTree[position] = 0;
            return segmentTree[position];
        }
    }
    ll mid = (left + right) / 2;
    ll leftValue = buildSegmentTree(left, mid, 2 * position + 1);
    ll rightValue = buildSegmentTree(mid + 1, right, 2 * position + 2);
    segmentTree[position] = leftValue + rightValue;
    return segmentTree[position];
}


ll countOfPrimes(ll low, ll high, ll left, ll right, ll position)
{
    if(low <= left && high >= right)
    {
        return segmentTree[position];
    }
    if(left > high || right < low)
    {
        return 0;
    }
    ll mid = (left + right) / 2;
    ll leftValue = countOfPrimes(low, high, left, mid, 2 * position + 1);
    ll rightValue = countOfPrimes(low, high, mid + 1, right, 2 * position + 2);
    return leftValue + rightValue;
}

ll update(ll left, ll right, ll position, ll index)
{
    if(right < index || left > index)
    {
        return segmentTree[position];
    }
    if(left == right)
    {
        if(primes[input[left]])
        {
            segmentTree[position] = 1;
            return 1;
        }
        else
        {
            segmentTree[position] = 0;
            return 0;
        }
    }
    ll mid = (left + right) / 2;
    ll leftValue = update(left, mid, (2 * position + 1), index);
    ll rightValue = update(mid + 1, right, (2 * position + 2), index);
    segmentTree[position] = leftValue + rightValue;
    return segmentTree[position];
}

int main()
{

    ll terms, queries;
    cin >> terms >> queries;
    for(ll i = 0; i < terms; i++)
    {
        ll temp;
        cin >> temp;
        input.push_back(temp);
    }

    generatePrimes();

    /*
    for(ll i = 2; i <= 30; i++)
    {
        if(primes[i])
        {
            cout << i << " is a prime" << endl;
        }
    }
    */
    ll left = 0, right = terms - 1, position = 0;
    ll totalCount = buildSegmentTree(left, right, position);
    // cout << totalCount << endl;
    // ll primesInGivenRange = countOfPrimes(1, 4, left, right, position);
    // cout << primesInGivenRange << endl;

    for(ll i = 0; i < queries; i++)
    {
        ll typeOfQuery;
        cin >> typeOfQuery;
        if(typeOfQuery == 1)
        {
            ll low, high;
            cin >> low >> high;
            ll primesInGivenRange = countOfPrimes(low - 1, high - 1, left, right, position);
            cout << primesInGivenRange << endl;
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            input[x - 1] = y;
            update(left, right, position, (x - 1));
        }
    }
    return 0;
}
