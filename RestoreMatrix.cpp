#include <bits/stdc++.h>
using namespace std;
/*
void printVect(vector <vector<long long int> > &mat, long long int row, long long int col)
{
    cout << "----Printer----" << endl;
    for(long long int j = 0; j < row; j++)
    {
        for(long long int k = 0; k < col; k++)
        {
            cout << mat[j][k] << " ";
        }
        cout << endl;
    }
    cout << "----Printer----" << endl;
}
*/

int main()
{
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++)
    {
        long long int row, col;
        cin >> row >> col;
        vector < vector<long long int> > mat(row, vector<long long int>(col));
        for(long long int j = 0; j < row; j++)
        {
            for(long long int k = 0; k < col; k++)
            {
                cin >> mat[j][k];
            }
        }
        //printVect(mat, row, col);
        bool solutionExists = true;
        for(long long int j = 0; j < row; j++)
        {
            for(long long int k = 0; k < col; k++)
            {
                if(mat[j][k] == -1)
                {
                    long long int previousColValue = -1;
                    if(k - 1 >= 0)
                    {
                        previousColValue = mat[j][k - 1];
                    }
                    long long int nextColValue = -1;
                    if((k + 1) < col && mat[j][k + 1] != -1)
                    {
                        nextColValue = mat[j][k + 1];
                    }
                    long long int previousRowValue = -1;
                    if(j - 1 >= 0)
                    {
                        previousRowValue = mat[j - 1][k];
                    }
                    long long int nextRowValue = -1;
                    if((j + 1) < row && mat[j + 1][k] != -1)
                    {
                        nextRowValue = mat[j + 1][k];
                    }
                    long long int prevMax = max(previousColValue, previousRowValue);
                    long long int nextMin;
                    if(nextColValue != -1 && nextRowValue != -1)
                    {
                        nextMin = min(nextColValue, nextRowValue);
                    }
                    else if(nextColValue == -1 && nextRowValue == -1)
                    {
                        nextMin = -1;
                    }
                    else
                    {
                        nextMin = max(nextColValue, nextRowValue);
                    }
                    if(nextMin != -1)
                    {
                        if(prevMax > nextMin)
                        {
                            solutionExists = false;
                            break;
                        }
                        else
                        {
                            if(prevMax != -1)
                            {
                                mat[j][k] = prevMax;
                            }
                            else
                            {
                                mat[j][k] = 1;
                            }
                        }
                    }
                    else
                    {
                        if(prevMax != -1)
                        {
                            mat[j][k] = prevMax;
                        }
                        else
                        {
                            mat[j][k] = 1;
                        }
                    }
                }
                else
                {
                    if(j - 1 >= 0 && k - 1 >= 0)
                    {
                        if(mat[j][k] >= mat[j - 1][k] && mat[j][k] >= mat[j][k - 1])
                        {
                            continue;
                        }
                        else
                        {
                            solutionExists = false;
                            break;
                        }
                    }
                    else if(j - 1 >= 0)
                    {
                        if(mat[j][k] >= mat[j - 1][k])
                        {
                            continue;
                        }
                        else
                        {
                            solutionExists = false;
                            break;
                        }
                    }
                    else if(k - 1 >= 0)
                    {
                        if(mat[j][k] >= mat[j][k - 1])
                        {
                            continue;
                        }
                        else
                        {
                            solutionExists = false;
                            break;
                        }
                    }
                }
            }
            if(!solutionExists)
            {
                break;
            }
        }
        if(solutionExists)
        {
            for(long long int j = 0; j < row; j++)
            {
                for(long long int k = 0; k < col; k++)
                {
                    cout << mat[j][k] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}
    
