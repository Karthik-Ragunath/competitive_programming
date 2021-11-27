#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Node
{
    public:
        int value;
        Node* left;
        Node* right;
        int position;
};

Node segmentTree4Head;
Node segmentTree7Head;
Node segmentTree47Head;
Node segmentTree74Head;

Node buildSegmentTree(int inputDigits[], Node head, int low, int high, int position)
{
    if(low == high)
    {
        Node node;
        node.position = position;
        node.value = inputDigits[low];
        node.left = NULL;
        node.right = NULL;
        return node;
    }
    int mid = (low + high) / 2;
    head.left = new Node;
    head.right = new Node;
    head.left = buildSegmentTree(inputDigits, head.left, low, mid, position * 2 + 1);
    head.right = buildSegmentTree(inputDigits, head.right, mid + 1, high, position * 2 + 2);
    head.value = head.left -> value + head.right -> value;
    head.position = position;
    return head;
}

Node buildSegmentTree4(int inputDigits[], Node head, int low, int high, int position)
{
    if(low == high)
    {
        Node node;
        node.position = position;
        if(inputDigits[low] == 4)
        {
            node.value = 1;
        }
        node.left = NULL;
        node.right = NULL;
        return node;
    }
    int mid = (low + high) / 2;
    head.left = new Node;
    head.right = new Node;
    head.left = buildSegmentTree47(inputDigits, head.left, low, mid, position * 2 + 1);
    head.right = buildSegmentTree47(inputDigits, head.right, mid + 1, high, position * 2 + 2);
    head.value = head.left -> value + head.right -> value;
    return head;
}

Node buildSegmentTree7(int inputDigits[], Node head, int low, int high, int position)
{
    if(low == high)
    {
        Node node;
        node.position = position;
        if(inputDigits[low] == 7)
        {
            node.value = 1;
        }
        node.left = NULL;
        node.right = NULL;
        return node;
    }
    int mid = (low + high) / 2;
    head.left = new Node;
    head.right = new Node;
    head.left = buildSegmentTree7(inputDigits, head.left, low, mid, position * 2 + 1);
    head.right = buildSegmentTree7(inputDigits, head.right, mid + 1, high, position * 2 + 2);
    head.value = head.left -> value + head.right -> value;
    return head;
}

Node buildSegmentTree47(int inputDigits[], Node head, int low, int high, int position)
{
    if(low == high)
    {
        Node node;
        node.position = position;
        if(inputDigits[low] == 4)
        {
            node.value = 1;
        }
        node.left = NULL;
        node.right = NULL;
        return node;
    }
    int mid = (low + high) / 2;
    head.left = new Node;
    head.right = new Node;
    head.left = buildSegmentTree47(inputDigits, head.left, low, mid, position * 2 + 1);
    head.right = buildSegmentTree47(inputDigits, head.right, mid + 1, high, position * 2 + 2);
    int node4Value = searchTrees(segmentTree4Head, head.left -> position);
    int node7Value = searchTrees(segmentTree7Head, head.right -> position);
    int leftValue = head.left -> value;
    int rightValue = head.right -> value;
    head.value = max(max((head.left -> value + node7Value),(node4Value + node7Value)),(node4Value + head.right -> value));
    return head;
}

Node buildSegmentTree74(int inputDigits[], Node head, int low, int high, int position)
{
    if(low == high)
    {
        Node node;
        node.position = position;
        if(inputDigits[low] == 7)
        {
            node.value = 1;
        }
        node.left = NULL;
        node.right = NULL;
        return node;
    }
    int mid = (low + high) / 2;
    head.left = new Node;
    head.right = new Node;
    head.left = buildSegmentTree74(inputDigits, head.left, low, mid, position * 2 + 1);
    head.right = buildSegmentTree74(inputDigits, head.right, mid + 1, high, position * 2 + 2);
    int node4Value = searchTrees(segmentTree4Head, head.left -> position);
    int node7Value = searchTrees(segmentTree7Head, head.right -> position);
    int leftValue = head.left -> value;
    int rightValue = head.right -> value;
    head.value = max(max((head.left -> value + node4Value),(node7Value + node4Value)),(node7Value + head.right -> value));
    return head;
}

void swapSegmentTrees(int low, int high, int lowerIndex, int upperIndex, Node head)
{
    if(lowerIndex <= low && upperIndex >= high)
    {
        int position = head.position;
        Node tree7Node = searchTreeNodes(segmentTree7Head, position);
        Node tree47Node = searchTreeNodes(segmentTree47Head, position);
        Node tree74Node = searchTreeNodes(segmentTree74Head, position);
        Node swap1 = head;
        head = tree7Node;
        tree7Node = swap1;
        Node swap2 = tree47Head;
        tree47Head = tree74Head;
        tree74Head = swap2;
        return
    }
    if(lowerIndex > high || upperIndex < low)
    {
        return;
    }
    int mid = (low + high) / 2;
    swapSegmentTrees(low, mid, lowerIndex, upperIndex, head);
    swapSegmentTrees(mid + 1, high, lowerIndex, upperIndex, head);
    return;
}

