#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    for(int k = 0; k < testcases; k++)
    {
        int numberOfTerms;
        cin >> numberOfTerms;
        vector <int> vectorA(numberOfTerms);
        for(int j = 0; j < numberOfTerms; j++)
        {
            cin >> vectorA[j];
        }
        vector <int> vectorB = vectorA;
        for(int i = 0; i < numberOfTerms; i++)
        {
            if(vectorA[i] == vectorB[i])
            {
                for(int j = 0; j < numberOfTerms; j++)
                {
                    if((vectorA[i] != vectorB[j]) && (vectorA[j] != vectorB[i]))
                    {
                        swap(vectorA[i], vectorA[j]);
                        break;
                    }
                }
            }
        }
        int hammingDistance = 0;
        for(int i = 0; i < numberOfTerms; i++)
        {
            if(vectorA[i] != vectorB[i])
            {
                hammingDistance++;
            }
        }
        cout << hammingDistance << endl;
        for(int i = 0; i < numberOfTerms; i++)
        {
            cout << vectorA[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
