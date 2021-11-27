#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <ostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Karthik Ragunath is a good boy";
    string s1 = s.substr(1, 8);
    cout << s1 << endl;
    int length = s1.size();
    cout << length << endl;
    stringstream streamo(s);
    string word;
    while(streamo >> word)
    {
        cout << word << endl;
        cout << word[0] << endl;
    }
    string s2 = "Karthik Ragunath is great";
    cout << s2[0] << endl;
    string *stringer = new string[5];
    for(int i = 0; i < 5; i++)
    {
    	cin >> stringer[i];
    }
    for(int i = 0; i < 5; i++)
    {
    	cout << stringer[i] << endl;
    }
    cout << stringer[0][0] << endl;
    string string1 = "123456";
    stringstream streamer(string1);
    int number;
    streamer >> number;
    int number2 = number + 1;
    cout << number2 << endl;
    string stringConvert = to_string(number);
    cout << stringConvert[0] << stringConvert[1] << endl;
    string cmp1 = "karthik";
    string cmp2 = "karthik";
    if(cmp1.compare(cmp2) == 0)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Different" << endl;
    }
    return 0;
}