void updateSegmentTrees(int lowerIndex, int upperIndex, int length)
{
    Node segmentTree4NewHead = updateSegmentTree(0, length, lowerIndex, upperIndex, segmentTree4Head);
    Node segmentTree7NewHead = updateSegmentTree(0, length, lowerIndex, upperIndex, segmentTree7Head);
    Node segmentTree47NewHead = updateSegmentTreeSubSequence47(0, length, lowerIndex, upperIndex, segmentTree47Head);
    Node segmentTree74NewHead = updateSegmentTreeSubSequence74(0, length, lowerIndex, upperIndex, segmentTree74Head);
}

Node updateSegmentTree(int low, int high, int lowerIndex, int upperIndex, Node head)
{
    if(lowerIndex <= low && upperIndex >= high)
    {
        return head
    }
    if(lowerIndex > high || upperIndex < low)
    {
        return head;
    }
    if(low == high)
    {
        return head;
    }
    int mid = (low + high) / 2;
    head.left = updateSegmentTree(low, mid, lowerIndex, upperIndex, head.left);
    head.right = updateSegmentTree(mid + 1, high, lowerIndex, upperIndex, head.right);
    head.value = head.left -> value + head.right -> value;
    return head;
}

Node updateSegmentTreeSubSequence47(int low, int high, int lowerIndex, int upperIndex, Node head)
{
    if(lowerIndex <= low && upperIndex >= high)
    {
        return head
    }
    if(lowerIndex > high || upperIndex < low)
    {
        return head;
    }
    if(low == high)
    {
        return head;
    }
    int mid = (low + high) / 2;
    head.left = updateSegmentTreeSubSequence47(low, mid, lowerIndex, upperIndex, head.left);
    head.right = updateSegmentTreeSubSequence47(mid + 1, high, lowerIndex, upperIndex, head.right);
    int node4Value = searchTrees(segmentTree4Head, head.left -> position);
    int node7Value = searchTrees(segmentTree7Head, head.right -> position);
    int leftValue = head.left -> value;
    int rightValue = head.right -> value;
    head.value = max(max((head.left -> value + node7Value),(node4Value + node7Value)),(node4Value + head.right -> value));
    return head;
 }

 Node updateSegmentTreeSubSequence74(int low, int high, int lowerIndex, int upperIndex, Node head)
 {
     if(lowerIndex <= low && upperIndex >= high)
     {
         return head
     }
     if(lowerIndex > high || upperIndex < low)
     {
         return head;
     }
     if(low == high)
     {
         return head;
     }
     int mid = (low + high) / 2;
     head.left = updateSegmentTreeSubSequence74(low, mid, lowerIndex, upperIndex, head.left);
     head.right = updateSegmentTreeSubSequence74(mid + 1, high, lowerIndex, upperIndex, head.right);
     int node4Value = searchTrees(segmentTree4Head, head.left -> position);
     int node7Value = searchTrees(segmentTree7Head, head.right -> position);
     int leftValue = head.left -> value;
     int rightValue = head.right -> value;
     head.value = max(max((head.left -> value + node4Value),(node7Value + node4Value)),(node7Value + head.right -> value));
     return head;
  }

int searchTrees(Node head, int position)
{
    int value = -1;
    if(head.position == position)
    {
        return head.value;
    }
    if(head.left != NULL)
    {
        value = searchTrees(head.left, position);
        if(value != -1)
        {
            return value;
        }
    }
    if(head.right != NULL)
    {
        value = searchTrees(head.right, position);
        if(value != -1)
        {
            return value;
        }
    }
    return value;
}

Node searchTreeNodes(Node head, int position)
{
    Node treeNode = NULL;
    if(head.position == position)
    {
        return head;
    }
    if(head.left != NULL)
    {
        treeNode = searchTreeNodes(head.left, position);
        if(treeNode != NULL)
        {
            return treeNode;
        }
    }
    if(head.right != NULL)
    {
        treeNode = searchTreeNodes(head.right, position);
        if(treeNode != NULL)
        {
            return treeNode;
        }
    }
    return treeNode;
}

int main()
{
    int stringLength, numberOfQueries;
    string input;
    cin >> stringLength >> numberOfQueries;
    int *inputDigits = new int[stringLength];
    for(int i = 0; i < stringLength; i++)
    {
        cin >> inputDigits[i];
    }
    segmentTree4Head.value = 0;
    segmentTree4Head.left = NULL;
    segmentTree4Head.right = NULL;
    segmentTree7Head.value = 0;
    segmentTree7Head.left = NULL;
    segmentTree7Head.right = NULL;
    segmentTree47Head.value = 0;
    segmentTree47Head.left = NULL;
    segmentTree47Head.right = NULL;
    segmentTree74Head.value = 0;
    segmentTree74Head.left = NULL;
    segmentTree74Head.right = NULL;
    buildSegmentTree4(inputDigits, segmentTree4Head, 0, stringLength - 1, 0);
    buildSegmentTree7(inputDigits, segmnetTree7Head, 0, stringLength - 1, 0);
    buildSegmentTree47(inputDigits, segmentTree47Head, 0, stringLength - 1, 0);
    buildSegmnetTree74(inputDigits, segmnetTree74Head, 0, stringLength - 1, 0);
    for(int j = 0; j < numberOfQueries; j++)
    {
        string query;
        cin >> query;
        if (query.compare("count") == 0)
        {
            cout << segmentTree47Head.value << endl;
        }
        else
        {
            int lowerIndex, upperIndex;
            cin >> lowerIndex >> upperIndex;
            updateSegmentTrees(lowerIndex, upperIndex, stringLength);
        }
    }
}
