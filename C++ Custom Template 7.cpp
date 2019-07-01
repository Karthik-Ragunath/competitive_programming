// C++ program to us priority_queue to implement Min Heap
// for user defined class
#include <bits/stdc++.h>
/*
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <iomanip>
*/
using namespace std;

// User defined class, Point
class Point
{

public:
int x;
int y;
Point(int _x, int _y)
{
	x = _x;
	y = _y;
}
int getX() { return x; }
int getY() { return y; }
};

// To compare two points
class myComparator
{
public:
	int operator() (const Point& p1, const Point& p2)
	{
		//return p1.getX() < p2.getX();
		return p1.x < p2.x;
	}
};

// Driver code
int main ()
{
	// Creates a Min heap of points (order by x coordinate)
	priority_queue <Point, vector<Point>, myComparator > pq;

	// Insert points into the min heap
	pq.push(Point(10, 2));
	pq.push(Point(2, 1));
	pq.push(Point(1, 5));

	set<Point, myComparator> setter;
	setter.insert(Point(10, 2));
	setter.insert(Point(2, 1));
	setter.insert(Point(1, 5));

	set<Point, myComparator>::iterator iter1 = setter.begin();
    cout << iter1 -> x << endl;
	set<Point, myComparator>::iterator iter = setter.find(Point(1,5));
	if(iter != setter.end())
	{
	    cout << "Found" << endl;
	    int xTemp = 8;
	    int yTemp = iter -> y;
	    setter.erase(iter);
	    setter.insert(Point(xTemp, yTemp));
	}
	set<Point, myComparator>::iterator iter2 = setter.begin();
    cout << iter2 -> x << endl;

    set<Point, myComparator>::iterator iter3 = setter.begin();
    for(;iter3 != setter.end();)
    {
        cout << iter3 -> x << " " << iter3 -> y << endl;
        iter3++;
    }

	// One by one extract items from min heap
	while (pq.empty() == false)
	{
		Point p = pq.top();
		cout << "(" << p.getX() << ", " << p.getY() << ")";
		cout << endl;
		pq.pop();
	}

	return 0;
}
