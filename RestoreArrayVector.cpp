#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll factorial(ll number)
{
    ll value = 1;
    for(ll i = number; i >= 1; i--)
    {
        value = value * i;
    }
    return value;
}

void printVector(vector< ll > &vectorPrint)
{
    cout << "------Print Origin------" << endl;
    vector< ll >::iterator itr = vectorPrint.begin();
    for(; itr!= vectorPrint.end(); itr++)
    {
        cout << *itr << endl;
    }
    cout << "---------Print Ends---------" << endl;
}

void addIncreasing(vector< pair<ll, ll> > &increasing, ll lower, ll upper)
{
    vector< pair<ll, ll> >::iterator increasingIter = increasing.begin();
    bool isNewElement = true;
    for(;increasingIter != increasing.end(); increasingIter++)
    {
        ll iterLower = increasingIter -> first;
        ll iterUpper = increasingIter -> second;
        if(lower < iterLower && upper > iterUpper)
        {
            increasingIter -> first = lower;
            increasingIter -> second = upper;
            isNewElement = false;
            break;
        }
        else if(lower >= iterLower && lower < iterUpper && upper > iterUpper)
        {
            increasingIter -> first = iterLower;
            increasingIter -> second = upper;
            isNewElement = false;
            break;
        }
        else if(lower < iterLower && upper > iterLower && upper <= iterUpper)
        {
            increasingIter -> first = lower;
            increasingIter -> second = iterUpper;
            isNewElement = false;
            break;
        }
        else if(lower >= iterLower && upper <= iterUpper)
        {
            isNewElement = false;
            break;
        }
    }
    if(isNewElement)
    {
        increasing.push_back(make_pair(lower, upper));
    }
}

void addDecreasing(vector< pair<ll, ll> > &decreasing, ll lower, ll upper)
{
    vector< pair<ll, ll> >::iterator decreasingIter = decreasing.begin();
    bool isNewElement = true;
    for(;decreasingIter != decreasing.end(); decreasingIter++)
    {
        ll iterLower = decreasingIter -> first;
        ll iterUpper = decreasingIter -> second;
        if(lower < iterLower && upper > iterUpper)
        {
            decreasingIter -> first = lower;
            decreasingIter -> second = upper;
            isNewElement = false;
            break;
        }
        else if(lower >= iterLower && lower < iterUpper && upper > iterUpper)
        {
            decreasingIter -> first = iterLower;
            decreasingIter -> second = upper;
            isNewElement = false;
            break;
        }
        else if(lower < iterLower && upper > iterLower && upper <= iterUpper)
        {
            decreasingIter -> first = lower;
            decreasingIter -> second = iterUpper;
            isNewElement = false;
            break;
        }
        else if(lower >= iterLower && upper <= iterUpper)
        {
            isNewElement = false;
            break;
        }
    }
    if(isNewElement)
    {
        decreasing.push_back(make_pair(lower, upper));
    }
}

bool checkValidity(vector < pair<ll, ll> > &increasing, vector < pair<ll, ll> > &decreasing)
{
    vector< pair<ll, ll> >::iterator increasingIter = increasing.begin();
    vector< pair<ll, ll> >::iterator decreasingIter = decreasing.begin();
    bool solutionExists = true;
    cout << "Came Here in check validity" << endl;
    for(;decreasingIter != decreasing.end();decreasingIter++)
    {
        ll decreasingIterLower = decreasingIter -> first;
        ll decreasingIterUpper = decreasingIter -> second;

        for(;increasingIter != increasing.end();)
        {
            ll increasingIterLower = increasingIter -> first;
            ll increasingIterUpper = increasingIter -> second;

            if(decreasingIterLower >= increasingIterUpper)
            {
                increasingIter++;
                continue;
            }
            else if(increasingIterLower >= decreasingIterUpper)
            {
                break;
            }
            else
            {
                solutionExists = false;
                break;
            }
            /*
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
            */
        }
        if(!solutionExists)
        {
            break;
        }
    }
    cout << "Solution Exists: " << solutionExists << endl;
    return solutionExists;
}

void mergeIncreasingAndDecreasing(vector< pair< ll, ll > > &increasing, vector< pair< ll, ll > > &decreasing)
{
    vector< pair<ll,ll> >::iterator incIter = increasing.begin();
    vector< pair<ll,ll> >::iterator decIter = decreasing.begin();
    for(; decIter != decreasing.end(); decIter++)
    {
        for(; incIter != increasing.end(); incIter++)
        {

        }
    }
}

