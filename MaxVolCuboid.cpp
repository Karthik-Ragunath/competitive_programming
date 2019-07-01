#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll testVal(ll A, ll B)
{
    ll maxAns = 0;
    ll maxIndex = 0;
    if(A < B)
    {
        for(ll i = A - 1, j = 1; i > 0; i--, j++)
        {
            ll temp = i * (B - j) * j;
            if(temp > maxAns)
            {
                maxIndex = j;
                maxAns = temp;
            }
        }
    }
    else
    {
        for(ll i = B - 1, j = 1; i > 0; i--, j++)
        {
            ll temp = (A - j) * i * j;
            if(temp > maxAns)
            {
                maxIndex = j;
                maxAns = temp;
            }
        }
    }
    cout << "TestIndex: " << maxIndex << endl;
    return maxAns;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        double A, B;
        cin >> A >> B;
        double value1 = ((2 * (A + B)) + sqrt((4 * (A + B) * (A + B)) - (4 * 3 * A * B))) / 6;
        // cout << value1 << endl;
        double value2 = ((2 * (A + B)) - sqrt((4 * (A + B) * (A + B)) - (4 * 3 * A * B))) / 6;
        // cout << value2 << endl;
        ll ceilVal1 = ceil(value1);
        ll ceilVal2 = ceil(value2);
        ll floorVal1 = floor(value1);
        ll floorVal2 = floor(value2);
        // cout << ceilVal1 << " " << ceilVal2 << " " << floorVal1 << " " << floorVal2 << endl;
        ll solution1 = (A - ceilVal1) * (B - ceilVal1) * ceilVal1;
        ll solution2 = (A - ceilVal2) * (B - ceilVal2) * ceilVal2;
        ll solution3 = (A - floorVal1) * (B - floorVal1) * floorVal1;
        ll solution4 = (A - floorVal2) * (B - floorVal2) * floorVal2;
        ll maxVal = 0;
        // cout << solution1 << " " << solution2 << " " << solution3 << " " << solution4 << endl;
        maxVal = max(solution1, max(solution2, max(solution3, solution4)));
        // cout << maxVal;
        if(maxVal == solution3)
        {
            cout << floorVal1 << " " << solution3 << endl;
        }
        else if(maxVal == solution4)
        {
            cout << floorVal2 << " " << solution4 << endl;
        }
        else if(maxVal == solution1)
        {
            cout << ceilVal1 << " " << solution1 << endl;
        }
        else if(maxVal == solution2)
        {
            cout << ceilVal2 << " " << solution2 << endl;
        }
        // ll testAns = testVal(A, B);
        // cout << "Test: " << testAns << endl;
    }
    return 0;
}
