#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll n = 0; n < testcases; n++)
    {
        ll R, r, v;
        double alpha, t;
        //velocity = v * pi
        cin >> R >> r >> v >> alpha >> t;
        ll numberOfRevsInAlpha = (ll)(alpha / 360);
        if(numberOfRevsInAlpha >= 1)
        {
            alpha = alpha - (numberOfRevsInAlpha * 360);
        }
        //T = 2 * pi / (v / absoluteRadius)
        ll absoluteRadius1 = (R - r);
        ll absoluteRadius2 = (R + r);
        double timeTakenSmallerCircle = (double)(2 / (double)v * (double)absoluteRadius1);
        double timeTakenLargerCircle = (double)(2 / (double)v * (double)absoluteRadius2);
        double timeTakenFor2Revs = timeTakenSmallerCircle + timeTakenLargerCircle;
        ll numberOfTwoRevs = (ll)(t / timeTakenFor2Revs);
        double leftOverTime;
        double solution = 0;
        ll insideOrOutside = 0; //At the end if the circle is inward or outward
        if(numberOfTwoRevs >= 1)
        {
            leftOverTime = t - ((double)(numberOfTwoRevs) * timeTakenFor2Revs);
        }
        else
        {
            leftOverTime = t;
        }
        ll numberOfSmallerRevsInLeftOverTime = (ll)(leftOverTime / timeTakenSmallerCircle);
        if(numberOfSmallerRevsInLeftOverTime >= 1)
        {
            leftOverTime = leftOverTime - ((double)timeTakenSmallerCircle);
            solution = (leftOverTime / timeTakenLargerCircle) * 2 * 180 + (double)(numberOfTwoRevs) * 2 * alpha + alpha;
            insideOrOutside = 1;
        }
        else
        {
            solution = (leftOverTime / timeTakenSmallerCircle) * 2 * 180 + (double)(numberOfTwoRevs) * 2 * alpha;
            insideOrOutside = 0;
        }

        ll numberOfRevsPossibleInSolution = (ll)(solution / 360);
        // if(numberOfRevsPossibleInSolution >= 1)
        // {
        //     solution = solution - ((double)numberOfRevsPossibleInSolution * 360);
        //     if(numberOfRevsPossibleInSolution % 2 == 1)
        //     {
        //         insideOrOutside = (insideOrOutside + 1) % 2;
        //     }
        // }

        while(numberOfRevsPossibleInSolution != 0)
        {
            solution = solution - ((double)numberOfRevsPossibleInSolution * 360);
            // cout << "Solution: " << solution << endl;
            if(numberOfRevsPossibleInSolution % 2 == 1)
            {
                insideOrOutside = (insideOrOutside + 1) % 2;
            }
            solution = solution + (numberOfRevsPossibleInSolution * alpha);
            numberOfRevsPossibleInSolution = (ll)(solution / 360);
        }

        cout.precision(6);
        cout << insideOrOutside << " ";
        cout << fixed << solution << endl;
    }
    return 0;
}
