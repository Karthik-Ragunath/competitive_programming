#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll minValueRequired = 0;

class Node
{
    public:
        ll index;
        vector< ll > children;
        unordered_map< ll, ll > keyValuePairs;
        ll parent;
        ll total;
        ll numberOfDirectChildren;
        ll weight;
};

ll dfs(ll currentIndex, vector< Node > &inputs, vector< bool > &visited)
{
    ll total = inputs[currentIndex].weight;
    ll numberOfDirectChildren = 0;
    visited[currentIndex] = true;
    vector< ll >::iterator childrenIter = inputs[currentIndex].children.begin();
    for(; childrenIter != inputs[currentIndex].children.end();)
    {
        if(!visited[*childrenIter])
        {
            inputs[*childrenIter].parent = currentIndex;
            ll subChildrenWeight = dfs(*childrenIter, inputs, visited);
            inputs[currentIndex].keyValuePairs.insert(make_pair(*childrenIter, subChildrenWeight));
            total += subChildrenWeight;
            numberOfDirectChildren += 1;
            childrenIter++;
        }
        else
        {
            inputs[currentIndex].children.erase(childrenIter);
        }
    }
    inputs[currentIndex].numberOfDirectChildren = numberOfDirectChildren;
    inputs[currentIndex].total = total;
    return total;
}

void cuttingAcrossChildren(vector< Node > &inputs, ll totalValue, ll i, bool &solutionFound)
{
    for(unordered_map< ll, ll >::iterator iter = inputs[i].keyValuePairs.begin(); iter != inputs[i].keyValuePairs.end(); iter++)
    {
        ll index = iter -> first;
        ll value = iter -> second;
        if(totalValue - value == value)
        {
            minValueRequired = 0;
            solutionFound = true;
            break;
        }
        unordered_map< ll, ll >::iterator innerIter = iter;
        for(++innerIter; innerIter != inputs[i].keyValuePairs.end(); innerIter++)
        {
            ll innerIndex = innerIter -> first;
            ll innerValue = innerIter -> second;
            ll treeValue = totalValue - value - innerValue;
            if(treeValue == value && innerValue <= treeValue)
            {
                ll solution = treeValue - innerValue;
                if(!solutionFound)
                {
                    solutionFound = true;
                    minValueRequired = solution;
                }
                else if(solution < minValueRequired)
                {
                    minValueRequired = solution;
                }
            }
            else if(value == innerValue && treeValue <= innerValue)
            {
                ll solution = innerValue - treeValue;
                if(!solutionFound)
                {
                    solutionFound = true;
                    minValueRequired = solution;
                }
                else if(solution < minValueRequired)
                {
                    minValueRequired = solution;
                }
            }
            else if(innerValue == treeValue && value <= treeValue)
            {
                ll solution = treeValue - value;
                if(!solutionFound)
                {
                    solutionFound = true;
                    minValueRequired = solution;
                }
                else if(solution < minValueRequired)
                {
                    minValueRequired = solution;
                }
            }
        }
    }
}

bool solution(vector< Node > &inputs, ll totalValue, ll n)
{
    bool solutionFound = false;
    for(ll i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            cuttingAcrossChildren(inputs, totalValue, i, solutionFound);
            if(solutionFound && minValueRequired == 0)
            {
                break;
            }
        }
        else
        {
            cuttingAcrossChildren(inputs, totalValue, i, solutionFound);
            if(solutionFound && minValueRequired == 0)
            {
                break;
            }

            //Cutting Across Parent and A Child
            ll parent = inputs[i].parent;
            ll valueAtIndex = inputs[i].total;
            ll value1 = totalValue - valueAtIndex;
            if(value1 == valueAtIndex)
            {
                minValueRequired = 0;
                solutionFound = true;
                break;
            }
            for(unordered_map< ll, ll >::iterator iter = inputs[i].keyValuePairs.begin(); iter != inputs[i].keyValuePairs.end(); iter++)
            {
                ll index = iter -> first;
                ll value = iter -> second;
                ll value2 = valueAtIndex - value;
                ll value3 = value;
                if(value1 == value2 && value3 <= value1)
                {
                    ll difference = value1 - value3;
                    if(!solutionFound)
                    {
                        minValueRequired = difference;
                        solutionFound = true;
                    }
                    else if(difference < minValueRequired)
                    {
                        minValueRequired = difference;
                    }
                }
                else if(value2 == value3 && value1 <= value2)
                {
                    ll difference = value2 - value1;
                    if(!solutionFound)
                    {
                        minValueRequired = difference;
                        solutionFound = true;
                    }
                    else if(difference < minValueRequired)
                    {
                        minValueRequired = difference;
                    }
                }
                else if(value3 == value1 && value2 <= value1)
                {
                    ll difference = value1 - value2;
                    if(!solutionFound)
                    {
                        minValueRequired = difference;
                        solutionFound = true;
                    }
                    else if(difference < minValueRequired)
                    {
                        minValueRequired = difference;
                    }
                }
            }
        }
    }
    return solutionFound;
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll l = 0; l < testcases; l++)
    {
        ll n;
        cin >> n;
        vector< Node > inputs(n + 1);
        vector< bool > visited(n + 1);
        for(ll i = 1; i <= n; i++)
        {
            cin >> inputs[i].weight;
        }
        for(ll i = 1; i <= n; i++)
        {
            inputs[i].index = i;
        }
        for(ll i = 0; i < n - 1; i++)
        {
            ll index1, index2;
            cin >> index1 >> index2;
            inputs[index1].children.push_back(index2);
            inputs[index2].children.push_back(index1);
        }
        inputs[1].parent = 1;
        ll totalWeights = dfs(1, inputs, visited);
        minValueRequired = 0;

        bool solutionFound = solution(inputs, totalWeights, n);
        if(solutionFound)
        {
            cout << minValueRequired << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