class CompareVectorPairs
{
    public:
        bool operator() (const pair<ll, ll> pair1, const pair<ll, ll> pair2)
        {
            if(pair1.first < pair2.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll m = 0; m < testcases; m++)
    {
        ll size, queries, k;
        cin >> size >> queries >> k;
        vector<ll> elements;
        vector< pair<ll, ll> > increasing;
        vector< pair<ll, ll> > decreasing;
        for(ll i = 0; i < size; i++)
        {
            ll temp;
            cin >> temp;
            elements.push_back(temp);
        }
        ll increasingSize = 0, decreasingSize = 0;
        vector< pair<ll, ll> > increasingActual;
        vector< pair<ll, ll> > decreasingActual;
        for(ll i = 0; i < queries; i++)
        {
            char type;
            cin >> type;
            if(type == 'I')
            {
                ll lower, upper;
                cin >> lower >> upper;
                addIncreasing(increasing, lower, upper);
                increasingActual.push_back(make_pair(lower, upper));
                increasingSize++;
            }
            else
            {
                ll lower, upper;
                cin >> lower >> upper;
                addDecreasing(decreasing, lower, upper);
                decreasingActual.push_back(make_pair(lower, upper));
                decreasingSize++;
            }
        }
        sort(increasing.begin(), increasing.end(), CompareVectorPairs());
        sort(decreasing.begin(), decreasing.end(), CompareVectorPairs());
        sort(increasingActual.begin(), increasingActual.end(), CompareVectorPairs());
        sort(decreasingActual.begin(), decreasingActual.end(), CompareVectorPairs());
        bool valid = checkValidity(increasing, decreasing);
        if(valid)
        {
            vector< pair<ll, ll> >::iterator iterInc = increasing.begin();
            vector< pair<ll, ll> >::iterator iterDec = decreasing.begin();
            cout << "Dec Size: " << decreasing.size() << endl;
            bool solutionExists = true;
            ll numberOfSolutions = 0;
            for(; iterInc != increasing.end(); iterInc++)
            {
                ll lower = iterInc -> first;
                ll higher = iterInc -> second;
                cout << "Inc Lower: " << lower << " Inc Higher: " << higher << endl;
                ll maxKLimit = higher - lower + 1;
                if(maxKLimit > k)
                {
                    cout << "0" << endl;
                    solutionExists = false;
                    cout << "Came Here 1" << endl;
                    break;
                }
                else
                {
                    bool allUnidentified = true;
                    ll minimumValue = -2;
                    printVector(elements);
                    for(ll i = lower; i <= higher; i++)
                    {
                        if(allUnidentified)
                        {
                            if(elements[i] != -1)
                            {
                                if(elements[i] <= k)
                                {
                                    allUnidentified = false;
                                    minimumValue = elements[i];
                                    continue;
                                }
                                cout << "Came Here 2" << endl;
                                solutionExists = false;
                                break;
                            }
                        }
                        else
                        {
                            if(elements[i] == -1)
                            {
                                if(minimumValue + 1 <= k)
                                {
                                    minimumValue = minimumValue + 1;
                                    continue;
                                }
                            }
                            else if((elements[i] - minimumValue == 1) && elements[i] <= k)
                            {
                                minimumValue = minimumValue + 1;
                                continue;
                            }
                            solutionExists = false;
                            cout << "Came Here 3" << endl;
                            break;
                        }
                    }
                    if(solutionExists)
                    {
                        if(allUnidentified)
                        {
                            ll numberOfTerms = higher - lower + 1;
                            numberOfSolutions += factorial(numberOfTerms);
                            cout << "Factorial 1: " << numberOfSolutions << endl;
                        }
                        else
                        {
                            numberOfSolutions += 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }

            cout << "Mid Solution Exists: " << solutionExists << endl;
            if(solutionExists)
            {
                for(; iterDec != decreasing.end(); iterDec++)
                {
                    ll lower = iterInc -> first;
                    ll higher = iterInc -> second;
                    cout << "Dec Lower: " << lower << " Dec Higher: " << higher << endl;
                    ll maxKLimit = higher - lower + 1;
                    if(maxKLimit > k)
                    {
                        cout << "0" << endl;
                        solutionExists = false;
                        cout << "Came Here 4" << endl;
                        break;
                    }
                    else
                    {
                        bool allUnidentified = true;
                        ll minimumValue = -2;
                        for(ll i = lower; i <= higher; i++)
                        {
                            if(allUnidentified)
                            {
                                if(elements[i] != -1)
                                {
                                    if(elements[i] <= k)
                                    {
                                        allUnidentified = false;
                                        minimumValue = elements[i];
                                        continue;
                                    }
                                    cout << "Came Here 5" << endl;
                                    solutionExists = false;
                                    break;
                                }
                            }
                            else
                            {
                                if(elements[i] == -1)
                                {
                                    if(minimumValue - 1 >= 1)
                                    {
                                        minimumValue = minimumValue - 1;
                                        continue;
                                    }
                                }
                                else if((minimumValue - elements[i] == 1) && elements[i] >= 0)
                                {
                                    minimumValue = minimumValue - 1;
                                    continue;
                                }
                                solutionExists = false;
                                cout << "Came Here 6" << endl;
                                break;
                            }
                        }
                        if(solutionExists)
                        {
                            if(allUnidentified)
                            {
                                ll numberOfTerms = higher - lower + 1;
                                numberOfSolutions += factorial(numberOfTerms);
                                cout << "Factorial 2: " << numberOfSolutions << endl;
                            }
                            else
                            {
                                numberOfSolutions += 1;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            if(solutionExists)
            {
                cout << numberOfSolutions << endl;
            }
            else
            {
                cout << "0" << endl;
            }
            /*
            vector< pair<ll, ll> >::iterator iterInc = increasing.begin();
            vector< pair<ll, ll> >::iterator iterDec = decreasing.begin();
            vector< pair<ll, ll> >::iterator iterIncAct = increasingActual.begin();
            vector< pair<ll, ll> >::iterator iterDecAct = decreasingActual.begin();

            for(; iterIncAct != increasingActual.end(); iterIncAct++)
            {
                ll lower = iterIncAct -> first;
                ll upper = iterIncAct -> second;
                for(; iterInc = increasing.end();)
                {
                    ll lowerLim = iterInc -> first;
                    ll upperLim = iterInc -> second;
                    if(lower >= lowerLim && lower < upperLim)
                    {
                        break;
                    }
                    else
                    {
                        iterInc++;
                        continue;
                    }
                }
            }

            for(; iterDecAct != decreasingActual.end(); iterDecAct++)
            {
                ll lower = iterDecAct -> first;
                ll upper = iterDecAct -> second;
                for(; iterDec = decreasing.end();)
                {
                    ll lowerLim = iterDec -> first;
                    ll upperLim = iterDec -> second;
                    if(lower >= lowerLim && lower < upperLim)
                    {
                        break;
                    }
                    else
                    {
                        iterDec++;
                        continue;
                    }
                }
            }
            */
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}
