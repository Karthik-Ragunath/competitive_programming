#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        string a, b;
        cin >> a >> b;
        string::iterator stringAIter = a.begin();
        string::iterator stringBIter = b.begin();
        for(; stringAIter != a.end() && stringBIter != b.end(); stringAIter++)
        {
            char actualCharA = *stringAIter;
            ll asciiValueA = (ll)(*stringAIter);
            if(asciiValueA >= 97)
            {
                ll actualAscii = 65 + (asciiValueA - 97);
                actualCharA = (char)(actualAscii);
            }
            // cout << "Actual Char A: " << actualCharA << " Char B: " << *stringBIter << endl;
            if(actualCharA == *stringBIter)
            {
                stringBIter++;
            }
        }
        if(stringBIter != b.end())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
