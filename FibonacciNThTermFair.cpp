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
        ll n1Multiplier = fibonacciVector[N - 2] % modulasValue;
        ll n2Multiplier = fibonacciVector[N - 1] % modulasValue;
        ll solution = 0;
        for(ll i = 0; i < M; i++)
        {
            cin >> vectorA[i];
            if(N != 2)
            {
                if(N != 1)
                {
                    solution = (solution + (((n1Multiplier * vectorA[i]) % modulasValue) * M) % modulasValue) % modulasValue;
                }
                else
                {
                    solution = (solution + ((vectorA[i] * M) % modulasValue)) % modulasValue;
                }
            }
        }

        for(ll i = 0; i < M; i++)
        {
            cin >> vectorB[i];
            if(N != 1)
            {
                if(N != 2)
                {
                    solution = (solution + (((n2Multiplier * vectorB[i]) % modulasValue) * M) % modulasValue) % modulasValue;
                }
                else
                {
                    solution = (solution + ((vectorB[i] * M) % modulasValue)) % modulasValue;
                }
            }
        }

        cout << solution << endl;
    }
}
