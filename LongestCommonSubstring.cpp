#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll length1 = s1.length();
    ll length2 = s2.length();
    ll maximum = 0;
    vector< vector< ll > > matrixArray(length1 + 1, vector< ll >(length2 + 1));
    for(ll i = length1 - 1; i >= 0; i--)
    {
        for(ll j = length2 - 1; j >= 0; j--)
        {
            if(s1[i] == s2[j])
            {
                matrixArray[i][j] = matrixArray[i + 1][j + 1] + 1;
                if(matrixArray[i][j] > maximum)
                {
                    maximum = matrixArray[i][j];
                }
            }
            else
            {
                matrixArray[i][j] = 0;
            }
        }
    }
    cout << maximum << endl;
    return 0;
}
