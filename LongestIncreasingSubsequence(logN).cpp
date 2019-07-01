#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, difference;
    cin >> n >> difference;
    vector< ll > inputs(n);
    vector< vector< ll > > maxSequence(2, vector< ll >(n, -1));
    vector< vector< ll > > maxSequenceIndex(2, vector< ll >(n, -1));
    ll currentMaxLength = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> inputs[i];
        if(currentMaxLength == 0)
        {
            maxSequence[0][i] = inputs[i];
            maxSequenceIndex[0][i] = 0;
            currentMaxLength++;
        }
        else
        {
            // cout << inputs[i] << " " << maxSequence[0][currentMaxLength - 1] << " " << "Index : " << i << " Max Index: " << maxSequenceIndex[0][currentMaxLength - 1] << endl;
            if((inputs[i] >= maxSequence[0][currentMaxLength - 1]) && (maxSequenceIndex[0][currentMaxLength - 1] != -1) && ((i - maxSequenceIndex[0][currentMaxLength - 1]) >= difference))
            {
                // cout << "Index 1: " << i << endl;
                maxSequence[0][currentMaxLength] = inputs[i];
                maxSequenceIndex[0][currentMaxLength] = i;
                currentMaxLength++;
            }
            else if((maxSequenceIndex[1][currentMaxLength - 1] != -1) && (inputs[i] >= maxSequence[1][currentMaxLength - 1]) && ((i - maxSequenceIndex[1][currentMaxLength - 1]) >= difference))
            {
                // cout << "Index 2: " << i << endl;
                maxSequence[0][currentMaxLength] = inputs[i];
                maxSequenceIndex[0][currentMaxLength] = i;
                currentMaxLength++;
            }
            else
            {
                ll upperBoundMaxSequenceRow0 = upper_bound(maxSequence[0].begin(), (maxSequence[0].begin() + (currentMaxLength - 1)), inputs[i]) - maxSequence[0].begin();
                if(upperBoundMaxSequenceRow0 == currentMaxLength - 1)
                {
                    if(maxSequenceIndex[1][currentMaxLength - 1] != -1 && maxSequence[1][currentMaxLength - 1] <= inputs[i])
                    {
                        continue;
                    }
                    maxSequence[1][currentMaxLength - 1] = inputs[i];
                    maxSequenceIndex[1][currentMaxLength - 1] = i;
                }
                else
                {
                    maxSequence[0][upperBoundMaxSequenceRow0] = inputs[i];
                    maxSequenceIndex[0][upperBoundMaxSequenceRow0] = i;
                }
            }
        }
    }
    cout << currentMaxLength << endl;
    return 0;
}
