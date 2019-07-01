#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

//Kadane's Algorithm
int main()
{
    int testcases;
    cin >> testcases;
    for(int testcase = 0; testcase < testcases; testcase++)
    {
        int numberOfTerms;
        int numberOfIterations;
        cin >> numberOfTerms;
        cin >> numberOfIterations;
        long cumulativeSum = 0;
        long maxCumulative = 0;
        long currentMax = 0;
        long globalMax = 0;
        // int currentMaxNegativeTransitionIndex = -1;
        for(int i = 0; i < numberOfTerms; i++)
        {
            long input;
            cin >> input;
            cumulativeSum = cumulativeSum + input;
            if(i == 0)
            {
                maxCumulative = cumulativeSum;
                currentMax = cumulativeSum;
                globalMax = cumulativeSum;
            }
            else
            {
                if(currentMax <= 0)
                {
                    currentMax = input;
                }
                else
                {
                    currentMax = currentMax + input;
                }
                if(currentMax > globalMax)
                {
                    globalMax = currentMax;
                }
                if(cumulativeSum > maxCumulative)
                {
                    maxCumulative = cumulativeSum;
                }
                // if(currentMax <= 0)
                // {
                //     currentMaxNegativeTransitionIndex = i;
                // }
            }
        }
        if(cumulativeSum > 0)
        {
            if(numberOfIterations > 1)
            {
                long maxTerm1 = currentMax + (numberOfIterations - 2) * cumulativeSum + maxCumulative;
                long maxTerm2 = globalMax;
                if(maxTerm1 >= maxTerm2)
                {
                    cout << maxTerm1 << endl;
                }
                else
                {
                    cout << maxTerm2 << endl;
                }
            }
            else
            {
                cout << globalMax << endl;
            }
        }
        else
        {
            if(numberOfIterations > 1)
            {
                long maxTerm1 = globalMax;
                long maxTerm2 = currentMax + maxCumulative;
                if(maxTerm1 >= maxTerm2)
                {
                    cout << maxTerm1 << endl;
                }
                else
                {
                    cout << maxTerm2 << endl;
                }
            }
            else
            {
                cout << globalMax << endl;
            }
        }
    }
    return 0;
}
