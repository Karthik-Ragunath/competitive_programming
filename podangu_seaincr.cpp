#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 1000110
// vector< vector< int > > rangeIndex(1000111);
vector< int > rangeIndex[maxn];
int last[maxn];
int fenwickTree[maxn];
int maxx[maxn];
int solutionVect[maxn];
int input[maxn];
// vector< vector < pair< int, int > > > queries(1000111);
vector < pair< int, int > > queries[maxn];

void createFenwickTree(int startingIndex, int endingIndex, int maximumValue)
{
    int i = startingIndex;
    while(i <= endingIndex)
    {
        fenwickTree[i] = max(fenwickTree[i], maximumValue);
        i += (i & -i);
        // cout << "ending index:" << fenwickTree[i] << endl;;
    }
}

void updateDAG(int index, int maxValue, int n)
{
    if(maxValue > maxx[index])
    {
        // cout << "max val: " << maxx[index] << endl;
        for(auto v: rangeIndex[index])
        {
            updateDAG(v, maxValue + 1, n);
        }
        // cout << "Index: " << index << endl;
        // vector< int >::iterator iter = rangeIndex[index].begin();
        // for(; iter != rangeIndex[index].end(); iter++)
        // {
        //     int indexValue = *iter;
        //     // cout << "Index Value: " << indexValue << endl;
        //     updateDAG(indexValue, maxValue + 1, n);
        // }
    }
    if(maxValue > maxx[index])
    {
        maxx[index] = maxValue;
        createFenwickTree(index, n, maxValue);
        // cout << "index: " << index << " maxx: " << maxx[index] << endl;
    }
}

// Hi,

// Thank you for the opportunity. 

// I am excited for further interview rounds at Google.

// I will go through the prep doc and prepare well for the interview. I will apply in the link provided by tonight.

// Just to confirm, the telephonic interview round will be around 15th of July right ?

// Regards,
// Karthik Ragunath A

int fenwickTreeRangeQuery(int endingIndex)
{
    int exists = endingIndex;
    int maxVal = 0;
    while(exists > 0)
    {
        int valueNow = fenwickTree[exists];
        if(valueNow > maxVal)
        {
            maxVal = valueNow;
        }
        exists -= (exists & -exists);
        // cout << "createFenwickTree maxval: " << maxVal;
    }
    return maxVal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcases;
    scanf("%d", &testcases);
    for(int l = 0; l < testcases; l++)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            int value;
            scanf("%d", &value);
            last[value] = i;
            input[i] = value;
            int prev = 0;
            for(int j = value - 1; j >= 1; j--)
            {
                if(last[j] > prev) //Since DAG is applied to aint elements on the right irrespective of given range
                {
                    prev = last[j];
                    rangeIndex[prev].push_back(i);
                    // cout << "i: " << i << " prev: " << prev << endl;
                }
            }
        }
        // printLast(input, last, n);
        // printRangeIndex(n);
        for(int i = 1; i <= q; i++)
        {
            int startIndex, endIndex;
            scanf("%d%d", &startIndex, &endIndex);
            queries[startIndex].push_back(make_pair(endIndex, i));
        }

        for(int i = n; i >= 1; i--)
        {
            updateDAG(i, 1, n);
            for(auto v:queries[i])
            {
                solutionVect[v.second] = fenwickTreeRangeQuery(v.first);
            }
            // vector< pair< int, int > >::iterator iter = queries[i].begin();
            // for(; iter != queries[i].end(); iter++)
            // {
            //     int endIndex = iter -> first;
            //     int solutionNumber = iter -> second;
            //     int solution = fenwickTreeRangeQuery(endIndex);
            //     solutionVect[solutionNumber] = solution;
            // }
        }
        for(int i = 1; i <= q; i++)
        {
            // printf("%d\n", solutionVect[i]);
            cout << solutionVect[i] << "\n";
        }
        for(int i = 0; i <= n + 1; i++)
        {
            fenwickTree[i] = 0;
            rangeIndex[i].clear();
            queries[i].clear();
            last[input[i]] = 0;
            maxx[i] = 0;
        }    
    }
    return 0;
}
