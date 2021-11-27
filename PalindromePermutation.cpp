#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void displaySolution(int solutionArray[], int lengthOfArray)
{
    for(int i = 0; i < lengthOfArray; i++)
    {
        cout << solutionArray[i] << " ";
    }
    cout << endl;
}


void intermediateTest(int solutionArray[], int lengthOfArray)
{
    for(int i = 0; i < lengthOfArray; i++)
    {
        cout << "i: " << i << " answer: " << solutionArray[i] << endl;
    }
}

void vector2DDisplay(vector<vector<int>> generic)
{
    int outerSize = generic.size();
    for(int i = 0; i < outerSize; i++)
    {
        int innerSize = generic[i].size();
        for(int j = 0; j < innerSize; j++)
        {
            cout << "i: " << i << " j: " << j << " value: " << generic[i][j] << endl;
        }
    }
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int k = 0; k < testcases; k++)
    {
        string input;
        cin >> input;
        int *alphabets = new int[26]();
        int stringLength = input.length();
        int *solutionArray = new int[stringLength]();
        vector<vector<int>> alphabetIndices(26);
        for(int i = 0; i < stringLength; i++)
        {
            alphabets[input[i] - 'a']++;
            alphabetIndices[input[i] - 'a'].push_back(i + 1);
        }

        /*
        cout << "-------Alphabets Count-------" << endl;
        intermediateTest(alphabets, 26);
        cout << "-------Alphabets Count End------" << endl;

        cout << "-------Alphabets Indices-------" << endl;
        vector2DDisplay(alphabetIndices);
        cout << "--------Alphabet Indices End--------" << endl;
        */

        if(stringLength % 2 == 0)
        {
            bool noSuchPerm = false;
            for(int i = 0; i < 26; i++)
            {
                if(alphabets[i] % 2 != 0)
                {
                    noSuchPerm = true;
                    break;
                }
            }
            if(noSuchPerm)
            {
                cout << "-1" << endl;
            }
            else
            {
                int currentIndex = 0;
                for(int i = 0; i < 26; i++)
                {
                    int countOfAlphabet = alphabets[i];
                    for(int j = 0; j <= countOfAlphabet / 2 - 1; j++)
                    {
                        solutionArray[j + currentIndex] = alphabetIndices[i][j];
                    }
                    for(int j = countOfAlphabet / 2, k = 1; j < countOfAlphabet; j++, k++)
                    {
                        solutionArray[stringLength - k - currentIndex] = alphabetIndices[i][j];
                    }
                    currentIndex = currentIndex + (countOfAlphabet / 2);
                }
                displaySolution(solutionArray, stringLength);
            }
        }
        else
        {
            bool noSuchPerm = false;
            bool firstOddFound = false;
            int oddAlphabet = -1;
            for(int i = 0; i < 26; i++)
            {
                if(alphabets[i] % 2 != 0)
                {
                    if(firstOddFound == false)
                    {
                        firstOddFound = true;
                        oddAlphabet = i;
                    }
                    else
                    {
                        noSuchPerm = true;
                        break;
                    }
                }
            }
            if(noSuchPerm)
            {
                cout << "-1" << endl;
            }
            else
            {
                int currentIndex = 0;
                for(int i = 0; i < 26; i++)
                {
                    if(i != oddAlphabet)
                    {
                        int countOfAlphabet = alphabets[i];
                        for(int j = 0; j <= countOfAlphabet / 2 - 1; j++)
                        {
                            solutionArray[j + currentIndex] = alphabetIndices[i][j];
                        }
                        for(int j = countOfAlphabet / 2, k = 1; j < countOfAlphabet; j++, k++)
                        {
                            solutionArray[stringLength - k - currentIndex] = alphabetIndices[i][j];
                        }
                        currentIndex = currentIndex + countOfAlphabet / 2;
                    }
                }
                int oddAlphabetCount = alphabets[oddAlphabet];
                for(int i = 0; i < oddAlphabetCount; i++)
                {
                    solutionArray[i + currentIndex] = alphabetIndices[oddAlphabet][i];
                }
                displaySolution(solutionArray, stringLength);
            }
        }
    }
}
