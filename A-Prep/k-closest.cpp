// https://leetcode.com/problems/k-closest-points-to-origin/
class PointsComparator
{
	public:
		bool operator()(const pair< int, int > &point_1, const pair< int, int > &point_2) const
		{
			if(point_1.first < point_2.first)
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
    	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    	{
    		int points_vec_size = points.size();
    		if(points_vec_size <= K)
    		{
    			return points;
    		}
        	multiset< pair< int, int >, PointsComparator > min_elements_set;
        	for(int i = 0; i < points_vec_size; i++)
        	{
        		int distance_val = pow(abs(points[i][0]), 2) + pow(abs(points[i][1]), 2);
	        	if(min_elements_set.size() < K)
	        	{
	        		min_elements_set.insert(make_pair(distance_val, i));
	        	}
	        	else
	        	{
	        		int last_value = prev(min_elements_set.end()) -> first;
	        		if(distance_val < last_value)
	        		{
	        			// cout << "erase and append" << "\n";
	        			min_elements_set.erase(--min_elements_set.end());
	        			min_elements_set.insert(make_pair(distance_val, i));
	        		}
	        	}
        	}
        	vector< vector< int > > solution_vec;
        	for(auto iter = min_elements_set.begin(); iter != min_elements_set.end(); iter++)
        	{
        		int index = iter -> second;
        		solution_vec.push_back(points[index]);
        	}
        	return solution_vec;
    	}
};