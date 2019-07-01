#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll numberOfGreaterValues;
ll numberOfSmallerValues;
ll numberOfSwapsGreaterValues;
ll numberOfSwapsSmallerValues;

ll returnBinarySearchIndexInSortedVector(vector< ll > &values, ll size, ll queryValue)
{
    ll low = 0, high = size - 1, mid;
    // cout << low << " " << high << endl;
    while(low <= high)
    {
        mid = (low + high) / 2;
        // cout << "mid: " << mid << endl;
        if(values[mid] == queryValue)
        {
            break;
        }
        else if(queryValue < values[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return mid;
}

void binarySearchOnDictionary(vector< ll > &values, ll size, ll index, ll queryValue)
{
    ll low = 0, high = size - 1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(mid == index)
        {
            break;
        }
        else if(index < mid)
        {
            numberOfGreaterValues++;
            if(values[mid] < queryValue)
            {
                numberOfSwapsGreaterValues++;
            }
            high = mid - 1;
        }
        else
        {
            numberOfSmallerValues++;
            if(values[mid] > queryValue)
            {
                numberOfSwapsSmallerValues++;
            }
            low = mid + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N, M;
        cin >> N >> M;
        vector< ll > values(N);
        vector< ll > sortedValues(N);
        unordered_map< ll, ll > indexDictionary;
        for(ll i = 0; i < N; i++)
        {
            cin >> values[i];
            sortedValues[i] = values[i];
            indexDictionary.insert(make_pair(values[i], i));
        }
        sort(sortedValues.begin(), sortedValues.end());
        // cout << "Val 0: " << values[0] << " SortedVal 0: " << sortedValues[0] << endl;
        for(ll i = 0; i < M; i++)
        {
            ll queryValue;
            cin >> queryValue;
            ll queryValueInSortedVector = returnBinarySearchIndexInSortedVector(sortedValues, N, queryValue);
            // cout << "Index: " << queryValueInSortedVector << endl;
            ll indexValueInUnorderedMap = indexDictionary[queryValue];
            numberOfSmallerValues = 0;
            numberOfGreaterValues = 0;
            numberOfSwapsGreaterValues = 0;
            numberOfSwapsSmallerValues = 0;
            binarySearchOnDictionary(values, N, indexValueInUnorderedMap, queryValue);
            ll numberOfGreaterValuesAvailable = (N - 1) - queryValueInSortedVector;
            ll numberOfSmallerValuesAvailable = queryValueInSortedVector;
            // cout << numberOfGreaterValuesAvailable << " " << numberOfGreaterValues << " " << numberOfSmallerValuesAvailable << " " << numberOfSmallerValues << endl;
            if(numberOfGreaterValuesAvailable >= numberOfGreaterValues && numberOfSmallerValuesAvailable >= numberOfSmallerValues)
            {
                ll numberOfSwaps;
                if(numberOfSwapsGreaterValues > numberOfSwapsSmallerValues)
                {
                    numberOfSwaps = numberOfSwapsSmallerValues + (numberOfSwapsGreaterValues - numberOfSwapsSmallerValues);
                }
                else
                {
                    numberOfSwaps = numberOfSwapsGreaterValues + (numberOfSwapsSmallerValues - numberOfSwapsGreaterValues);
                }
                cout << numberOfSwaps << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }

    }
    return 0;
}
