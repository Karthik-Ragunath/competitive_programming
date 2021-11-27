#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll numberOfStrings;
    cin >> numberOfStrings;
    for(ll i = 0; i < numberOfStrings; i++)
    {
        string input;
        cin >> input;
        unordered_map< string, ll > stringMap;
        ll lengthOfString = input.size();
        for(ll i = 0; i < lengthOfString; i++)
        {
            for(ll j = i + 1, k = 1; j <= lengthOfString; j++, k++)
            {
                string temp = input.substr(i, k);
                sort(temp.begin(), temp.end());
                unordered_map< string, ll >::iterator findIter = stringMap.find(temp);
                if(findIter != stringMap.end())
                {
                    findIter -> second += 1;
                }
                else
                {
                    stringMap.insert(make_pair(temp, 1));
                }
            }
        }
        unordered_map< string, ll >::iterator iter = stringMap.begin();
        ll solution = 0;
        for(; iter != stringMap.end(); iter++)
        {
            ll value = iter -> second;
            solution += ((value * (value - 1)) / 2);
        }
        cout << solution << endl;
    }
    return 0;
}
