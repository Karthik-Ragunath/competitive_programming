// https://www.codechef.com/LTIME14/problems/TALCA
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct HASH
{
	size_t operator()(const pair< ll, ll > &pair_val) const
	{
		return hash< ll >()(pair_val.first ^ (pair_val.second << 32));
	}
};

ll find_parent(ll index, vector< ll > parents)
{
	if(parents[index] == index)
	{
		return index;
	}
	ll value = find_parent(parents[index], parents);
	parents[index] = value;
	return value;
}

void dfs(ll current_node, vector< bool > &visited, vector< bool > &visited_avoid_inf_loop, vector< ll > &parents, unordered_map< ll, unordered_set< ll > > &tree_nodes, unordered_map< ll, unordered_set< ll > > &lca_queries, unordered_map< pair< ll, ll >, ll, HASH > &result_lcas, ll parent_node_index)
{
	visited_avoid_inf_loop[current_node] = true;
	for(auto iter = tree_nodes[current_node].begin(); iter != tree_nodes[current_node].end(); iter++)
	{
		if(!visited_avoid_inf_loop[*iter])
		{
			dfs(*iter, visited, visited_avoid_inf_loop, parents, tree_nodes, lca_queries, result_lcas, current_node);
		}
	}
	auto find_iter = lca_queries.find(current_node);
	if(find_iter != lca_queries.end())
	{
		for(auto iter = lca_queries[current_node].begin(); iter != lca_queries[current_node].end(); iter++)
		{
			// cout << "prev_node: " << *iter << " current_node: " << current_node;
			if(*iter == current_node)
			{
				ll lca_val = *iter;
				result_lcas.insert(make_pair(make_pair(current_node, *iter), lca_val));
				result_lcas.insert(make_pair(make_pair(*iter, current_node), lca_val));
				// cout << " lca val: " << lca_val;
			}
			else if(visited[*iter])
			{
				ll lca_val = find_parent(*iter, parents);
				result_lcas.insert(make_pair(make_pair(current_node, *iter), lca_val));
				result_lcas.insert(make_pair(make_pair(*iter, current_node), lca_val));
				// cout << " lca val: " << lca_val;
			}
			// cout << endl;
		}
	}
	visited[current_node] = true;
	parents[current_node] = parent_node_index;
}


void check_and_add_unord_map(unordered_map< ll, unordered_set< ll > > &unord_map, ll u, ll v)
{
	// cout << "u and v: " << u << " " << v << endl; 
	auto find_iter = unord_map.find(u);
	if(find_iter != unord_map.end())
	{
		find_iter -> second.insert(v);
	}
	else
	{
		unordered_set< ll > new_set;
		new_set.insert(v);
		unord_map.insert(make_pair(u, new_set));
	}
	// cout << "stone1" << endl;
	auto find_iter_new = unord_map.find(v);
	if(find_iter_new != unord_map.end())
	{
		find_iter_new -> second.insert(u);
	}
	else
	{
		unordered_set< ll > new_set;
		new_set.insert(u);
		unord_map.insert(make_pair(v, new_set));
	}
	// cout << "stone2" << endl;
}

int main()
{
	ll n;
	cin >> n;
	unordered_map< ll, unordered_set< ll > > nodes;
	for(ll i = 0; i < n - 1; i++)
	{
		ll t1, t2;
		cin >> t1 >> t2;
		check_and_add_unord_map(nodes, t1, t2);
	}
	
	/*
	for(auto iter = nodes.begin(); iter != nodes.end(); iter++)
	{
		cout << "Key: " << iter -> first << " Vals: ";
		for(auto inner_iter = iter -> second.begin(); inner_iter != iter -> second.end(); inner_iter++)
		{
			cout << *inner_iter << " " << endl;
		}
	}
	*/
	// cout << "Mile0" << endl;
	vector< bool > visited(n + 1);
	vector< bool > visited_avoid_inf_loop(n + 1);
	unordered_map< ll, unordered_set< ll > > lca_queries;
	vector< pair< ll, pair< ll, ll > > > actual_queries;  
	ll Q;
	cin >> Q;
	for(ll i = 0; i < Q; i++)
	{
		ll r, u, v;
		cin >> r >> u >> v;
		actual_queries.push_back(make_pair(r, make_pair(u, v)));
		// cout << "r u v: " << r << " " << u << " " << v << endl;
		if(r == 1)
		{
			check_and_add_unord_map(lca_queries, u, v);
		}
		else
		{
			check_and_add_unord_map(lca_queries, r, u);
			check_and_add_unord_map(lca_queries, u, v);
			check_and_add_unord_map(lca_queries, v, r);
		}
		// cout << "r u v: " << r << " " << u << " " << v << endl;
	}
	// cout << "Mile1" << endl;
	vector< ll > parents(n + 1);
	for(ll i = 0; i <= n; i++)
	{
		parents[i] = i;
	}
	unordered_map< pair< ll, ll >, ll, HASH > result_lcas;
	dfs(1, visited,  visited_avoid_inf_loop, parents, nodes, lca_queries, result_lcas, 1);
	for(auto iter = actual_queries.begin(); iter != actual_queries.end(); iter++)
	{
		if(iter -> first == 1)
		{
			cout << result_lcas[make_pair(iter -> second.first, iter -> second.second)] << endl;
		}
		else
		{
			ll result_1 = result_lcas[make_pair(iter -> first, iter -> second.first)];
			ll result_2 = result_lcas[make_pair(iter -> second.first, iter -> second.second)];
			ll result_3 = result_lcas[make_pair(iter -> first, iter -> second.second)];
			// cout << result_1 << " " << result_2 << " " << result_3 << endl;
			if(result_1 == result_2)
			{
				cout << result_3 << endl;
			}
			else if(result_1 == result_3)
			{
				cout << result_2 << endl;
			}
			else if(result_2 == result_3)
			{
				cout << result_1 << endl;
			}
		}
	}
	return 0;
}