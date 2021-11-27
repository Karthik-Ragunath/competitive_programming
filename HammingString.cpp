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
    for(int i = 0; i < testcases; i++)
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
        string hammingString = "";
        for(int i = 0; i < numberOfTerms; i++)
        {
            if(vectorA[i] != vectorB[i])
            {
                hammingDistance++;
            }
            hammingString.append(to_string(vectorA[i]));
            if(i != numberOfTerms - 1)
            {
                hammingString.append(" ");
            }
        }
        cout << hammingDistance << endl << hammingString << endl;
    }
    return 0;
}
