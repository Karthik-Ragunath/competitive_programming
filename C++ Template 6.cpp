#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int main()
{
	map<int, int> priorityMap;
	priorityMap[0] = 5;
	priorityMap[1] = 17;
	priorityMap[2] = 4;
	priorityMap[3] = 18;
	priorityMap[4] = 19;

	map<int, int>::iterator itr = priorityMap.begin();
	for(;itr != priorityMap.end(); itr++)
	{
		cout << itr -> first << " " << itr -> second << endl;
	}
    return 0;
}
