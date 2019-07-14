// https://www.codechef.com/problems/PAIRCLST
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct HASH
{
	size_t operator()(const pair< ll, ll > &pair_key) const
	{
		return hash< ll >()(pair_key.first ^ (pair_key.second << 32));
	}
};

class Compare_Nodes
{
	public:
		bool operator()(const pair< ll, ll > &pair_1, const pair< ll, ll > &pair_2) const
		{
			if(pair_1.second > pair_2.second)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

vector< vector< ll > > edges(100001);
vector< ll > special_nodes;
unordered_set< ll > special_edges_set;
unordered_map< pair< ll, ll >, ll, HASH > weight_map;

int main()
{
	ll nodes_count, edges_count, special_edges_count;
	cin >> nodes_count >> edges_count >> special_edges_count;
	for(ll i = 0; i < special_edges_count; i++)
	{
		ll temp;
		cin >> temp;
		special_nodes.push_back(temp);
		special_edges_set.insert(temp);
	}
	for(ll i = 0; i < edges_count; i++)
	{
		ll node_1, node_2, weight;
		cin >> node_1 >> node_2 >> weight;
		edges[node_1].push_back(node_2);
		edges[node_2].push_back(node_1);
		weight_map.insert(make_pair(make_pair(node_2, node_1), weight));
		weight_map.insert(make_pair(make_pair(node_1, node_2), weight));
	}
	ll solution = 100000000000L;
	for(ll i = 0; i < special_edges_count; i++)
	{
		ll special_node_index = special_nodes[i];
		vector< ll > distance(nodes_count + 1, -1);
		distance[special_node_index] = 0;
		ll distance_now = 0;
		priority_queue< pair< ll, ll >, vector< pair< ll, ll > >, Compare_Nodes > pq;
		for(auto iter = edges[special_node_index].begin(); iter != edges[special_node_index].end(); iter++)
		{
			ll other_index = *iter;
			ll edge_weight = weight_map[make_pair(special_node_index, other_index)];
			distance[other_index] = distance[special_node_index] + edge_weight;
			pq.push(make_pair(other_index, distance[other_index]));
		}
		while(!pq.empty())
		{
			pair< ll, ll > top_pair = pq.top();
			pq.pop();
			ll top_index = top_pair.first;
			ll distance_top_index = top_pair.second;
			auto find_iter = special_edges_set.find(top_index);
			if(find_iter != special_edges_set.end())
			{
				if(distance_top_index < solution)
				{
					solution = distance_top_index;
					break;
				}
			}
			else if(distance_top_index >= solution)
			{
				break;
			}
			for(auto iter = edges[top_index].begin(); iter != edges[top_index].end(); iter++)
			{
				ll other_index = *iter;
				ll edge_weight = weight_map[make_pair(top_index, other_index)];
				if(distance[other_index] == -1)
				{
					distance[other_index] = distance_top_index + edge_weight;
					pq.push(make_pair(other_index, distance[other_index]));
				}
				else
				{
					if(edge_weight + distance_top_index < distance[other_index])
					{
						distance[other_index] = distance_top_index + edge_weight;
						pq.push(make_pair(other_index, distance[other_index]));
					}
				}
			}
		}
	}
	cout << solution << "\n";
	return 0;
}