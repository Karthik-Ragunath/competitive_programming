// https://www.codechef.com/problems/MAZE
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct HASH
{
	// size_t operator()(const pair< ll, ll > &pair_1, const pair< ll, ll > &pair_2) const
	// {
	// 	return hash<ll>()(pair_1.first ^ pair_1.second ^ pair_2.first ^ (pair_2.second << 32));
	// }
	size_t operator()(const pair< ll, ll > &pair_node) const
	{
		return hash<ll>()(pair_node.first ^ (pair_node.second << 32));
	}
};

struct HASH_PAIR
{
	size_t operator()(const pair< pair< ll, ll >, pair< ll, ll > > &pair_node) const
	{
		return hash< ll >()(pair_node.first.first ^ pair_node.first.second ^ pair_node.second.first ^ (pair_node.second.second << 32));
	}
};

pair< ll, ll > find_parent(unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, pair< ll, ll > cell)
{
	if(cells_parent[cell] == cell)
	{
		return cell;
	}
	pair< ll, ll > parent_cell = find_parent(cells_parent, cells_parent[cell]);
	cells_parent[cell] = parent_cell;
	return parent_cell;
}

bool union_find_op(unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, unordered_map< pair< ll, ll >, ll, HASH > &union_rank_weight, pair< ll, ll > cell_1, pair< ll, ll> cell_2)
{
	pair< ll, ll > parent_cell_1 = find_parent(cells_parent, cell_1);
	pair< ll, ll > parent_cell_2 = find_parent(cells_parent, cell_2);
	// cout << "cell1: " << cell_1.first << ", " << cell_1.second << " parent_cell_1: " << cells_parent[cell_1].first << ", " << cells_parent[cell_1].second << endl;
	// cout << "cell2: " << cell_2.first << ", " << cell_2.second << " parent_cell_2: " << cells_parent[cell_2].first << ", " << cells_parent[cell_2].second << endl;
	if(parent_cell_1 != parent_cell_2)
	{
		if(union_rank_weight[parent_cell_1] >= union_rank_weight[parent_cell_2])
		{
			cells_parent[parent_cell_2] = parent_cell_1;
			union_rank_weight[parent_cell_1] += union_rank_weight[parent_cell_2];
		}
		else
		{
			cells_parent[parent_cell_1] = parent_cell_2;
			union_rank_weight[parent_cell_2] += union_rank_weight[parent_cell_1];
		}
		return false;
	}
	else
	{
		return true;
	}
}

bool is_adjacent_cell_present(unordered_set< pair< ll, ll >, HASH > &edges_set, unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, unordered_map< pair< ll, ll >, ll, HASH > &union_rank_weight, pair< ll, ll > cell_1, pair<ll, ll> cell_2, unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > &visited_map, unordered_set< pair< ll, ll >, HASH > &outer_edges_set, unordered_map< pair< ll, ll >, ll, HASH > &edge_connected_outer, bool is_outer)
{
	bool is_cycle = false;
	auto edges_find_iter = edges_set.find(cell_2);
	// cout << "cell 1: " << cell_1.first << ", " << cell_1.second << " cell 2: " << cell_2.first << ", " << cell_2.second << endl;
	if(edges_find_iter != edges_set.end())
	{
		// cout << "cell 1: " << cell_1.first << ", " << cell_1.second << " cell 2: " << cell_2.first << ", " << cell_2.second << endl;
		if(not is_outer)
		{
			auto outer_find_iter = outer_edges_set.find(cell_2);
			if(outer_find_iter != outer_edges_set.end())
			{
				if(edge_connected_outer[cell_1] == 1)
				{
					return is_cycle;
				}
			}
		}
		if(cell_1.first < cell_2.first || cell_1.second < cell_2.second)
		{
			if(visited_map[make_pair(make_pair(cell_1.first, cell_1.second), make_pair(cell_2.first, cell_2.second))] == 1)
			{
				return is_cycle;
			}
			visited_map[make_pair(make_pair(cell_1.first, cell_1.second), make_pair(cell_2.first, cell_2.second))] = 1;
		}
		else
		{
			if(visited_map[make_pair(make_pair(cell_2.first, cell_2.second), make_pair(cell_1.first, cell_1.second))] == 1)
			{
				return is_cycle;
			}
			visited_map[make_pair(make_pair(cell_2.first, cell_2.second), make_pair(cell_1.first, cell_1.second))] = 1;
		}
		if(not is_outer)
		{ 
			auto outer_find_iter = outer_edges_set.find(cell_2);
			if(outer_find_iter != outer_edges_set.end())
			{
				edge_connected_outer[cell_1] = 1;
			}
		}
		is_cycle = union_find_op(cells_parent, union_rank_weight, cell_1, cell_2);
		// cout << "cell 1: " << cell_1.first << ", " << cell_1.second << " cell 2: " << cell_2.first << ", " << cell_2.second << " Parent cell_1: " << cells_parent[make_pair(cell_1.first, cell_1.second)].first << ", " << cells_parent[make_pair(cell_1.first, cell_1.second)].second << " Parent cell_2: " << cells_parent[make_pair(cell_2.first, cell_2.second)].first << ", " << cells_parent[make_pair(cell_2.first, cell_2.second)].second <<endl;
		// cout << "-------------" << endl;
	}
	// cout << "Is cycle: " << is_cycle << endl;
	// cout << "****" << endl;
	return is_cycle;
}

