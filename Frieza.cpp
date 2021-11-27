#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    set< ll > goodValues;
    goodValues.insert((ll)('f'));
    goodValues.insert((ll)('r'));
    goodValues.insert((ll)('i'));
    goodValues.insert((ll)('e'));
    goodValues.insert((ll)('z'));
    goodValues.insert((ll)('a'));
    for(ll k = 0; k < testcases; k++)
    {
        string temp;
        cin >> temp;
        string::iterator str = temp.begin();
        ll currentCountGood = 0;
        ll currentCountBad = 0;
        string solutionString = "";
        bool previous;
        set< ll >::iterator setIterBegin = goodValues.find((ll)(*str));
        if(setIterBegin != goodValues.end())
        {
            currentCountGood++;
            previous = true;
            str++;
        }
        else
        {
            currentCountBad++;
            previous = false;
            str++;
        }

        for(; str != temp.end(); str++)
        {
            set< ll >::iterator setIter = goodValues.find((ll)(*str));
            if(setIter != goodValues.end())
            {
                if(previous == false)
                {
                    string solTemp = to_string(currentCountBad);
                    solutionString += solTemp;
                    currentCountBad = 0;
                }
                currentCountGood++;
                previous = true;
            }
            else
            {
                if(previous == true)
                {
                    string solTemp = to_string(currentCountGood);
                    solutionString += solTemp;
                    currentCountGood = 0;
                }
                currentCountBad++;
                previous = false;
            }
        }

        if(currentCountGood > 0)
        {
            string solTemp = to_string(currentCountGood);
            solutionString += solTemp;
            currentCountGood = 0;
        }
        else
        {
            string solTemp = to_string(currentCountBad);
            solutionString += solTemp;
            currentCountBad = 0;
        }
        cout << solutionString << endl;
    }
    return 0;
}
