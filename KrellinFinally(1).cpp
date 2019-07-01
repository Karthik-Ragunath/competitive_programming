#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class SegmentTreeNode
{
    public:
        ll mode;
        ll frequency;
};

ll gcd(ll a, ll b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    ll multiple = (a * b);
    // a * b = lcm(a, b) * gcd(a, b);
    ll gcdValue = gcd(a, b);
    ll lcmValue = multiple / gcdValue;
    return lcmValue;
}

SegmentTreeNode buildSegmentTree(vector< ll > &values, ll low, ll high, ll index, vector< SegmentTreeNode > &segmentTreeNode)
{
    if(low == high)
    {
        segmentTreeNode[index].mode = low;
        segmentTreeNode[index].frequency = values[low];
        return segmentTreeNode[index];
    }
    ll mid = (low + high) / 2;
    SegmentTreeNode leftNode = buildSegmentTree(values, low, mid, 2 * index + 1, segmentTreeNode);
    SegmentTreeNode rightNode = buildSegmentTree(values, mid + 1, high, 2 * index + 2, segmentTreeNode);
    if(leftNode.frequency >= rightNode.frequency)
    {
        segmentTreeNode[index].mode = leftNode.mode;
        segmentTreeNode[index].frequency = leftNode.frequency;
    }
    else
    {
        segmentTreeNode[index].mode = rightNode.mode;
        segmentTreeNode[index].frequency = rightNode.frequency;
    }
    return segmentTreeNode[index];
}

ll buildRangeSegmentTree(vector< ll > &values, ll low, ll high, ll index, vector< ll > &rangeSumSegmentTree)
{
    if(low == high)
    {
        rangeSumSegmentTree[index] = values[low];
        return rangeSumSegmentTree[index];
    }
    ll mid = (low + high) / 2;
    ll leftTreeSum = buildRangeSegmentTree(values, low, mid, 2 * index + 1, rangeSumSegmentTree);
    ll rightTreeSum = buildRangeSegmentTree(values, mid + 1, high, 2 * index + 2, rangeSumSegmentTree);
    rangeSumSegmentTree[index] = leftTreeSum + rightTreeSum;
    return rangeSumSegmentTree[index];
}

SegmentTreeNode updateSegmentTree(vector< ll > &values, ll low, ll high, ll index, vector< SegmentTreeNode > &segmentTreeNode, ll position, ll positionValue)
{
    if(low > position || high < position)
    {
        return segmentTreeNode[index];
    }
    if(low == high)
    {
        values[low] = positionValue;
        segmentTreeNode[index].mode = low;
        segmentTreeNode[index].frequency = positionValue;
        return segmentTreeNode[index];
    }
    ll mid = (low + high) / 2;
    SegmentTreeNode left = updateSegmentTree(values, low, mid, 2 * index + 1, segmentTreeNode, position, positionValue);
    SegmentTreeNode right = updateSegmentTree(values, mid + 1, high, 2 * index + 2, segmentTreeNode, position, positionValue);
    if(left.frequency >= right.frequency)
    {
        segmentTreeNode[index].mode = left.mode;
        segmentTreeNode[index].frequency = left.frequency;
    }
    else
    {
        segmentTreeNode[index].mode = right.mode;
        segmentTreeNode[index].frequency = right.frequency;
    }
    return segmentTreeNode[index];
}

ll updateRangeSumSegmentTree(vector< ll > &values, ll low, ll high, ll index, vector< ll > &rangeSumSegmentTree, ll position, ll positionValue)
{
    if(low > position || high < position)
    {
        return rangeSumSegmentTree[index];
    }
    if(low == high)
    {
        values[low] = positionValue;
        rangeSumSegmentTree[index] = values[low];
        return rangeSumSegmentTree[index];
    }
    ll mid = (low + high) / 2;
    ll leftTreeSum = updateRangeSumSegmentTree(values, low, mid, 2 * index + 1, rangeSumSegmentTree, position, positionValue);
    ll rightTreeSum = updateRangeSumSegmentTree(values, mid + 1, high, 2 * index + 2, rangeSumSegmentTree, position, positionValue);
    rangeSumSegmentTree[index] = leftTreeSum + rightTreeSum;
    return rangeSumSegmentTree[index];
}

SegmentTreeNode returnRange(vector< ll > &values, ll low, ll high, ll index, vector< SegmentTreeNode > &segmentTreeNode, ll left, ll right)
{
    if(left > high || right < low)
    {
        SegmentTreeNode node;
        node.mode = -1;
        node.frequency = -1;
        return node;
    }
    if(left <= low && right >= high)
    {
        return segmentTreeNode[index];
    }
    ll mid = (low + high) / 2;
    SegmentTreeNode leftNode = returnRange(values, low, mid, 2 * index + 1, segmentTreeNode, left, right);
    SegmentTreeNode rightNode = returnRange(values, mid + 1, high, 2 * index + 2, segmentTreeNode, left, right);
    if(leftNode.mode == -1)
    {
        return rightNode;
    }
    if(rightNode.mode == -1)
    {
        return leftNode;
    }
    SegmentTreeNode returnNode;
    if(leftNode.frequency >= rightNode.frequency)
    {
        returnNode.mode = leftNode.mode;
        returnNode.frequency = leftNode.frequency;
    }
    else
    {
        returnNode.mode = rightNode.mode;
        returnNode.frequency = rightNode.frequency;
    }
    return returnNode;
}