bool union_operation(unordered_set< pair< ll, ll >, HASH > &edges_set, unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, unordered_map< pair< ll, ll >, ll, HASH > &union_rank_weight, ll column_len, ll row_len, unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > &visited_map, unordered_set< pair< ll, ll >, HASH > &outer_edges_set, unordered_set< pair< ll, ll >, HASH > &inner_edges_set, bool is_outer)
{
	bool is_cycle = false;
	unordered_map< pair< ll, ll >, ll, HASH > edge_connected_outer;
	if(is_outer)
	{ 
		for(auto edges_iter = edges_set.begin(); edges_iter != edges_set.end(); edges_iter++)
		{
			ll cell_1 = edges_iter -> first;
			ll cell_2 = edges_iter -> second;
			if(cell_2 - cell_1 == 1)
			{
				is_cycle = is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - (column_len + 2), cell_1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1, cell_1 + (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2 - (column_len + 2), cell_2), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2, cell_2 + (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - (column_len + 2), cell_2 - (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 + (column_len + 2), cell_2 + (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer);
				if(is_cycle)
				{
					return is_cycle;
				}
			}
			else
			{
				is_cycle = is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - 1, cell_1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1, cell_1 + 1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2 - 1, cell_2), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2, cell_2 + 1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - 1, cell_2 - 1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 + 1, cell_2 + 1), visited_map, outer_edges_set, edge_connected_outer, is_outer);
				if(is_cycle)
				{
					return is_cycle;
				}
			}
		}
	}
	else
	{
		for(auto edges_iter = inner_edges_set.begin(); edges_iter != edges_set.end(); edges_iter++)
		{
			ll cell_1 = edges_iter -> first;
			ll cell_2 = edges_iter -> second;
			if(cell_2 - cell_1 == 1)
			{
				is_cycle = is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - (column_len + 2), cell_1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1, cell_1 + (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2 - (column_len + 2), cell_2), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2, cell_2 + (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - (column_len + 2), cell_2 - (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 + (column_len + 2), cell_2 + (column_len + 2)), visited_map, outer_edges_set, edge_connected_outer, is_outer);
				if(is_cycle)
				{
					return is_cycle;
				}
			}
			else
			{
				is_cycle = is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - 1, cell_1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1, cell_1 + 1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2 - 1, cell_2), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2, cell_2 + 1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - 1, cell_2 - 1), visited_map, outer_edges_set, edge_connected_outer, is_outer) || is_adjacent_cell_present(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 + 1, cell_2 + 1), visited_map, outer_edges_set, edge_connected_outer, is_outer);
				if(is_cycle)
				{
					return is_cycle;
				}
			}
		}
	}
	return is_cycle;
}

