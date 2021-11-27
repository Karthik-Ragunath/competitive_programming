#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a != b)
        {
            if(c == a)
            {
                if(d == b)
                {
                    cout << "YES" << endl;
                    continue;
                }
            }
            else if(c == b)
            {
                if(d == a)
                {
                    cout << "YES" << endl;
                    continue;
                }
            }
            cout << "NO" << endl;
            continue;
        }
        else
        {
            if(c == d)
            {
                cout << "YES" << endl;
                continue;
            }
            else
            {
                cout << "NO" << endl;
                continue;
            }
        }
    }
}
