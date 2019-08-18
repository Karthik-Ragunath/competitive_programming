class MaxPriorityQueueComparator
{
	public:
		bool operator()(const pair< int, int > pair_1, const pair< int, int > pair_2) const
		{
			if(pair_1.second < pair_2.second)
			{
				return true;
			}
            else if(pair_1.second == pair_2.second and pair_1.first > pair_2.first)
            {
                return true;
            }
            else
            {
                return false;
            }
			return false;
		}
};

class MinSetComparator
{
	public:
		bool operator()(const pair< int, int > pair_1, const pair< int, int > pair_2) const
		{
			if(pair_1.second < pair_2.second)
			{
				return true;
			}
            else if(pair_1.second == pair_2.second and pair_1.first < pair_2.first)
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
			vector< vector< int > > children(numCourses);
			vector< pair< int, int > > indegree;
			for(int i = 0; i < numCourses; i++)
			{
				indegree.push_back(make_pair(i, 0));
			}
			for(int i = 0; i < prerequisites.size(); i++)
			{
				int course = prerequisites[i][0];
				int prerequisite = prerequisites[i][1];
				children[prerequisite].push_back(course);
				indegree[course].second += 1;
			}
			vector< int > solution;
			// priority_queue< pair< int, int >, vector< pair< int, int > >, PriorityQueueComparator > pq(indegree.begin(), indegree.end());
			set< pair< int, int >, MinSetComparator > bst(indegree.begin(), indegree.end());
			/*
			set< pair< int, int >, MinSetComparator > bst;
            for(int i = 0; i < numCourses; i++)
            {
                bst.insert(indegree[i]);
            }
            */
			int visited_nodes_count = 0;
			vector< bool > visited(numCourses);
			vector< int > popped_elements;
            bool is_begin = true;
			while(not bst.empty() and (not popped_elements.empty() or is_begin))
			{
                is_begin = false;
				for(auto iter = popped_elements.begin(); iter != popped_elements.end();)
				{
					int parent_index = *iter;
                    // cout << "Parent Value: " << parent_index << "\n";
					for(auto child: children[parent_index])
					{
                        
						auto find_iter = bst.find(make_pair(child, indegree[child].second));
                        // cout << "Child: " << child << " Child Value: " << find_iter -> second << " " << "Indeg: " << indegree[child].second << "\n";
						int child_value = find_iter -> second;
						bst.erase(find_iter);
						bst.insert(make_pair(child, child_value - 1));
                        indegree[child].second = child_value - 1;
					}
					iter = popped_elements.erase(iter);
				}
                // cout << "Popped elements size: " << popped_elements.size() << "\n";
				while(not bst.empty())
				{
					pair< int, int > top_pair = *(bst.begin());
					if(top_pair.second == 0)
					{
                        // cout << top_pair.first << " " << top_pair.second << "\n";
						popped_elements.push_back(top_pair.first);
						bst.erase(bst.begin());
						visited[top_pair.first] = true;
						solution.push_back(top_pair.first);
					}
					else
					{
						break;
					}
				}
			}
            return solution.size() == numCourses ? solution : vector< int >{};
	    }
};