bool is_linked(unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, pair< ll, ll > cell_1, pair< ll, ll> cell_2, pair< ll, ll > parent_cell_1, pair< ll, ll > parent_cell_2, unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > &visited_map, unordered_set< pair< ll, ll >, HASH > &outer_edges_set, unordered_map< pair< ll, ll >, ll, HASH > &edge_connected_outer, pair< ll, ll > root_cell, unordered_set< pair< ll, ll >, HASH > &unneeded_edges)
{
	// cout << "cell 1: " << cell_1.first << ", " << cell_1.second << " cell 2: " << cell_2.first << ", " << cell_2.second << "Parent cell 1: " << parent_cell_1.first << ", " << parent_cell_1.second << endl;
	auto outer_find_iter = outer_edges_set.find(cell_2);
	if(cell_2 == root_cell)
	{
		return false;
	}
	auto unneeded_edges_iter = unneeded_edges.find(cell_2);
	if(unneeded_edges_iter != unneeded_edges.end())
	{
		return false;
	}
	if(outer_find_iter != outer_edges_set.end())
	{
		if(edge_connected_outer[cell_1] == 1)
		{
			return false;
		}
	}
	if(cell_1.first < cell_2.first || cell_1.second < cell_2.second)
	{
		if(visited_map[make_pair(make_pair(cell_1.first, cell_1.second), make_pair(cell_2.first, cell_2.second))] == 1)
		{
			return false;
		}
		visited_map[make_pair(make_pair(cell_1.first, cell_1.second), make_pair(cell_2.first, cell_2.second))] = 1;
	}
	else
	{
		if(visited_map[make_pair(make_pair(cell_2.first, cell_2.second), make_pair(cell_1.first, cell_1.second))] == 1)
		{
			return false;
		}
		visited_map[make_pair(make_pair(cell_2.first, cell_2.second), make_pair(cell_1.first, cell_1.second))] = 1;
	}
	if(outer_find_iter != outer_edges_set.end())
	{
		edge_connected_outer[cell_1] = 1;
	} 
	parent_cell_2 = find_parent(cells_parent, cell_2);
	if(parent_cell_1 == parent_cell_2)
	{
		// cout << "cell 1: " << cell_1.first << ", " << cell_1.second << " cell 2: " << cell_2.first << ", " << cell_2.second << " Parent cell_1: " << parent_cell_1.first << ", " << parent_cell_1.second << " Parent cell_2: " << parent_cell_2.first << ", " << parent_cell_2.second << endl;
		return true;
	}
	return false;
}

bool is_same_parent(unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, pair< ll, ll > cell_1, pair< ll, ll> cell_2, ll row_len, ll column_len, unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > &visited_map, unordered_set< pair< ll, ll >, HASH > &outer_edges_set, unordered_map< pair< ll, ll >, ll, HASH > &edge_connected_outer, unordered_set< pair< ll, ll >, HASH > &unneeded_edges)
{
	pair< ll, ll > parent_cell_1 = find_parent(cells_parent, cell_1);
	pair< ll, ll > parent_cell_2 = find_parent(cells_parent, cell_2);
	bool is_same_parent = false;
	if(cell_2.second - cell_2.first == 1)
	{
		is_same_parent = is_linked(cells_parent, cell_2, make_pair(cell_2.first - (column_len + 2), cell_2.first), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.first, cell_2.first + (column_len + 2)), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.second - (column_len + 2), cell_2.second), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.second, cell_2.second + (column_len + 2)), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.first - (column_len + 2), cell_2.second - (column_len + 2)), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.first + (column_len + 2), cell_2.second + (column_len + 2)), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges);
		if(is_same_parent)
		{
			return is_same_parent;
		}
	}
	else
	{
		is_same_parent = is_linked(cells_parent, cell_2, make_pair(cell_2.first - 1, cell_2.first), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.first, cell_2.first + 1), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.second - 1, cell_2.second), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.second, cell_2.second + 1), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.first - 1, cell_2.second - 1), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges) || is_linked(cells_parent, cell_2, make_pair(cell_2.first + 1, cell_2.second + 1), parent_cell_1, make_pair((ll)0, (ll)0), visited_map, outer_edges_set, edge_connected_outer, cell_1, unneeded_edges);
		if(is_same_parent)
		{
			return is_same_parent;
		}
	}	
	return is_same_parent;
}

