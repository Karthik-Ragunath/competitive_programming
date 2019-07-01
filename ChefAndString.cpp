#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector< vector< pair< ll, ll > > > > hasher(20, vector< vector< pair< ll, ll > > >(26));
vector< vector< ll > > sizeNow(20, vector< ll >(26));

ll binarySearch(ll left, ll right, ll position, char character)
{
    ll charAtPos = (ll)(character - 'a');
    vector< pair< ll, ll > > vect = hasher[position - 1][charAtPos];
    if(sizeNow[position - 1][charAtPos] == 0)
    {
        return 0;
    }
    ll lHigh = sizeNow[position - 1][charAtPos] - 1;
    ll lLow = 0;
    ll rHigh = sizeNow[position - 1][charAtPos] - 1;
    ll rLow = 0;
    ll lMid, rMid;
    bool lowValueFound = false;
    bool highValueFound = false;
    while(lLow < lHigh)
    {
        //cout << "lLow: " << lLow << " lHigh: " << lHigh << " lMid: " << lMid;
        lMid = (lLow + lHigh) / 2;
        ll stringNo = vect[lMid].first;
        //cout << " String No. " << stringNo << endl;
        if(left == stringNo)
        {
            lLow = lMid;
            lowValueFound = true;
            break;
        }
        if(left < stringNo)
        {
            lHigh = lMid;
            continue;
        }
        if(left > stringNo)
        {
            lLow = lMid + 1;
            continue;
        }
    }
    if(!lowValueFound)
    {
        ll stringNo = vect[lLow].first;
        if(stringNo < left)
        {
        	return 0;
        }
    }
    while(rLow < rHigh)
    {
        //cout << "rLow: " << rLow << " rHigh: " << rHigh << " rMid: " << rMid;
        rMid = (rLow + rHigh) / 2;
        ll stringNo = vect[rMid].first;
        //cout << " String No. " << stringNo << endl;
        if(right == stringNo)
        {
            rHigh = rMid;
            highValueFound = true;
            break;
        }
        if(right < stringNo)
        {
            rHigh = rMid - 1;
            continue;
        }
        if(right > stringNo)
        {
            rLow = rMid + 1;
            continue;
        }
    }
    if(!highValueFound)
    {
        ll stringNo = vect[rHigh].first;
        if(stringNo > right)
        {
        	return 0;
        }
    }
    ll lowerLimitValue = vect[lLow].second;
    ll upperLimitValue = vect[rHigh].second;
    ll solution = upperLimitValue - lowerLimitValue + 1;
    return solution;
}


int main()
{
    ll stringCount;
    cin >> stringCount;
    for(ll n = 0; n < stringCount; n++)
    {
        string stringInput;
        cin >> stringInput;
        string::iterator strIter = stringInput.begin();
        ll stringPos = 0;
        for(; strIter != stringInput.end(); strIter++, stringPos++)
        {
            ll charAtPos = (ll)(*strIter - 'a');
            hasher[stringPos][charAtPos].push_back(make_pair(n + 1, sizeNow[stringPos][charAtPos]++));
        }
    }
    ll queryCount;
    cin >> queryCount;
    for(ll n = 0; n < queryCount; n++)
    {
        ll left, right, position;
        char character;
        cin >> left >> right >> position >> character;
        ll solution = binarySearch(left, right, position, character);
        cout << solution << endl;
    }
    return 0;
}
