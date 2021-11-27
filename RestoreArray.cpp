#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void addIncreasing(set< pair<ll, ll>, CompareSet > &increasing, ll lower, ll upper)
{
    set< pair<ll, ll>, CompareSet >::iterator increasingIter = increasing.begin();
    for(;increasingIter != increasing.end(); increasingIter++)
    {
        ll iterLower = increasingIter -> first;
        ll iterUpper = increasingIter -> second;
        if(lower < iterLower && upper > upperIter)
        {
            increasing.erase(increasingIter);
            increasing.insert(make_pair(lower, upper));
            break;
        }
        else if(lower >= iterLower && lower < iterUpper && upper > iterUpper)
        {
            increasing.erase(increasingIter);
            increasing.insert(make_pair(iterLower, upper));
            break;
        }
        else if(lower < iterLower && upper > iterLower && upper <= iterUpper)
        {
            increasing.erase(increasingIter);
            increasing.insert(make_pair(lower, iterUpper));
            break;
        }
        else if(lower >= iterLower && upper <= iterUpper)
        {
            break;
        }
    }
}

void addDecreasing(set< pair<ll, ll>, CompareSet > &decreasing, ll lower, ll upper)
{
    set< pair<ll, ll>, CompareSet >::iterator decreasingIter = decreasing.begin();
    for(;decreasingIter != decreasing.end(); decreasingIter++)
    {
        ll iterLower = decreasingIter -> first;
        ll iterUpper = decreasingIter -> second;
        if(lower < iterLower && upper > upperIter)
        {
            decreasing.erase(decreasingIter);
            decreasing.insert(make_pair(lower, upper));
            break;
        }
        else if(lower >= iterLower && lower < iterUpper && upper > iterUpper)
        {
            decreasing.erase(decreasingIter);
            decreasing.insert(make_pair(iterLower, upper));
            break;
        }
        else if(lower < iterLower && upper > iterLower && upper <= iterUpper)
        {
            decreasing.erase(decreasingIter);
            decreasing.insert(make_pair(lower, iterUpper));
            break;
        }
        else if(lower >= iterLower && upper <= iterUpper)
        {
            break;
        }
    }
}

bool checkValidity(set < pair<ll, ll>, CompareSet > &increasing, set < pair<ll, ll>, CompareSet > &decreasing)
{
    set< pair<ll, ll>, CompareSet >::iterator increasingItr = increasing.begin();
    set< pair<ll, ll>, CompareSet >::iteartor decreasingIter = decreasing.begin();
    for(;decreasingIter != decreasing.end(); decreasingIter++)
    {
        ll decreasingIterLower = decreasingIter -> first;
        ll decreasingIterUpper = decreasingIter -> second;
        bool solutionExists = true;
        for(;increasingIter != increasing.end(); increasingIter++)
        {
            ll increasingIterLower = increasingIter -> first;
            ll increasingIterUpper = increasingIter -> second;
            if(decreasingIterLower >= increasingIterUpper)
            {
                continue;
            }
            else
            {
                if(decreasingIterLower >= increasingIterLower && decreasingIterLower < increasingIterUpper)
                {
                    solutionExists = false;
                    break;
                }
                else if(decreasingIterUpper > increasingIterLower && decreasingIterUpper <= increasingIterUpper)
                {
                    solutionExists = false;
                    break;
                }
                else if(decreasingIterLower >= increasingIterLower && decreasingIterUpper <= increasingIterUpper)
                {
                    solutionExists = false;
                    break;
                }
                else if(decreasingIterLower < increasingIterLower && decreasingIterUpper > increasingIterUpper)
                {
                    solutionExists = false;
                    break;
                }
            }
        }
        if(!solutionExists)
        {
            break;
        }
    }
    return solutionExists;
}

class CompareSet
{
    public:
        bool operator() (const pair<ll, ll> &pair1, const pair<ll, ll> &pair2)
        {
            if(pair1.second > pair2.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll m = 0; m < testcases; m++)
    {
        ll size, queries, k;
        cin >> size >> queries >> k;
        vector<ll> elements(size);
        set< pair<ll, ll>, CompareSet > increasing;
        set< pair<ll, ll>, CompareSet > decreasing;
        for(ll i = 0; i < size; i++)
        {
            ll temp;
            cin >> temp;
            elements.push_back(temp);
        }
        for(ll i = 0; i < queries; i++)
        {
            char type;
            cin >> type;
            if(type == 'I')
            {
                ll lower, upper;
                cin >> lower >> upper;
                set< pair<ll, ll> >::iterator iter = CompareSet.begin();
                for(;iter != )
                increasing.insert(make_pair(lower, upper));
            }
            else
            {
                ll lower, upper;
                cin >> lower >> upper;
                decreasing.insert(make_pair(lower, upper));
            }
        }
        bool valid = checkValidity(increasing, decreasing);
        if(valid)
        {

        }
        else
        {
            cout << "0" << endl;
        }
    }
    return;
}