bool does_adj_cell_form_cycle(unordered_set< pair< ll, ll >, HASH > &edges_set, unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, unordered_map< pair< ll, ll >, ll, HASH > &union_rank_weight, pair< ll, ll > cell_1, pair<ll, ll> cell_2, ll row_len, ll column_len, unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > &visited_map, unordered_set< pair< ll, ll >, HASH > &outer_edges_set, unordered_map< pair< ll, ll >, ll, HASH > &edge_connected_outer, unordered_set< pair< ll, ll >, HASH > &unneeded_edges)
{
	bool is_cycle = false;
	auto edges_find_iter = edges_set.find(cell_2);
	if(edges_find_iter == edges_set.end())
	{
		auto unneeded_edges_iter = unneeded_edges.find(cell_2);
		if(unneeded_edges_iter == unneeded_edges.end())
		{
			is_cycle = is_same_parent(cells_parent, cell_1, cell_2, row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges);
		}
	}
	return is_cycle;
}

bool cycle_formation(unordered_set< pair< ll, ll >, HASH > &edges_set, unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > &cells_parent, unordered_map< pair< ll, ll >, ll, HASH > &union_rank_weight, ll row_len, ll column_len, unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > &visited_map, unordered_set< pair< ll, ll >, HASH > &outer_edges_set, unordered_set< pair< ll, ll >, HASH > &inner_edges_set, unordered_set< pair< ll, ll >, HASH > &unneeded_edges)
{
	bool cycle_formed = false;
	unordered_map< pair< ll, ll >, ll, HASH > edge_connected_outer;
	for(auto edges_iter = inner_edges_set.begin(); edges_iter != inner_edges_set.end(); edges_iter++)
	{
		ll cell_1 = edges_iter -> first;
		ll cell_2 = edges_iter -> second;
		if(cell_2 - cell_1 == 1)
		{
			cycle_formed = does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - (column_len + 2), cell_1), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1, cell_1 + (column_len + 2)), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2 - (column_len + 2), cell_2), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2, cell_2 + (column_len + 2)), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - (column_len + 2), cell_2 - (column_len + 2)), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 + (column_len + 2), cell_2 + (column_len + 2)), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges);
			if(cycle_formed)
			{
				return cycle_formed;
			}
		}
		else
		{
			cycle_formed = does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - 1, cell_1), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1, cell_1 + 1), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2 - 1, cell_2), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_2, cell_2 + 1), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 - 1, cell_2 - 1), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges) || does_adj_cell_form_cycle(edges_set, cells_parent, union_rank_weight, *edges_iter, make_pair(cell_1 + 1, cell_2 + 1), row_len, column_len, visited_map, outer_edges_set, edge_connected_outer, unneeded_edges);
			if(cycle_formed)
			{
				return cycle_formed;
			}
		}
	}
	return cycle_formed;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll testcases;
	cin >> testcases;
	for(ll test = 0; test < testcases; test++)
	{
		ll rows, columns, edges;
		cin >> rows >> columns >> edges;
		unordered_set< pair< ll, ll >, HASH > edges_set;
		unordered_set< pair< ll, ll >, HASH > outer_edges_set;
		unordered_map< pair< ll, ll >, pair< ll, ll >, HASH > cells_parent;
		unordered_map< pair< ll, ll >, ll, HASH > union_rank_weight;
		unordered_set< pair< ll, ll >, HASH > inner_edges_set;
		unordered_set< pair< ll, ll >, HASH > unneeded_edges;

		for(ll i = 1, j = 1, k = (rows + 1) * (columns + 2) + 1; j <= columns + 1; i++, j++, k++)
		{
			unneeded_edges.insert(make_pair(i, i + 1));
			unneeded_edges.insert(make_pair(k, k + 1));
		}
		for(ll i = 1, j = 1, k = columns + 2; j <= rows + 1; i += columns + 2, j++, k += columns + 2)
		{
			unneeded_edges.insert(make_pair(i, i + columns + 2));
			unneeded_edges.insert(make_pair(k, k + columns + 2));
		}

		for(ll i = 2, j = 1; j <= columns; j++, i++)
		{
			edges_set.insert(make_pair(i, i + columns + 2));
			outer_edges_set.insert(make_pair(i, i + columns + 2));
			cells_parent.insert(make_pair(make_pair(i, i + columns + 2), make_pair(i, i + columns + 2)));
			union_rank_weight.insert(make_pair(make_pair(i, i + columns + 2), (ll)1));
		}
		for(ll i = rows * (columns + 2) + 2, j = 1; j <= columns; j++, i++)
		{
			edges_set.insert(make_pair(i, i + columns + 2));
			outer_edges_set.insert(make_pair(i, i + columns + 2));
			cells_parent.insert(make_pair(make_pair(i, i + columns + 2), make_pair(i, i + columns + 2)));
			union_rank_weight.insert(make_pair(make_pair(i, i + columns + 2), (ll)1));
		}
		for(ll i = columns + 4, j = 1; j <= rows; j++, i += columns + 2)
		{
			edges_set.insert(make_pair(i - 1, i));
			outer_edges_set.insert(make_pair(i - 1, i));
			cells_parent.insert(make_pair(make_pair(i - 1, i), make_pair(i - 1, i)));
			union_rank_weight.insert(make_pair(make_pair(i - 1, i), (ll)1));
		}
		for(ll i = columns + 2 + columns + 1, j = 1; j <= rows; j++, i += columns + 2)
		{
			edges_set.insert(make_pair(i, i + 1));
			outer_edges_set.insert(make_pair(i, i + 1));
			cells_parent.insert(make_pair(make_pair(i, i + 1), make_pair(i, i + 1)));
			union_rank_weight.insert(make_pair(make_pair(i, i + 1), (ll)1));
		}

		unordered_map< pair< pair< ll, ll >, pair< ll, ll > >, ll, HASH_PAIR > visited_map;
		bool outer_edge = union_operation(edges_set, cells_parent, union_rank_weight, rows, columns, visited_map, outer_edges_set, inner_edges_set, true);

		// cout << "Outer Edge: " << outer_edge << endl;
		// for(auto edges_iter = edges_set.begin(); edges_iter != edges_set.end(); edges_iter++)
		// {
		// 	cout << "Edges Iter: " << edges_iter -> first << ", " << edges_iter -> second << " parent: " << cells_parent[*edges_iter].first << ", " << cells_parent[*edges_iter].second << " weight: " << union_rank_weight[*edges_iter] << endl;
		// }
		for(ll i = 0; i < edges; i++)
		{
			ll temp1_row, temp1_col, temp2_row, temp2_col;
			cin >> temp1_row >> temp1_col >> temp2_row >> temp2_col;
			ll cell_1 = temp1_row * (columns + 2) + temp1_col + 1;
			ll cell_2 = temp2_row * (columns + 2) + temp2_col + 1;
			// cout << "Edges: " << cell_1 << " " << cell_2 << endl;
			edges_set.insert(make_pair(cell_1, cell_2));
			cells_parent.insert(make_pair(make_pair(cell_1, cell_2), make_pair(cell_1, cell_2)));
			union_rank_weight.insert(make_pair(make_pair(cell_1, cell_2), 1));
			inner_edges_set.insert(make_pair(cell_1, cell_2));
		}

		// cout << "---Second Portion---" << endl;
		bool is_cycle = union_operation(edges_set, cells_parent, union_rank_weight, rows, columns, visited_map, outer_edges_set, inner_edges_set, false);
		// cout << "---Second Portion Ends: " << is_cycle << " ---" << endl;

		if(is_cycle)
		{
			// cout << "Solution: " << 0 << endl;
			cout << 0 << "\n";
		}
		else
		{
			is_cycle = cycle_formation(edges_set, cells_parent, union_rank_weight, rows, columns, visited_map, outer_edges_set, inner_edges_set, unneeded_edges);
			if(is_cycle)
			{
				// cout << "Solution: " << 1 << endl;
				cout << 1 << "\n";
			}
			else
			{
				// cout << "Solution: " << 2 << endl;
				cout << 2 << "\n";
			}
		}
	}
	return 0;
}

/*
Sample Input

4
4 4 2
1 2 1 3
2 1 3 1
4 4 4
1 2 1 3
2 1 3 1
2 2 2 3
2 2 3 2
4 4 2
2 1 3 1
1 1 1 2
6 7 8
3 1 4 1
3 2 4 2
3 2 3 3
2 3 3 3
2 5 3 5
2 6 3 6
3 6 3 7
3 7 4 7
*/