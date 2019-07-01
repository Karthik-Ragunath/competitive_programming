#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N;
        cin >> N;
        vector< ll > negativeTerms;
        vector< bool > positiveCumulative;
        vector< ll > terms(N);
        vector< ll > sum(N);
        vector< ll > changedValue(N);
        vector< ll > negativeTermsIndex;
        ll size = 0;
        ll totalSum = 0;
        for(ll i = 0; i < N; i++)
        {
            cin >> terms[i];
            totalSum += terms[i];
        }

        for(ll i = 0; i < N; i++)
        {
            bool canBeNegative = true;
            if(i - 1 >= 0)
            {
                if(terms[i] >= terms[i - 1])
                {
                    canBeNegative = false;
                }
            }
            if(i + 1 < N && canBeNegative)
            {
                if(terms[i] >= terms[i + 1])
                {
                    canBeNegative = false;
                }
            }
            if(canBeNegative)
            {
                size++;
                negativeTerms.push_back(terms[i]);
                negativeTermsIndex.push_back(i);
                changedValue[i] = terms[i] * -1;
                if(i - 1 >= 0)
                {
                    sum[i] = sum[i - 1] + changedValue[i];
                    if(sum[i] <= 0)
                    {
                        positiveCumulative.push_back(false);
                    }
                    else
                    {
                        positiveCumulative.push_back(true);
                    }
                }
                else
                {
                    sum[i] = changedValue[i];
                    positiveCumulative.push_back(true);
                }
            }
            else
            {
                changedValue[i] = terms[i];
                if(i - 1 >= 0)
                {
                    if(changedValue[i - 1] < 0)
                    {
                        sum[i] = changedValue[i - 1] + changedValue[i];
                    }
                    else
                    {
                        sum[i] = sum[i - 1] + changedValue[i];
                    }
                }
                else
                {
                    sum[i] = changedValue[i];
                }
            }
        }
        vector< ll > cumulativeSum(size);
        for(ll i = 0; i < size; i++)
        {
            if((i - 3) >= 0)
            {
                if(positiveCumulative[i])
                {
                    ll cumulativeTemp1 = cumulativeSum[i - 1] + negativeTerms[i];
                    ll cumulativeTemp2 = cumulativeSum[i - 2] + negativeTerms[i];
                    if(cumulativeTemp1 > cumulativeTemp2)
                    {
                        cumulativeSum[i] = cumulativeTemp1;
                    }
                    else
                    {
                        cumulativeSum[i] = cumulativeTemp2;
                    }
                }
                else
                {
                    ll cumulativeTemp1 = cumulativeSum[i - 2] + negativeTerms[i];
                    ll cumulativeTemp2 = cumulativeSum[i - 3] + negativeTerms[i];
                    if(cumulativeTemp1 > cumulativeTemp2)
                    {
                        cumulativeSum[i] = cumulativeTemp1;
                    }
                    else
                    {
                        cumulativeSum[i] = cumulativeTemp2;
                    }
                }
            }
            else if((i - 2) >= 0)
            {
                if(positiveCumulative[i])
                {
                    ll cumulativeTemp1 = cumulativeSum[i - 1] + negativeTerms[i];
                    ll cumulativeTemp2 = cumulativeSum[i - 2] + negativeTerms[i];
                    if(cumulativeTemp1 > cumulativeTemp2)
                    {
                        cumulativeSum[i] = cumulativeTemp1;
                    }
                    else
                    {
                        cumulativeSum[i] = cumulativeTemp2;
                    }
                }
                else
                {
                    cumulativeSum[i] = cumulativeSum[i - 2] + negativeTerms[i];
                }
            }
            else if((i - 1) >= 0)
            {
                if(positiveCumulative[i])
                {
                    cumulativeSum[i] = cumulativeSum[i - 1] + negativeTerms[i];
                }
                else
                {
                    cumulativeSum[i] = negativeTerms[i];
                }
            }
            else
            {
                cumulativeSum[i] = negativeTerms[i];
            }
        }
        ll minValue = 0;
        vector< ll > maxNegationCombination;
        ll sizeOfMaxCombinationNegativeValues = 0;
        if(size >= 2)
        {
            ll maxCumulative1 = cumulativeSum[size - 1];
            ll maxCumulative2 = cumulativeSum[size - 2];
            if(maxCumulative1 > maxCumulative2)
            {
                minValue = totalSum - maxCumulative1;
                for(ll i = (size - 1); i >= 0; i--)
                {
                    if(maxCumulative1 == cumulativeSum[i])
                    {
                        sizeOfMaxCombinationNegativeValues++;
                        maxNegationCombination.push_back(negativeTermsIndex[i]);
                        maxCumulative1 -= negativeTerms[i];
                        if(!positiveCumulative[i])
                        {
                            i -= 1;
                        }
                        if(maxCumulative1 == 0)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                minValue = totalSum - maxCumulative2;
                for(ll i = (size - 2); i >= 0; i--)
                {
                    if(maxCumulative2 == cumulativeSum[i])
                    {
                        sizeOfMaxCombinationNegativeValues++;
                        maxNegationCombination.push_back(negativeTermsIndex[i]);
                        maxCumulative2 -= negativeTerms[i];
                        if(!positiveCumulative[i])
                        {
                            i -= 1;
                        }
                        if(maxCumulative2 == 0)
                        {
                            break;
                        }
                    }
                }
            }
        }
        else if(size == 1)
        {
            minValue = totalSum - cumulativeSum[size - 1];
            sizeOfMaxCombinationNegativeValues++;
            maxNegationCombination.push_back(negativeTermsIndex[size - 1]);
        }

        for(ll i = 0, j = sizeOfMaxCombinationNegativeValues - 1; i < N; i++)
        {
            if(j >= 0)
            {
                if(i == maxNegationCombination[j])
                {
                    ll value = -1 * terms[i];
                    cout << value << " ";
                    j--;
                }
                else
                {
                    cout << terms[i] << " ";
                }
            }
            else
            {
                cout << terms[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
