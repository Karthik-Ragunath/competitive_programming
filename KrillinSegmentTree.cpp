#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class SegmentTreeNode
{
    public:
        ll mode;
        ll frequency;
        ll median;
};

ll binarySearchIndex(ll index, vector< ll > &prevCumFreq, vector< ll > &values, ll low, ll high)
{
    ll mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        ll leftNow = prevCumFreq[mid] + 1;
        ll rightNow = prevCumFreq[mid] + values[mid];
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

SegmentTreeNode buildSegmentTree(vector< ll > &values, ll low, ll high, ll index, vector< SegmentTreeNode > &segmentTreeNode, vector< ll > &prevCumFreq, ll N)
{
    if(low == high)
    {
        segmentTreeNode[index].mode = low;
        segmentTreeNode[index].frequency = values[low];
        segmentTreeNode[index].median = low;
        return segmentTreeNode[index];
    }
    ll mid = (low + high) / 2;
    SegmentTreeNode leftNode = buildSegmentTree(values, low, mid, 2 * index + 1, segmentTreeNode, prevCumFreq, N);
    SegmentTreeNode rightNode = buildSegmentTree(values, mid + 1, high, 2 * index + 2, segmentTreeNode, prevCumFreq, N);
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
    ll median = prevCumFreq[high] + values[high] - prevCumFreq[low];
    if(median % 2 == 0)
    {
        ll median1 = prevCumFreq[low] + (median / 2);
        ll median2 = prevCumFreq[low] + (median / 2) + 1;
        ll median = (median1 + median2) / 2;
        ll rangeIndexValue = binarySearchIndex(median, prevCumFreq, values, 0, N - 1);
        segmentTreeNode[index].median = rangeIndexValue;
    }
    else
    {
        ll median = (median + 1) / 2 + prevCumFreq[low];
        ll rangeIndexValue = binarySearchIndex(median, prevCumFreq, values, 0, N - 1);
        segmentTreeNode[index].median = rangeIndexValue;
    }
    return segmentTreeNode[index];
}

SegmentTreeNode updateSegmentTree(vector< ll > &values, ll low, ll high, ll index, vector< SegmentTreeNode > &segmentTreeNode, vector< ll > &prevCumFreq, ll position, ll positionValue, ll N)
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
        segmentTreeNode[index].median = low;
        return segmentTreeNode[index];
    }
    ll mid = (low + high) / 2;
    SegmentTreeNode left = updateSegmentTree(values, low, mid, 2 * index + 1, segmentTreeNode, prevCumFreq, position, positionValue, N);
    SegmentTreeNode right = updateSegmentTree(values, mid + 1, high, 2 * index + 2, segmentTreeNode, prevCumFreq, position, positionValue, N);
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
    ll median = prevCumFreq[high] + values[high] - prevCumFreq[low];
    if(median % 2 == 0)
    {
        ll median1 = prevCumFreq[low] + (median / 2);
        ll median2 = prevCumFreq[low] + (median / 2) + 1;
        ll median = (median1 + median2) / 2;
        ll rangeIndexValue = binarySearchIndex(median, prevCumFreq, values, 0, N - 1);
        segmentTreeNode[index].median = rangeIndexValue;
    }
    else
    {
        ll median = (median + 1) / 2 + prevCumFreq[low];
        ll rangeIndexValue = binarySearchIndex(median, prevCumFreq, values, 0, N - 1);
        segmentTreeNode[index].median = rangeIndexValue;
    }
    return segmentTreeNode[index];
}

SegmentTreeNode returnRange(vector< ll > &values, ll low, ll high, ll index, vector< SegmentTreeNode > &segmentTreeNode, vector< ll > &prevCumFreq, ll left, ll right, ll N)
{
    if(left > high || right < low)
    {
        SegmentTreeNode node;
        node.mode = -1;
        node.frequency = -1;
        node.median = -1;
        return node;
    }
    if(left <= low && right >= high)
    {
        return segmentTreeNode[index];
    }
    ll mid = (low + high) / 2;
    SegmentTreeNode leftNode = returnRange(values, low, mid, 2 * index + 1, segmentTreeNode, prevCumFreq, left, right, N);
    SegmentTreeNode rightNode = returnRange(values, mid + 1, high, 2 * index + 2, segmentTreeNode, prevCumFreq, left, right, N);
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
    ll leftValue = (left > low) ? left : low;
    ll rightValue = (right < high) ? right : high;
    ll median = prevCumFreq[rightValue] + values[rightValue] - prevCumFreq[leftValue];
    if(median % 2 == 0)
    {
        ll median1 = prevCumFreq[leftValue] + (median / 2);
        ll median2 = prevCumFreq[leftValue] + (median / 2) + 1;
        ll median = (median1 + median2) / 2;
        ll rangeIndexValue = binarySearchIndex(median, prevCumFreq, values, 0, N - 1);
        returnNode.median = rangeIndexValue;
    }
    else
    {
        ll median = (median + 1) / 2 + prevCumFreq[leftValue];
        ll rangeIndexValue = binarySearchIndex(median, prevCumFreq, values, 0, N - 1);
        returnNode.median = rangeIndexValue;
    }
    return returnNode;
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
        cout << "Median: " << segmentTreeNode[i].median << endl;
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
        vector< ll > prevCumFreq(N);
        vector< SegmentTreeNode > segmentTreeNode(2 * N);
        ll previousCumulativeFrequency = 0;
        for(ll j = 0; j < N; j++)
        {
            cin >> values[j];
            prevCumFreq[j] = previousCumulativeFrequency;
            previousCumulativeFrequency += values[j];
        }
        SegmentTreeNode rootNode = buildSegmentTree(values, 0, N - 1, 0, segmentTreeNode, prevCumFreq, N);
        for(ll j = 0; j < queries; j++)
        {
            ll queryType;
            cin >> queryType;
            if(queryType == 1)
            {
                ll startIndex, endIndex;
                cin >> startIndex >> endIndex;
                SegmentTreeNode node = returnRange(values, 0, N - 1, 0, segmentTreeNode, prevCumFreq, startIndex, endIndex, N);
                printDetails(values, segmentTreeNode, N);
                cout << node.mode << " " << node.median << endl;
            }
            else
            {
                ll index, value;
                cin >> index >> value;
                SegmentTreeNode node = updateSegmentTree(values, 0, N - 1, 0, segmentTreeNode, prevCumFreq, index - 1, value, N);
            }
        }
    }
    return 0;
}
