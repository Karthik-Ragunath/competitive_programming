// https://www.codechef.com/problems/TALCA
// https://s3.amazonaws.com/codechef_shared/download/Solutions/LTIME14/Tester/TALCA.cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(vector< bool > &visited, vector< int > &levels, vector< int > &parents, vector< vector< int > > &adjacent_mat, int current_level, int current_node, int parent, int &max_level)
{
	if(current_level > max_level)
	{
		max_level = current_level;
	}
	levels[current_node] = current_level;
	parents[current_node] = parent;
	visited[current_node] = true;
	for(auto child_node: adjacent_mat[current_node])
	{
		if(not visited[child_node])
		{
			dfs(visited, levels, parents, adjacent_mat, current_level + 1, child_node, current_node, max_level);
		}
	}
}

int lca(vector< vector< int > > jump_levels, vector< int > &levels, int q1, int q2)
{
	if(q1 == q2)
	{
		return q1;
	}
	if(levels[q1] < levels[q2])
	{
		int temp = q1;
		q1 = q2;
		q2 = temp;
	}
	int log = 1;
	for(; (levels[q1] - (1 << log)) >= levels[q2]; log++); //log value will always be one level higher
	log--;
	q1 = jump_levels[q1][log];
	if(q1 == q2)
	{
		return q1;
	}
	int log = 1;
	for(; (1 << log) <= levels[q1]; log++);
	log -= 1;
	for(int i = log; i >= 0; i--)
	{
		if(jump_levels[q1][log] != -1 and (jump_levels[q1][i] != jump_levels[q2][i]))
		{
			q1 = jump_levels[q1][i];
			q2 = jump_levels[q2][i];
		}
	}
	return parents[q1];
}

vector< vector< int > > set_levels(vector< vector< int > > &adjacent_mat, vector< int > &parents, int max_level, int nodes_count)
{
	int log = 1;
	for(; (1 << log) <= max_level; log++); //log value will always be on eval higher - log - 1, max_level - 0 -> (1 << 0) <= 0 -> 1 <= 0; 1--
	log -= 1;
	vector< vector< int > > jump_levels(nodes_count + 1, vector< int >(log + 1));
	for(int i = 1; i <= nodes_count; i++)
	{
		for(int j = 0; j <= log; j++)
		{
			if(j = 0)
			{
				jump_levels[i][j] = parents[i];
			}
			else
			{
				if(jump_levels[i])
				jump_levels[i][j] = jump_levels[jump_levels[i][j - 1]][j - 1];
			}
		}
	}
	return jump_levels;
}

int main()
{
	int nodes_count, edges_count;
	cin >> nodes_count >> queries;
	vector< vector< int > > adjacent_mat(nodes_count + 1);
	vector< pair< int, int > > query_pair;
	for(int i = 0; i < nodes_count - 1; i++)
	{
		int node_1, node_2;
		cin >> node_1 >> node_2;
		adjacent_mat[node_1].push_back(node_2);
		adjacent_mat[node_2].push_back(node_1);
	}
	for(int i = 0; i < queries; i++)
	{
		int q1, q2;
		cin >> q1 >> q2;
		query_pair.push_back(make_pair(q1, q2));
	}
	vector< int > levels(n + 1);
	vector< bool > visited(n + 1);
	int max_level = 0;
	dfs(visited, levels, parents, adjacent_mat, 0, 1, -1, max_level);
	vector< vector< int > > jump_levels = set_levels(adjacent_mat, parents, max_level, nodes_count);
	return 0;
}