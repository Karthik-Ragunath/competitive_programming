#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *data = new int[4];
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    //data[3] = 4;
    vector<int> v(data, data + 4);
    do {
        cout << v[0] << v[1] << v[2] << endl;
        //cout << v[0] << v[1] << v[2] << v[3] << endl;
    } while(next_permutation(v.begin(), v.end()));
    return 0;
}
