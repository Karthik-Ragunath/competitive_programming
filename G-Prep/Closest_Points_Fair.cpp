// https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/
// https://www.topcoder.com/community/competitive-programming/tutorials/line-sweep-algorithms/
// http://olympiad.cs.uct.ac.za/presentations/camp1_2009/linesweep_handout.pdf (important)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class CompareVector
{
	public:
		bool operator()(const pair< double, double > &pair_1, const pair< double, double > &pair_2) const
		{
			return pair_1.first < pair_2.first;
		}
};

double closest_points_distance(vector< pair< double, double > > &input_points)
{
	vector< pair< double, double > > new_points(input_points);
	sort(input_points.begin(), input_points.end(), CompareVector());
	set< pair< ll, ll > > bounding_box;
	bounding_box.insert(input_points[0]);
	double min_distance = 10000000000000;
	for(int i = 1; i < input_points.size(); i++)
	{
		int left = 0;
		for(auto iter = new_points.begin(); iter != new_points.end() and left < i; left++)
		{
			if(iter -> first + min_distance < input_points[i].first)
			{
				bounding_box.erase(*iter);
				new_points.erase(iter); //erase a non existing value in set doesnt throw an error in sets
			}
			else
			{
				break;
			}
			left += 1;
		}
		for(auto iter = bounding_box.lower_bound(make_pair(input_points[i].first - min_distance, input_points[i].second - min_distance)); iter != bounding_box.end() and (input_points[i].second + min_distance >= iter -> second); iter++)
		{
			min_distance = min(min_distance, sqrt(pow(input_points[i].first - iter -> first, 2) + pow(input_points[i].second - iter -> second, 2)));
		}
		bounding_box.insert(input_points[i]);
	}
	return min_distance;
}

int main()
{
	// vector< pair< double, double > > input_points{make_pair(2, 3), make_pair(12, 30), make_pair(40, 50), make_pair(5, 1), make_pair(12, 10), make_pair(3, 4)};
	vector< pair< double, double > > input_points{make_pair(12, 13), make_pair(12, 30), make_pair(18, 16), make_pair(20, 13), make_pair(24, 25), make_pair(8, 7)};
	double min_distance = closest_points_distance(input_points);
	cout << min_distance << "\n";
	return 0;
}