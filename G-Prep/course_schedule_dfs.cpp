class Comparator
{
	public:
		bool operator()(const pair< int, int > pair_1, const pair< int, int > pair_2) const
		{
			if(pair_1.second < pair_2.second)
			{
				return true;
			}
			return false;
		}
};

class Solution 
{
	public:
		int find_parent(int a, vector< int > &parents)
		{
			if(parents[a] == a)
			{
				return a;
			}
			int parent = find_parent(parents[a], parents);
			parents[a] = parent;
			return parent;
		}

		bool union_find(int course, int prerequisite, vector< int > &parents)
		{
            
			int parent_course = find_parent(course, parents);
			int parent_prerequisite = find_parent(prerequisite, parents);
            // cout << "Course: " << course << ":" << parent_course << " PreReq: " << prerequisite << ":" << parent_prerequisite << "\n";
			if(parent_course != parent_prerequisite)
			{
				parents[course] = parent_prerequisite;
				return false;
			}
			else
			{
				return true;
			}
		}

	    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
	    {
			vector< int > parents(numCourses);
			iota(parents.begin(), parents.end(), 0);
			vector< vector< int > > children(numCourses);
			vector< pair< int, int > > weights;
			for(int i = 0; i < numCourses; i++)
			{
				weights.push_back(make_pair(i, 1));
			}
			bool is_cycle = false;
			for(int i = 0; i < prerequisites.size(); i++)
			{
				int course = prerequisites[i][0];
				int prerequisite = prerequisites[i][1];
				is_cycle = union_find(course, prerequisite, parents);
				if(is_cycle)
				{
					break;
				}
				children[prerequisite].push_back(course);
				weights[prerequisite].second += weights[course].second;
			}
			vector< int > solution;
			if(is_cycle)
			{
				return solution;
			}
			priority_queue< pair< int, int >, vector< pair< int, int > >, Comparator > pq(weights.begin(), weights.end());
			int visited_nodes_count = 0;
			vector< bool > visited(numCourses);
			while(not pq.empty())
			{
				pair< int, int > top_pair = pq.top();
				pq.pop();
				visited[top_pair.first] = true;
				solution.push_back(top_pair.first);
			}
			for(int i = 0; i < numCourses; i++)
			{
				if(not visited[i])
				{
					solution.push_back(i);
				}
			}
			return solution;
	    }
};