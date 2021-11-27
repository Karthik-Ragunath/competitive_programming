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
        int numberOfTunnels, numberOfCars, distance, speed;
        //int precision = numeric_limits<double>::max_digits10;
        cin >> numberOfTunnels;
        vector<double> values(numberOfTunnels);
        for(int i = 0; i < numberOfTunnels; i++)
        {
            cin >> values[i];
        }
        cin >> numberOfCars >> distance >> speed;
        double timeBetweenTunnels = (double)distance / (double)speed;

        double **start = new double*[2];
        for(int i = 0; i < 2; i++)
        {
            start[i] = new double[numberOfTunnels];
        }
        double **end = new double*[2];
        for(int i = 0; i < 2; i++)
        {
            end[i] = new double[numberOfTunnels];
        }

        start[0][0] = 0;
        end[0][0] = start[0][0] + values[0];
        for(int i = 1; i < numberOfTunnels; i++)
        {
            start[0][i] = end[0][i - 1] + timeBetweenTunnels;
            end[0][i] = start[0][i] + values[i];
        }

        start[1][0] = values[0];
        end[1][0] = start[1][0] + values[0];
        for(int i = 1; i < numberOfTunnels; i++)
        {
            start[1][i] = end[1][i - 1] + timeBetweenTunnels;
            if(start[1][i] < end[0][i])
            {
                start[1][i] = end[0][i];
            }
            end[1][i] = start[1][i] + values[i];
        }
        /*
        cout << setprecision(precision) << fixed << end[1][numberOfTunnels -1] << endl;
        cout << setprecision(precision) << fixed << end[0][numberOfTunnels -1] << endl;
        */
        double solution = (double)(numberOfCars - 1) * (end[1][numberOfTunnels - 1] - end[0][numberOfTunnels - 1]);
        cout.precision(9);
        cout << fixed << solution << endl;
    }
    return 0;
}
