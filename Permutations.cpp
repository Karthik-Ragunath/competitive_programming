#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solution = 0;

vector< vector< vector< ll > > > permutes(8);
vector< vector< ll > > solutionValue(8);
void permute()
{
    for(ll i = 1; i <= 8; i++)
    {
        vector< ll > v;
        vector< vector< ll > > pushV;
        vector< ll > tempSolVect;
        for(ll j = 0; j < i; j++)
        {
            v.push_back(j + 1);
        }
        ll counter = 0;
        do
        {
            pushV.push_back(v);
            ll solutionTemp = 0;
            for(ll k = 1; k < i; k++)
            {
                if(v[k] > v[k - 1])
                {
                    solutionTemp++;
                }
            }
            tempSolVect.push_back(solutionTemp);
            counter++;
        }while(next_permutation(v.begin(), v.end()));
        permutes[i - 1] = (pushV);
        solutionValue[i - 1] = tempSolVect;
    }
}

void printPermutes(ll N, ll i)
{
    cout << "N: " << N << endl;
    cout << "Size: " << permutes[N - 1][i].size() << endl;
    cout << "Begin" << endl;
    for(ll j = 0; j < N; j++)
    {
        cout << permutes[N - 1][i][j] << " ";
    }
    cout << "end" << endl;
}

void compute(ll N, vector< ll > &input, vector< ll > &nonZeroIndex, ll K)
{
    ll rowSize = permutes[N - 1].size();
    ll columnSize = permutes[N - 1][0].size();
    ll nonZeroSize = nonZeroIndex.size();
    if(nonZeroSize == N)
    {
        ll solVal = solutionValue[N - 1][0];
        //printPermutes(N, 0);
        if(solVal == K)
        {
	        solution = 1;
        }
        else
        {
            solution = 0;
        }
        return;
    }
    //cout << "Row Size: " << rowSize << endl;
    for(ll i = 0; i < rowSize; i++)
    {
        //printPermutes(N, i);
        bool solutionFind = true;
        for(ll j = 0; j < nonZeroSize; j++)
        {
            ll index = nonZeroIndex[j];
            if(permutes[N - 1][i][index] != input[index])
            {
                solutionFind = false;
                break;
            }
        }
        if(solutionFind)
        {
            ll solVal = solutionValue[N - 1][i];
            if(solVal == K)
            {
                solution++;
            }
        }
    }
    return;
}

int main()
{
    ll testcases;
    cin >> testcases;
    permute();
    for(ll k = 0; k < testcases; k++)
    {
        ll N, K;
        cin >> N >> K;
        vector< ll > input;
        vector< ll > inputNonZeroIndex;
        for(ll i = 0; i < N; i++)
        {
            ll value;
            cin >> value;
            input.push_back(value);
            if(value != 0)
            {
                inputNonZeroIndex.push_back(i);
            }
        }
        solution = 0;
        compute(N, input, inputNonZeroIndex, K);
        cout << solution << endl;
    }
    return 0;
}
