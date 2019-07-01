#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int k = 0; k < testcases; k++)
    {
        long long int numberOfTunnels, numberOfCars, distance, speed;
        cin >> numberOfTunnels;
        long long int maximum = -1;
        for(int i = 0; i < numberOfTunnels; i++)
        {
            long long int value;
            cin >> value;
            if(value > maximum)
            {
                maximum = value;
            }
        }
        cin >> numberOfCars >> distance >> speed;
        double solution = (double)((numberOfCars - 1) * maximum);
        cout.precision(9);
        cout << fixed << solution << endl;
        //cout << fixed << solution << endl;
    }
    return 0;
}
