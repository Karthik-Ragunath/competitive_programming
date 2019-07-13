#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Comparator
{
	public:
		bool operator()(const vector< int > &vec_1, const vector< int > &vec_2) const
		{
			if(vec_1[0] < vec_2[0])
			{
				return true;
			}
			else if(vec_1[0] == vec_2[0])
			{
				if(vec_1[1] < vec_2[1])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
};

class Compare_PQ
{
	public:
		bool operator()(const int val_1, const int val_2) const
		{
			if(val_1 > val_2) // bcoz default is <, we must do inverse, quite awkward
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class Solution 
{
	public:
    	int minMeetingRooms(vector<vector<int>>& intervals) 
    	{
        	sort(intervals.begin(), intervals.end(), Comparator());
        	priority_queue< int, vector< int >, Compare_PQ > pq_rooms;
        	for(auto iter = intervals.begin(); iter != intervals.end(); iter++)
        	{
        		// if(!pq_rooms.empty())
        		// {
        		// 	cout << pq_rooms.top() << " " << (*iter)[1] << "\n";
        		// }
        		if(!pq_rooms.empty() and (*iter)[0] >= pq_rooms.top())
        		{
        			// cout << "milestome1" << "\n";
        			pq_rooms.pop();
        			pq_rooms.push((*iter)[1]);
        		}
        		else
        		{
        			// cout << "pushed alone: " << (*iter)[1] << "\n";
        			pq_rooms.push((*iter)[1]);
        		}
        	}
        	return pq_rooms.size();
    	}
};

int main()
{
	vector< vector< int > > intervals {{0, 30}, {5, 10}, {15, 20}};
	Solution solution;
	int min_rooms_req = solution.minMeetingRooms(intervals);
	cout << min_rooms_req << "\n";
	return 0;
}