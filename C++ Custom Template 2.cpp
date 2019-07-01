#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <array>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Node
{
	public:
		int index;
		vector<Node> children;
};

void editVector(vector<Node> &vect)
{
	cout << "Inside editVector" << endl;
	vector<Node>::iterator itr = vect.begin();
	for(;itr != vect.end();)
	{
		int index = itr -> index;
		cout << "Index: " << index << endl;
		vector<Node>::iterator childrenIter = itr -> children.begin();
		for(;childrenIter != itr -> children.end();)
		{
			cout << "Inside Inside" << endl;
			int indexInside = childrenIter -> index;
			cout << indexInside << endl;
			++childrenIter;
		}
		cout << "End Inside Inside" << endl;
		++itr;
	}
}

void alterVector(vector<int> &sizey)
{
	sizey[3] = 6;
	vector<int>::iterator it = sizey.begin();
	for(;it != sizey.end();)
	{
		if(*it == 6)
		{
			it = sizey.erase(it);
		}
		else
		{
			++it;
		}
	}
}

int main() {
	// vector<bool> visited(5);
	// cout << visited[0] << " " << visited[3] << " " << visited[4] << endl;
	// fill(visited.begin(), visited.end(), false);
	// cout << visited[0] << " " << visited[3] << " " << visited[4] << endl;
	// bool falser = false;
	// bool truer = true;
	// cout << falser << endl;
	// cout << truer << endl;
	vector<int> sizey(5);
	alterVector(sizey);
	cout << sizey.size() << endl;
	vector<Node> nodes;
	Node node1;
	node1.index = 1;
	Node node2;
	node2.index = 2;
	Node node3;
	node3.index = 3;
	node1.children.push_back(node2);
	node2.children.push_back(node3);
	node3.children.push_back(node1);
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	cout << "Nodes size: " << nodes.size() << endl;
	editVector(nodes);
	// your code goes here
	return 0;
}
