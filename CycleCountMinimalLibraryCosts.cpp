#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Node
{
    public:
        ll parentIndex;
        ll index;
};

int main()
{
    ll queries;
    cin >> queries;
    for(ll l = 0; l < queries; l++)
    {
        ll cities, roads, libraryCost, roadCost;
        ll cyclesCount = 0;
        cin >> cities >> roads >> libraryCost >> roadCost;
        vector< Node > cityNodes(cities + 1);
        for(ll i = 0; i <= cities; i++)
        {
            cityNodes[i].parentIndex = i;
            cityNodes[i].index = i;
        }
        for(ll i = 0; i < roads; i++)
        {
            ll city1, city2;
            cin >> city1 >> city2;
            while(cityNodes[city1].parentIndex != cityNodes[city1].index)
            {
                city1 = cityNodes[city1].parentIndex;
            }
            while(cityNodes[city2].parentIndex != cityNodes[city2].index)
            {
                city2 = cityNodes[city2].parentIndex;
            }
            if(cityNodes[city1].parentIndex == cityNodes[city2].parentIndex)
            {
                cyclesCount += 1;
            }
            else
            {
                cityNodes[city2].parentIndex = cityNodes[city1].parentIndex;
            }
        }
        ll librariesRequired = 0;
        for(ll i = 1; i <= cities; i++)
        {
            if(cityNodes[i].index == cityNodes[i].parentIndex)
            {
                librariesRequired += 1;
            }
        }
        // cout << cyclesCount << " " << librariesRequired << endl;
        ll totalMinCost1 = librariesRequired * libraryCost + (roads - cyclesCount) * roadCost;
        ll totalMinCost2 = cities * libraryCost;
        if(totalMinCost1 < totalMinCost2)
        {
            cout << totalMinCost1 << endl;
        }
        else
        {
            cout << totalMinCost2 << endl;
        }
    }
    return 0;
}
