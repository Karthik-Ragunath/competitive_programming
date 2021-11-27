#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void displayArray(vector< vector< ll > > &displayArray, ll length)
{
    for(ll i = 0; i < 26; i++)
    {
        for(ll j = 0; j < length; j++)
        {
            cout << displayArray[i][j] << " ";
        }
        cout << endl;
    }
}

void printDetails(vector< vector< ll > > &indexCountTable, vector< vector< ll > > &rangeQueryTable, vector< vector< ll > > &contributionTableCumulative, vector< vector< ll > > &indexCountTableUpperCumulative, vector< vector< ll > > &indexCountTableDownwardCumulative, ll length)
{
    cout << "indexCountTable" << endl;
    displayArray(indexCountTable, length);
    cout << "Done" << endl << endl;
    cout << "rangeQueryTable" << endl;
    displayArray(rangeQueryTable, length);
    cout << "Done" << endl << endl;
    cout << "contributionTableCumulative" << endl;
    displayArray(contributionTableCumulative, length);
    cout << "Done" << endl << endl;
    cout << "indexCountTableUpperCumulative" << endl;
    displayArray(indexCountTableUpperCumulative, length);
    cout << "Done" << endl << endl;
    cout << "indexCountTableDownwardCumulative" << endl;
    displayArray(indexCountTableDownwardCumulative, length);
    cout << "Done" << endl << endl;
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        string input;
        cin >> input;
        ll length = input.size();
        vector< vector< ll > > indexCountTable(26, vector< ll >(length));
        for(ll i = 0; i < 26; i++)
        {
            for(ll j = 0; j < length; j++)
            {
                ll index = (ll)(input[j] - 'a');
                if(index == i)
                {
                    if(j == 0)
                    {
                        indexCountTable[i][j] = 1;
                    }
                    else
                    {
                        indexCountTable[i][j] = indexCountTable[i][j - 1] + 1;
                    }
                }
                else
                {
                    if(j == 0)
                    {
                        indexCountTable[i][j] = 0;
                    }
                    else
                    {
                        indexCountTable[i][j] = indexCountTable[i][j - 1];
                    }
                }
            }
        }
        vector< vector< ll > > rangeQueryTable(26, vector< ll >(length));
        for(ll i = 0; i < 26; i++)
        {
            for(ll j = 0; j < length; j++)
            {
                rangeQueryTable[i][j] = indexCountTable[i][length - 1] - indexCountTable[i][j];
            }
        }
        vector< vector< ll > > contributionTableCumulative(26, vector< ll >(length));
        for(ll j = 0; j < length; j++)
        {
            for(ll i = 0; i < 26; i++)
            {
                if(i != 0)
                {
                    contributionTableCumulative[i][j] = rangeQueryTable[i][j] + contributionTableCumulative[i - 1][j];
                }
                else
                {
                    contributionTableCumulative[i][j] = rangeQueryTable[i][j];
                }
            }
        }
        vector< vector< ll > > indexCountTableUpperCumulative(26, vector< ll >(length));
        for(ll j = 0; j < length; j++)
        {
            for(ll i = 25; i >= 0; i--)
            {
                if(i == 25)
                {
                    indexCountTableUpperCumulative[i][j] = indexCountTable[i][j];
                }
                else
                {
                    indexCountTableUpperCumulative[i][j] = indexCountTable[i][j] + indexCountTableUpperCumulative[i + 1][j];
                }
            }
        }
        vector< vector< ll > > indexCountTableDownwardCumulative(26, vector< ll >(length));
        for(ll j = 0; j < length; j++)
        {
            for(ll i = 0; i < 26; i++)
            {
                if(i == 0)
                {
                    indexCountTableDownwardCumulative[i][j] = indexCountTable[i][j];
                }
                else
                {
                    indexCountTableDownwardCumulative[i][j] = indexCountTable[i][j] + indexCountTableDownwardCumulative[i - 1][j];
                }
            }
        }
        // printDetails(indexCountTable, rangeQueryTable, contributionTableCumulative, indexCountTableUpperCumulative, indexCountTableDownwardCumulative, length);
        vector< ll > yCalc(length);
        vector< ll > alphabets(26);
        ll yTotal = 0;
        for(ll i = length - 1; i >= 0; i--)
        {
            ll currentIndex = (ll)(input[i] - 'a');
            alphabets[currentIndex]++;
            ll lengthValue = 0;
            for(ll j = currentIndex + 1; j < 26; j++)
            {
                lengthValue += alphabets[j];
            }
            yCalc[i] = lengthValue;
            yTotal += yCalc[i];
        }
        ll maximumSave = 0;
        for(ll j = 0; j < length; j++)
        {
            ll indexValue = (ll)(input[j] - 'a');
            for(ll i = indexValue - 1; i >= 0; i--)
            {
                ll contributionVal = contributionTableCumulative[25][j] - contributionTableCumulative[i][j];
                ll difference = indexValue - i;
                ll contributionReducedInLeftSide = indexCountTableUpperCumulative[i][j] - indexCountTableUpperCumulative[indexValue][j];
                ll overall = contributionVal + difference - contributionReducedInLeftSide;
                ll save = yCalc[j] - overall;
                if(save > maximumSave)
                {
                    maximumSave = save;
                    cout << "Cont Val: " << contributionVal << " ";
                    cout << "Maximum Save Index: " << i << " " << j << " IndexValue: " << indexValue << endl;
                }
            }
            for(ll i = indexValue + 1; i < 26; i++)
            {
                ll contributionVal = contributionTableCumulative[25][j] - contributionTableCumulative[i][j];
                ll difference = i - indexValue;
                ll contributionIncreasedInLeftSide = indexCountTable[indexValue][j] - 1 + (indexCountTableDownwardCumulative[i - 1][j] - indexCountTableDownwardCumulative[indexValue][j]);
                ll overall = contributionVal + difference + contributionIncreasedInLeftSide;
                ll save = yCalc[j] - overall;
                if(save > maximumSave)
                {
                    maximumSave = save;
                    cout << "Maximum Save Index: " << i << " " << j << " IndexValue: " << indexValue << endl;
                }
            }
        }
        cout << maximumSave << endl;
        ll solution = yTotal - maximumSave;
        cout << "Solution: " << solution << endl;
    }
    return 0;
}
