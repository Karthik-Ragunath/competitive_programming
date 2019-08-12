#include <bits/stdc++.h>
using namespace std;
#define ll long long 

class CompareMinHeapsPair
{
	public:
		bool operator()(const pair< ll, pair< ll, ll > > &pair_1, const pair< ll, pair< ll, ll > > &pair_2) const
		{
			if(pair_1.second.first > pair_2.second.first)
			{
				return true;
			}
			else
			{
				if(pair_1.second.first == pair_2.second.first and pair_1.second.second > pair_2.second.second)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
};

class CompareSetsMaxY
{
	public:
		bool operator()(const pair< ll, pair< ll, ll > > &pair_1, const pair< ll, pair< ll, ll > > &pair_2) const
		{
			if(pair_1.second.second < pair_2.second.second)
			{
				return true;
			}
			else
			{
				if(pair_1.second.second == pair_2.second.second and pair_1.second.first > pair_2.second.second)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
};

bool does_lie_on_segment(pair< ll, ll > point_1, pair< ll, ll > point_2, pair< ll, ll > point_3)
{
	if(point_3.first <= max(point_1.first, point_2.first) and point_3.first >= min(point_1.first, point_2.first) and point_3.second <= max(point_1.second, point_2.second) and point_3.second >= min(point_1.second, point_2.second))
	{
		return true;
	}
	return false;
}

ll orientation(pair< ll, ll > point_1, pair< ll, ll > point_2, pair< ll, ll > point_3)
{
	// > 0 - clockwise, < 0 - anticlockwise, == 0 - colinear
	return (point_2.second - point_1.second) * (point_3.first - point_2.first) - (point_2.first - point_1.first) * (point_3.second - point_2.second); 
}

bool does_lines_intersect(pair< pair< ll, ll >, pair< ll, ll > > line_1, pair< pair< ll, ll >, pair< ll, ll > > line_2)
{
	pair< ll, ll > p1 = line_1.first;
	pair< ll, ll > q1 = line_1.second;
	pair< ll, ll > p2 = line_2.first;
	pair< ll, ll > q2 = line_2.second;
	ll orientation_1 = orientation(p1, q1, p2);
	ll orientation_2 = orientation(p1, q1, q2);
	ll orientation_3 = orientation(p2, q2, p1);
	ll orientation_4 = orientation(p2, q2, q1);
	if(orientation_1 != orientation_2 and orientation_3 != orientation_4)
	{
		return true;
	}
	if(orientation_1 == 0 and does_lie_on_segment(p1, q1, p2))
	{
		return true;
	}
	if(orientation_2 == 0 and does_lie_on_segment(p1, q1, q2))
	{
		return true;
	}
	if(orientation_3 == 0 and does_lie_on_segment(p2, q2, p1))
	{
		return true;
	}
	if(orientation_4 == 0 and does_lie_on_segment(p2, q2, q1))
	{
		return true;
	}
	return false;
}

vector< pair< ll, ll > > find_intersections(vector< pair< pair< ll, ll >, pair< ll, ll > > > &line_pairs)
{
	vector< pair< ll, ll > > solution_vec;
	vector< pair< ll, pair< ll, ll > > > vector_pair_points;
	ll index = 0;
	for(auto pairs: line_pairs)
	{
		vector_pair_points.push_back(make_pair(index, make_pair(pairs.first.first, pairs.first.second)));
		vector_pair_points.push_back(make_pair(index, make_pair(pairs.second.first, pairs.second.second)));
		index++;
	}
	priority_queue< pair< ll, pair< ll, ll > >, vector< pair< ll, pair< ll, ll > > >, CompareMinHeapsPair > points_process_order(vector_pair_points.begin(), vector_pair_points.end());
	// pair< ll, pair< ll, ll > > pair_head_test = points_process_order.top();
	// cout << pair_head_test.first << " " << pair_head_test.second.first << " " << pair_head_test.second.second << "\n";
	unordered_map< ll, pair< ll, ll > > visited;
	set< pair< ll, pair< ll, ll > >, CompareSetsMaxY > balanced_tree_y_sorted;
	while(not points_process_order.empty())
	{
		pair< ll, pair< ll, ll > > priority_pair = points_process_order.top();
		points_process_order.pop();
		if(visited.find(priority_pair.first) != visited.end())
		{
			pair< ll, pair< ll, ll > > pair_to_be_removed = make_pair(priority_pair.first, visited[priority_pair.first]);
			/* distance is O(n)
			int distance_from_start = distance(balanced_tree_y_sorted.begin(), balanced_tree_y_sorted.find(priority_pair));
			int distance_to_end = distance(balanced_tree_y_sorted.find(priority_pair) - balanced_tree_y_sorted.end()) - 1;
			if(distance_from_start >= 1 and distance_to_end >= 1) 
			{
				//check whether above and below given lines intersect
			}
			*/
			if(pair_to_be_removed != *balanced_tree_y_sorted.begin() and pair_to_be_removed != *balanced_tree_y_sorted.rbegin())
			{
				//check whether above and below given lines intersect
				auto find_iter = balanced_tree_y_sorted.find(pair_to_be_removed);
				auto find_iter_new = balanced_tree_y_sorted.find(pair_to_be_removed);
				--find_iter;
				++find_iter_new;
				pair< pair< ll, ll >, pair< ll, ll > > prev_line = line_pairs[find_iter -> first];
				pair< pair< ll, ll >, pair< ll, ll > > next_line = line_pairs[find_iter_new -> first];
				bool does_intersect = does_lines_intersect(prev_line, next_line);
				if(does_intersect)
				{
					solution_vec.emplace_back(find_iter -> first, find_iter_new -> first);
				}
			}
			balanced_tree_y_sorted.erase(pair_to_be_removed); 
		}
		else
		{
			visited[priority_pair.first] = priority_pair.second;
			balanced_tree_y_sorted.insert(priority_pair);
			if(priority_pair != *balanced_tree_y_sorted.begin())
			{
				// check whether priority pair line and above lying line intersect
				auto find_iter = balanced_tree_y_sorted.find(priority_pair);
				pair< pair< ll, ll >, pair< ll, ll > > line_pair_1 = line_pairs[priority_pair.first];
				--find_iter;
				pair< pair< ll, ll >, pair< ll, ll > > line_pair_2 = line_pairs[find_iter -> first];
				bool does_intersect = does_lines_intersect(line_pair_2, line_pair_1);
				if(does_intersect)
				{
					solution_vec.emplace_back(find_iter -> first, priority_pair.first);
				}
			}
			if(priority_pair != *balanced_tree_y_sorted.rbegin())
			{
				// check whether priority pair line and below lying line intersect
				auto find_iter = balanced_tree_y_sorted.find(priority_pair);
				pair< pair< ll, ll >, pair< ll, ll > > line_pair_1 = line_pairs[priority_pair.first];
				++find_iter;
				pair< pair< ll, ll >, pair< ll, ll > > line_pair_2 = line_pairs[find_iter -> first];
				bool does_intersect = does_lines_intersect(line_pair_1, line_pair_2);
				if(does_intersect)
				{
					solution_vec.emplace_back(priority_pair.first, find_iter -> first);
				}
			}
		}
	} 
	return solution_vec;
}

void print_vec_pair(vector< pair< ll, ll > > &intersections)
{
	for(auto pair_val: intersections)
	{
		cout << pair_val.first << " " << pair_val.second << "\n";
	}
}

int main()
{
	vector< pair< pair< ll, ll >, pair< ll, ll > > > line_segment_pairs{make_pair(make_pair(6,1), make_pair(10,10)), make_pair(make_pair(1,5), make_pair(5,1)), make_pair(make_pair(6,10), make_pair(10, 1)), make_pair(make_pair(1,1), make_pair(5,5))};
	vector< pair< ll, ll > > intersections = find_intersections(line_segment_pairs);
	print_vec_pair(intersections);
	return 0;
}