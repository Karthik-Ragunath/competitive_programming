// https://www.hackerrank.com/challenges/min-max-riddle/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector< ll > inputs(n);
    vector< ll > left(n);
    vector< ll > right(n);
    vector< ll > solution(n + 1);
    for(ll i = 0; i < n; i++)
    {
        cin >> inputs[i];
        left[i] = -1;
        right[i] = n;
    }
    stack< ll > leftStack;
    stack< ll > rightStack;
    for(ll i = 0; i < n; i++)
    {
        while(!leftStack.empty() && inputs[leftStack.top()] >= inputs[i])
        {
            leftStack.pop();
        }
        if(!leftStack.empty())
        {
            left[i] = leftStack.top();
        }
        leftStack.push(i);
    }
    for(ll i = n - 1; i >= 0; i--)
    {
        while(!rightStack.empty() && inputs[rightStack.top()] >= inputs[i])
        {
            rightStack.pop();
        }
        if(!rightStack.empty())
        {
            right[i] = rightStack.top();
        }
        rightStack.push(i);
    }
    for(ll i = 0; i < n; i++)
    {
        // cout << "Right[i]: " << right[i] << " " << "Left[i]: " << left[i] << endl;
        ll rangeInWhichGivenElementIsMin = right[i] - left[i] - 1;
        solution[rangeInWhichGivenElementIsMin] = max(solution[rangeInWhichGivenElementIsMin], inputs[i]);
    }
    for(ll i = n - 1; i >= 1; i--)
    {
        solution[i] = max(solution[i], solution[i + 1]);
    }
    for(ll i = 1; i <= n; i++)
    {
        cout << solution[i] << " ";
    }
    cout << endl;
    return 0;
}