ll returnRangeSegmentTreeSum(vector< ll > &values, ll low, ll high, ll index, vector< ll > &rangeSumSegmentTree, ll left, ll right)
{
    if(left > high || right < low)
    {
        return 0;
    }
    if(left <= low & right >= high)
    {
        return rangeSumSegmentTree[index];
    }
    ll mid = (low + high) / 2;
    ll leftTreeSum = returnRangeSegmentTreeSum(values, low, mid, 2 * index + 1, rangeSumSegmentTree, left, right);
    ll rightTreeSum = returnRangeSegmentTreeSum(values, mid + 1, high, 2 * index + 2, rangeSumSegmentTree, left, right);
    ll totalSum = leftTreeSum + rightTreeSum;
    return totalSum;
}

ll binarySearchIndex(ll index, vector< ll > &values, ll low, ll high, vector< ll > &rangeSumSegmentTree, ll N)
{
    ll mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        ll midSum = returnRangeSegmentTreeSum(values, 0, N - 1, 0, rangeSumSegmentTree, 0, mid);
        ll leftNow = midSum - values[mid] + 1;
        ll rightNow = midSum;
        if(leftNow <= index && rightNow >= index)
        {
            break;
        }
        if(leftNow > index)
        {
            high = mid - 1;
            continue;
        }
        if(rightNow < index)
        {
            low = mid + 1;
            continue;
        }
    }
    return mid;
}

ll returnMedianValue(vector< ll > &values, ll low, ll high, ll N, vector< ll > &rangeSumSegmentTree)
{
    ll leftSum = returnRangeSegmentTreeSum(values, 0, N - 1, 0, rangeSumSegmentTree, 0, low);
    ll rightSum = returnRangeSegmentTreeSum(values, 0, N - 1, 0, rangeSumSegmentTree, 0, high);
    // cout << "LeftSum: " << leftSum << " RightSum: " << rightSum << endl;
    ll cumFreqLowPrev = (leftSum - values[low]);
    ll median = rightSum - cumFreqLowPrev;
    ll rangeIndexValue = 0;
    if(median % 2 == 0)
    {
        ll median1 = cumFreqLowPrev + (median / 2);
        ll median2 = cumFreqLowPrev + (median / 2) + 1;
        ll medianNow = (median1 + median2) / 2;
        rangeIndexValue = binarySearchIndex(medianNow, values, 0, N - 1, rangeSumSegmentTree, N);
    }
    else
    {
        ll medianNow = (median + 1) / 2 + cumFreqLowPrev;
        rangeIndexValue = binarySearchIndex(medianNow, values, 0, N - 1, rangeSumSegmentTree, N);
    }
    return rangeIndexValue;
}

void printDetails(vector< ll > &values, vector< SegmentTreeNode > &segmentTreeNode, ll N)
{
    cout << "*-----Details-----*" << endl;
    cout << "N: " << N << endl;
    for(ll i = 0; i < 2 * N; i++)
    {
        cout << "----" << endl;
        cout << "SegmentTreeIndex: " << i << endl;
        cout << "Mode: " << segmentTreeNode[i].mode << endl;
        cout << "Freq: " << segmentTreeNode[i].frequency << endl;
        cout << "----" << endl;
    }
    cout << "--------" << endl;
    cout << "*-----Details-----*" << endl;
}

int main()
{
    ll testcases;
    cin >> testcases;
    for(ll i = 0; i < testcases; i++)
    {
        ll N, queries;
        cin >> N >> queries;
        vector< ll > values(N);
        vector< SegmentTreeNode > segmentTreeNode(4 * N);
        vector< ll > rangeSumSegmentTree(4 * N);
        ll previousCumulativeFrequency = 0;
        for(ll j = 0; j < N; j++)
        {
            cin >> values[j];
        }
        SegmentTreeNode rootNode = buildSegmentTree(values, 0, N - 1, 0, segmentTreeNode);
        ll rootNodeSum = buildRangeSegmentTree(values, 0, N - 1, 0, rangeSumSegmentTree);
        for(ll j = 0; j < queries; j++)
        {
            ll queryType;
            cin >> queryType;
            if(queryType == 1)
            {
                ll startIndex, endIndex;
                cin >> startIndex >> endIndex;
                SegmentTreeNode node = returnRange(values, 0, N - 1, 0, segmentTreeNode, startIndex - 1, endIndex - 1);
                //printDetails(values, segmentTreeNode, N);
                ll median = returnMedianValue(values, startIndex - 1, endIndex - 1, N, rangeSumSegmentTree);
                // cout << node.mode << " " << median << endl;
                ll lcmValue = lcm(node.mode + 1, median + 1);
                cout << lcmValue << endl;
            }
            else
            {
                ll index, value;
                cin >> index >> value;
                ll updatedRootSum = updateRangeSumSegmentTree(values, 0, N - 1, 0, rangeSumSegmentTree, index - 1, value);
                SegmentTreeNode node = updateSegmentTree(values, 0, N - 1, 0, segmentTreeNode, index - 1, value);
            }
        }
    }
    return 0;
}
