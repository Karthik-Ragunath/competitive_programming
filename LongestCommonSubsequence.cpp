#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll length1 = s1.length();
    ll length2 = s2.length();
    vector< vector< ll > > matrixArray(length1 + 1, vector< ll >(length2 + 1));
    for(ll i = length1 - 1; i >= 0; i--)
    {
        for(ll j = length2 - 1; j >= 0; j--)
        {
            if(s1[i] == s2[j])
            {
                matrixArray[i][j] = matrixArray[i + 1][j + 1] + 1;
            }
            else
            {
                matrixArray[i][j] = max(matrixArray[i][j + 1], max(matrixArray[i + 1][j + 1], matrixArray[i + 1][j]));
            }
        }
    }
    cout << matrixArray[0][0] << endl;
    return 0;
}
