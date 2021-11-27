#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< ll > stepsCount(50, -1);
ll modulas = 10000000007;

//Dont look at it in the form of number combinations, look at it from steps he can reach. For example, from 4th step he can reach 1st, 2nd and 3rd step (-3, -2, -1) steps. Therefore, number of ways to reach fourth step is ways of (3rd + 2nd + 1st).
ll recurseSteps(ll value)
{
    if(value == 0)
    {
        return 1;
    }
    else if(value < 0)
    {
        return 0;
    }
    if(stepsCount[value] != -1)
    {
        return stepsCount[value];
    }
    stepsCount[value] = recurseSteps(value - 1) % modulas;
    stepsCount[value] = (stepsCount[value] + recurseSteps(value - 2)) % modulas;
    stepsCount[value] = (stepsCount[value] + recurseSteps(value - 3)) % modulas;
    return stepsCount[value];
}

int main()
{
    ll inputCount;
    cin >> inputCount;
    vector< ll > originalInputs;
    ll maxValue = 0;
    for(ll i = 0; i < inputCount; i++)
    {
        ll input;
        cin >> input;
        if(i == 0)
        {
            maxValue = input;
        }
        else if(input > maxValue)
        {
            maxValue = input;
        }
        originalInputs.push_back(input);
    }
    // cout << "Maximum Value: " << maxValue << endl;
    ll maxSolution = recurseSteps(maxValue);
    for(ll i = 0; i < inputCount; i++)
    {
        ll stepHeight = originalInputs[i];
        cout << stepsCount[stepHeight] << endl;
    }
    return 0;
}
