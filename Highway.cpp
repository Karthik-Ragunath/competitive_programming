#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll m = 0; m < testcases; m++)
    {
        ll lanes, manSpeed, laneWidth;
        cin >> lanes >> manSpeed >> laneWidth;
        vector< ll > carSpeed(lanes);
        vector< ll > carDirection(lanes);
        vector< ll > carInitialPosition(lanes);
        vector< ll > carLength(lanes);
        for(ll i = 0; i < lanes; i++)
        {
            cin >> carSpeed[i];
        }
        for(ll i = 0; i < lanes; i++)
        {
            cin >> carDirection[i];
        }
        for(ll i = 0; i < lanes; i++)
        {
            cin >> carInitialPosition[i];
        }
        for(ll i = 0; i < lanes; i++)
        {
            cin >> carLength[i];
        }
        double timeTakenToCrossForMan = (double)laneWidth / (double)manSpeed;
        double currentTime = 0;
        for(ll i = 0; i < lanes; i++)
        {
            double timeTakenToCrossForCar = -1;
            double timeTakenForFrontPartToReachYZero = -1;
            if(carDirection[i] == 1)
            {
                ll distanceToTravel = carLength[i] - carInitialPosition[i];
                if(distanceToTravel >= 0)
                {
                    timeTakenToCrossForCar = (double)distanceToTravel / (double)carSpeed[i];
                    if(carInitialPosition[i] <= 0)
                    {
                        timeTakenForFrontPartToReachYZero = (double)(carInitialPosition[i] * -1) / (double)(carSpeed[i]);
                    }
                }
            }
            else
            {
                ll distanceToTravel = carLength[i] + carInitialPosition[i];
                if(distanceToTravel >= 0)
                {
                    timeTakenToCrossForCar = (double)distanceToTravel / (double)carSpeed[i];
                    if(carInitialPosition[i] >= 0)
                    {
                        timeTakenForFrontPartToReachYZero = (double)(carInitialPosition[i]) / (double)(carSpeed[i]);
                    }
                }
            }
            if(timeTakenToCrossForCar >= 0)
            {
                if((currentTime + timeTakenToCrossForMan) < timeTakenForFrontPartToReachYZero || currentTime > timeTakenToCrossForCar)
                {
                    currentTime = currentTime + timeTakenToCrossForMan;
                }
                else
                {
                    currentTime = currentTime + (timeTakenToCrossForCar - currentTime) + timeTakenToCrossForMan + (double)(0.000001);
                }
            }
            else
            {
                currentTime = currentTime + timeTakenToCrossForMan;
            }
        }
        cout.precision(9);
        cout << fixed << currentTime << endl;
    }
    return 0;
}
