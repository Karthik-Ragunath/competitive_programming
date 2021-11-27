#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll modulasValue = 747474747;

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll N, dimensions;
        cin >> N >> dimensions;
        vector< ll > distance(N);
        vector< bool > visited(N);
        vector< vector < ll > > input(N, vector < ll > (dimensions));
        ll answer = 1;
        for(ll i = 0; i < N; i++)
        {
            for(ll j = 0; j < dimensions; j++)
            {
                cin >> input[i][j];
            }
        }
        distance[0] = 0;
        visited[0] = true;
        for(ll i = 1; i < N; i++)
        {
            ll distanceValue = 0;
            for(ll l = 0; l < dimensions; l++)
            {
                ll currentDistance = input[i][l] - input[0][l];
                // distanceValue = (distanceValue + (currentDistance * currentDistance) % modulasValue) % modulasValue; //Wrong
                distanceValue = (distanceValue + (currentDistance * currentDistance));
            }
            if(distanceValue > distance[i])
            {
                distance[i] = distanceValue;
            }
        }
        for(ll j = 1; j < N; j++)
        {
            ll largestIndex = 0;
            //distance[0] will always be zero and therefore largestIndex is always set as 0
            for(ll i = 1; i < N; i++)
            {
                if(!visited[i])
                {
                    if(distance[i] >= distance[largestIndex])
                    {
                        largestIndex = i;
                    }
                }
            }
            visited[largestIndex] = true;
            if(distance[largestIndex] != 0)
            {
                answer = ((answer % modulasValue) * (distance[largestIndex] % modulasValue)) % modulasValue;
                // cout << "Distance of index " << largestIndex << " : " << distance[largestIndex] << " answer: " << answer << endl;
            }
            for(ll i = 1; i < N; i++)
            {
                if(!visited[i])
                {
                    ll distanceValue = 0;
                    for(ll l = 0; l < dimensions; l++)
                    {
                        ll currentDistance = input[i][l] - input[largestIndex][l];
                        // distanceValue = (distanceValue + (currentDistance * currentDistance) % modulasValue) % modulasValue; //Wrong
                        distanceValue = (distanceValue + (currentDistance * currentDistance));
                    }
                    if(distanceValue > distance[i])
                    {
                        distance[i] = distanceValue;
                    }
                }
            }
        }
        cout << answer << endl;
    }
}
