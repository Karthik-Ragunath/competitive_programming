#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< ll > fibonacciVector(100007);
ll modulasValue = 1000000007;

void generateFibonacci()
{
    fibonacciVector[0] = 0;
    fibonacciVector[1] = 1;
    for(ll i = 2; i < 100007; i++)
    {
        fibonacciVector[i] = (fibonacciVector[i - 1] % modulasValue + fibonacciVector[i - 2] % modulasValue) % modulasValue;
    }
}

int main()
{
    generateFibonacci();
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        ll M, N;
        cin >> M >> N;
        vector< ll > vectorA(M);
        vector< ll > vectorB(M);
        for(ll i = 0; i < M; i++)
        {
            cin >> vectorA[i];
        }
        for(ll i = 0; i < M; i++)
        {
            cin >> vectorB[i];
        }
        ll n1Multiplier = fibonacciVector[N - 2] % modulasValue;
        ll n2Multiplier = fibonacciVector[N - 1] % modulasValue;
        // cout << fibonacciVector[100000] << " " << fibonacciVector[879] << endl;
        ll solution = 0;
        for(ll i = 0; i < M; i++)
        {
            for(ll j = 0; j < M; j++)
            {
                ll n1 = vectorA[i];
                ll n2 = vectorB[j];
                if(N >= 3)
                {
                    ll finalN1Value = (n1 * n1Multiplier) % modulasValue;
                    ll finalN2Value = (n2 * n2Multiplier) % modulasValue;
                    ll finalValue = (finalN1Value + finalN2Value) % modulasValue;
                    // cout << "Final Value: " << finalValue << endl;
                    solution = (solution + finalValue) % modulasValue;
                }
                else if(N == 2)
                {
                    solution = (solution + n2) % modulasValue;
                }
                else
                {
                    solution = (solution + n1) % modulasValue;
                }
            }
        }
        cout << solution << endl;
    }
}
