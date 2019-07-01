#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int test;
    cin >> test;
    vector<long long int> solution;
    long long int value = 0;
    for(long long int i = 1; value <= 1100000000; i++)
    {
        value += i;
        solution.push_back(value);
    }
    for(long long int m = 0; m < test; m++)
    {
        long long int distance;
        cin >> distance;
        // cout << "Distance: " << distance << endl;
        long long int n = (-1 + sqrt(distance * 2 * 4 + 1)) / 2;
        // cout << "N: " << n << endl;
        long long int subwayDist = solution[n - 1];
        if(distance == subwayDist)
        {
            cout << n << endl;
        }
        else
        {
            long long int prevDis = subwayDist;
            long long int nextDis = solution[n];
            // cout << "Solution: " << solution[2] << endl;
            // cout << "Prev Dist: " << prevDis << endl;
            // cout << "Next Dist: " << nextDis << endl;
            long long int prevWalk = distance - prevDis;
            long long int nextWalk = nextDis - distance;
            // cout << "Next walk: " << nextWalk << endl;
            long long int prevSteps = n + prevWalk;
            long long int nextSteps = n + 1 + nextWalk;
            if(prevSteps < nextSteps)
            {
                cout << prevSteps << endl;
            }
            else
            {
                cout << nextSteps << endl;
            }
        }
    }
}
