#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    long long int testcases;
    cin >> testcases;
    for(long long int testcase = 0; testcase < testcases; testcase++)
    {
        long long int numberOfVertices;
        cin >> numberOfVertices;
        long long int *verticesX = new long long int[numberOfVertices];
        long long int *verticesY = new long long int[numberOfVertices];
        map <long long int, vector<long long int>> yMap;
        long long int minX = 1000000001;
        long long int maxX = -1000000001;
        long long int minY = 1000000001;
        long long int maxY = -1000000001;
        for(long long int i = 0; i < numberOfVertices; i++)
        {
            cin >> verticesX[i] >> verticesY[i];
            //yMap.insert(make_pair(verticesY[i], i));
            //yMap.count(verticesY[i]) > 0 { // Key already exists };
            yMap[verticesY[i]].push_back(i);
            if (verticesX[i] < minX)
            {
                minX = verticesX[i];
            }
            if (verticesX[i] > maxX)
            {
                maxX = verticesX[i];
            }
            if (verticesY[i] < minY)
            {
                minY = verticesY[i];
            }
            if (verticesY[i] > maxY)
            {
                maxY = verticesY[i];
            }
        }
        // cout << yMap.size() << endl;
        vector <long long int> sortedIndices;
        map<long long int, vector<long long int>>::iterator itr = yMap.begin();
        for(;itr != yMap.end();)
        {
            // cout << "Key" << itr -> first << endl;
            vector<long long int>::iterator vectorIter = itr -> second.begin();
            for(;vectorIter != itr -> second.end();)
            {
                // cout << *vectorIter << endl;
                sortedIndices.push_back(*vectorIter);
                vectorIter++;
            }
            itr++;
        }

        cout << "Sorted Values" << endl;
        vector<long long int> sortedValues;
        vector<long long int>::iterator vectorIter = sortedIndices.begin();
        for(;vectorIter != sortedIndices.end();)
        {
            cout << verticesY[*vectorIter] << endl;
            sortedValues.push_back(verticesY[*vectorIter]);
            vectorIter++;
        }

        //Finding where 6 will be present
        cout << "Lower Bound" << endl;
        vector<long long int>::iterator lowerBound;
        lowerBound = lower_bound(sortedValues.begin(), sortedValues.end(), 8);
        long long int lowerBoundIndex = (lowerBound - sortedValues.begin()) - 1;

        //Index before and after the lowerBound will give the lines connected to that point.
        cout << lowerBoundIndex << endl;

        long long int xPointMin = xMin - 1;
        long long int xPointMax = xMax + 1;
        for (long long int y = yMin; y <= yMax; y++)
        {
            
        }
    }
    return 0;
}
