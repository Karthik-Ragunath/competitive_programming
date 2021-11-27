#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long int solution = 0;
int counter = 0;

void compute(string input, int alphabets[], int value, int index)
{
    if(alphabets[value] == 0)
    {
        alphabets[value]++;
        counter++;
        if(counter == 3)
        {
            solution++;
        }
    }
    else
    {
        if(counter == 3)
        {
            if(input[index - 4] - 'a' == value)
            {
                solution++;
            }
            else
            {
                counter = 0;
                alphabets[26] = {0};
            }
        }
        else
        {
            counter = 0;
            alphabets[26] = {0};
        }
    }
}

int main()
{
    long long int testcases;
    cin >> testcases;
    for(long long int i = 0; i < testcases; i++)
    {
        string s;
        cin >> s;
        long long int length = s.length();
        counter = 0;
        solution = 0;
        int alphabets[26] = {0};
        cout << length << endl;
        for(long long int j = 0; j < length; j++)
        {
            if(s[j] - 'a' == 2)
            {
                cout << "2" << " " << counter << " index: " << index << endl;
                compute(s, alphabets, 2, j);
            }
            else if(s[j] - 'a' == 4)
            {
                cout << "4" << " " << counter << " index: " << index << endl;
                compute(s, alphabets, 4, j);
            }
            else if(s[j] - 'a' == 5)
            {
                cout << "5" << " " << counter << " index: " << index << endl;
                compute(s, alphabets, 5, j);
            }
            else if(s[j] - 'a' == 7)
            {
                cout << "7" << " " << counter << " index: " << index << endl;
                compute(s, alphabets, 7, j);
            }
            else
            {
                counter = 0;
                alphabets[26] = {0};
            }
        }
        cout << solution << endl;
    }
    return 0;
}
