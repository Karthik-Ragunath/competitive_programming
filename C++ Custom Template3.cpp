#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
	public:
		int value;
		Node* left;
		Node* right;
};

Node returnFunction(Node input)
{
	input.value = 2;
	// cout << input.value;
	return input;
}

int main() {
	Node root;
	root.value = 5;
	root.left = NULL;
	root.right = NULL;
	root.left = new Node;
	root.left->value = 10;
	Node returnedValue = returnFunction(root);
	cout << returnedValue.value;
	cout << returnedValue.left->value;
	// your code goes here
	return 0;
}
