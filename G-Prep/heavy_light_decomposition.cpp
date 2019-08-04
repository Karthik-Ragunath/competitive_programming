// https://www.hackerrank.com/challenges/subtrees-and-paths/problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct HASH
{
    size_t operator()(const pair< ll, ll > &hash_pair) const
    {
        return hash< ll >()(hash_pair.first ^ (hash_pair.second << 32));
    }
};

vector< ll > nodes(100001);
vector< unordered_set< ll > > tree_nodes(100001);
vector< bool > tree_nodes_visited(100001);
vector< bool > visited_lca_nodes(100001);
unordered_map< ll, pair< ll, ll > > query_type_add;
unordered_map< ll, pair< ll, ll > > query_type_max;
unordered_map< ll, unordered_set< ll > > lca_map;
vector< ll > max_child_vec(100001);
vector< ll > union_find_parent(100001);
vector< ll > parent_nodes(100001);
unordered_map< pair< ll, ll >, ll, HASH > lca_pair_map;
vector< ll > chain_number_vec(100001);
vector< ll > chain_head;
vector< vector< ll > > fenwick_tree(1000);
vector< unordered_map< ll, ll > > chain_positions(1000);
vector< vector< ll > > chain_positions_values(1000);
vector< bool > updated_atleast_once(100001);
vector< ll > unique_values_updated_atleast_once_in_chain(1000);

ll chain_number = 1;

ll find_parent_index(ll index)
{
    if(union_find_parent[index] == index)
    {
        return index;
    }
    ll parent_index = find_parent_index(union_find_parent[index]);
    union_find_parent[index] = parent_index;
    return parent_index;
}

void print_vec(vector< ll > test_vec)
{ 
    ll index = 0;
    for(auto iter = test_vec.begin(); iter != test_vec.end(); iter++, index++)
    {
        cout << "index: " << index << "val: " << *iter << "\n";
    }
}

void fenwick_tree_creation(ll start_index, ll end_index, vector< ll > &local_nodes, vector< ll > &local_fenwick_tree, ll update_value)
{
    while(start_index <= end_index)
    {
        local_fenwick_tree[start_index] = update_value > local_fenwick_tree[start_index] ? update_value : local_fenwick_tree[start_index];
        start_index += start_index & (-start_index);
    }
}

void create_fenwick_tree(ll start_index, ll end_index, vector< ll > &local_nodes, vector< ll > &local_fenwick_tree)
{
    for(ll i = 1; i <= end_index; i++)
    {
        // Node already exists 
        fenwick_tree_creation(i, end_index, local_nodes, local_fenwick_tree, -1000000000000);
    }
}

void update_fenwick_tree(ll index, ll value, ll end_index, vector< ll > &local_nodes, vector< ll > &local_fenwick_tree)
{
    local_nodes[index] += value;
    fenwick_tree_creation(index, end_index, local_nodes, local_fenwick_tree, local_nodes[index]);
}

ll fenwick_query(ll index, vector< ll > &local_fenwick_tree)
{
    ll max_value = -1000000000001;
    while(index > 0)
    {
        max_value = local_fenwick_tree[index] > max_value ? local_fenwick_tree[index] : max_value;
        index -= (index & -index);
    }
    return max_value;
}

ll range_query(ll start_index, ll end_index, vector< ll > &local_fenwick_tree)
{
    ll end_index_val = fenwick_query(end_index, local_fenwick_tree);
    ll start_index_val = fenwick_query(start_index - 1, local_fenwick_tree);
    // cout << "range_query - end_index: " << end_index << " end_index_val: " << end_index_val << "\n";
    // cout << "range_query - start_index: " << start_index << " start_index_val: " << start_index_val << "\n"; 
    ll max_in_range = end_index_val - start_index_val;
    return max_in_range;
}

ll dfs(ll index)
{
    ll max_value = 0;
    ll max_value_child = index;
    // cout << "dfs_index: " << index << "\n";
    for(auto children: tree_nodes[index])
    {
        // cout << "children: " << children << "\n";
        parent_nodes[children] = index;
        tree_nodes[children].erase(index);
        ll max_child_value = dfs(children);
        if(max_child_value > max_value)
        {
            max_value = max_child_value;
            max_value_child = children;
        }
    }

    for(ll child_lca_index: lca_map[index])
    {
        if(visited_lca_nodes[child_lca_index])
        {
            // cout << "index: " << index << " child_lca_index: " << child_lca_index << "\n";
            ll lca_value = find_parent_index(child_lca_index);
            // cout << "lca_value: " << lca_value << "\n";
            lca_pair_map[make_pair(index, child_lca_index)] = lca_value;
            lca_pair_map[make_pair(child_lca_index, index)] = lca_value;
        }
    }

    visited_lca_nodes[index] = true;
    union_find_parent[index] = parent_nodes[index];
    max_child_vec[index] = max_value_child;
    return (max_value + 1);
}

ll query_tree_up(ll index_1, ll index_2)
{
    ll chain_number_index_1 = chain_number_vec[index_1];
    ll chain_number_index_2 = chain_number_vec[index_2];
    auto position_index_1_iter = chain_positions[chain_number_index_1].find(index_1);
    ll position_index_1 = position_index_1_iter -> second;
    auto position_index_2_iter = chain_positions[chain_number_index_2].find(index_2);
    ll position_index_2 = position_index_2_iter -> second;
    if(chain_number_index_1 == chain_number_index_2)
    {
        ll max_index, min_index;
        if(position_index_1 > position_index_2)
        {
            max_index = position_index_1;
            min_index = position_index_2;
        }
        else
        {
            max_index = position_index_2;
            min_index = position_index_1;
        }
        // cout << "Min_Index: " << min_index << " max_index: " << max_index << "\n";
        ll range_max_value = range_query(min_index, max_index, fenwick_tree[chain_number_index_1]);
        return range_max_value;
    }
    else
    {
        ll range_max_value = -10000000000;
        ll source_chain_number_index = -1, source_chain_position_index = -1, target_chain_number_index = -1, target_chain_position_index = -1;
        if(chain_number_index_1 > chain_number_index_2)
        {
            source_chain_number_index = chain_number_index_1;
            source_chain_position_index = position_index_1;
            target_chain_number_index = chain_number_index_2;
            target_chain_position_index = position_index_2;
        }
        else
        {
            source_chain_number_index = chain_number_index_2;
            source_chain_position_index = position_index_2;
            target_chain_number_index = chain_number_index_1;
            target_chain_position_index = position_index_1;
        }
        while(true)
        {
            // cout << source_chain_number_index << " " << source_chain_position_index << " " << target_chain_number_index << " " << target_chain_position_index << "\n";
            ll range_value = range_query(1, source_chain_position_index, fenwick_tree[source_chain_number_index]);
            if(range_value > range_max_value)
            {
                range_max_value = range_value;
            }
            ll chain_head_index = chain_head[source_chain_number_index];
            ll parent_chain_head = parent_nodes[chain_head_index];
            // cout << "chain_head_index: " << chain_head_index << " parent_chain_head_index: " << parent_chain_head << "\n"; 
            if(chain_number_vec[parent_chain_head] == target_chain_number_index)
            {
                // cout << "new chain number is same as destination chain number" << "\n";
                ll range_value = range_query(1, target_chain_position_index, fenwick_tree[target_chain_number_index]);
                if(range_value > range_max_value)
                {
                    range_max_value = range_value;
                }
                break;
            }
            source_chain_number_index = chain_number_vec[parent_chain_head];
            auto source_chain_position_index_iter = chain_positions[source_chain_number_index].find(parent_chain_head);
            source_chain_position_index = source_chain_position_index_iter -> second;
        }
        return range_max_value;
    }
}

ll query_for_max(ll index_1, ll index_2)
{
    ll lca_value = lca_pair_map[make_pair(index_1, index_2)];
    cout << "index_1: " << index_1 << " index_2: " << index_2 << " lca_value: " << lca_value << "\n";
    ll max_value_range_1 = query_tree_up(index_1, lca_value);
    ll max_value_range_2 = query_tree_up(index_2, lca_value);
    if(max_value_range_1 > max_value_range_2)
    {
        return max_value_range_1;
    }
    else
    {
        return max_value_range_2;
    }
    return -1;
}

void hld(ll index)
{
    if(index == 1)
    {
        chain_head.push_back(index);
        // cout << "chain_number: " << chain_number << " chain_head: " << chain_head[chain_number] << "\n";
        chain_positions_values[chain_number].push_back(0);
    }
    chain_number_vec[index] = chain_number;
    chain_positions_values[chain_number].push_back(nodes[index]);
    chain_positions[chain_number].insert(make_pair(index, chain_positions_values[chain_number].size() - 1));
    // cout << "chain_number: " << chain_number << " position of node: " << index << " is: " << chain_positions[chain_number][index] << "\n";
    if(max_child_vec[index] != index)
    {
        // cout << "max_child_vec of chain_number: " << chain_number << " is: " << max_child_vec[index] << "\n";
        hld(max_child_vec[index]);
    }
    for(auto child: tree_nodes[index])
    {
        if(child != max_child_vec[index])
        {
            chain_number++;
            chain_head.push_back(child);
            chain_positions_values[chain_number].push_back(0);
            // cout << "chain_number: " << chain_number << " chain_head: " << chain_head[chain_number] << "\n";
            hld(child);
        }
    }
}

void create_fenwick_tree_chains()
{
    for(ll i = 1; i <= chain_number; i++)
    {
        vector< ll > local_fenwick_tree(chain_positions_values[i].size(), -1000000000000);
        // create_fenwick_tree(1, chain_positions_values[i].size() - 1, chain_positions_values[i], local_fenwick_tree); // Doesnt make any difference 
        fenwick_tree[i] = local_fenwick_tree;
        // cout << "Tree (Chain) Number: " << i << "\n";
        // print_vec(fenwick_tree[i]);
    }
}

void updates(ll index, ll value)
{
    nodes[index] += value;
    ll chain_number_local = chain_number_vec[index];
    if(!updated_atleast_once[index])
    {
        updated_atleast_once[index] = true;
        unique_values_updated_atleast_once_in_chain[chain_number_local] += 1;
    }
    // cout << "previous fenwick tree values: " << "\n";
    // print_vec(fenwick_tree[chain_number_local]);
    auto local_fenwick_tree_index_iter = chain_positions[chain_number_local].find(index);
    ll local_fenwick_tree_index = local_fenwick_tree_index_iter -> second;
    update_fenwick_tree(local_fenwick_tree_index, value, chain_positions_values[chain_number_local].size() - 1, chain_positions_values[chain_number_local], fenwick_tree[chain_number_local]);
    // cout << "tree (chain) number: " << chain_number_local << " fenwick_tree_position: " << local_fenwick_tree_index << " value to be updated: " << value <<  "\n";
    // print_vec(fenwick_tree[chain_number_local]);
}


int main()
{
    chain_head.push_back(0); // for convienience
    parent_nodes[1] = 1;
    ll node_count;
    cin >> node_count;
    for(ll i = 0; i < node_count - 1; i++)
    {
        ll node_1, node_2;
        cin >> node_1 >> node_2;
        tree_nodes[node_1].insert(node_2);
        tree_nodes[node_2].insert(node_1);
    }

    ll queries;
    cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        string type;
        cin >> type;
        if(type == "add")
        {
            ll node, value;
            cin >> node >> value;
            query_type_add.insert(make_pair(i, make_pair(node, value)));
        }
        else
        {
            ll node_1, node_2;
            cin >> node_1 >> node_2;
            query_type_max.insert(make_pair(i, make_pair(node_1, node_2)));
            lca_map[node_1].insert(node_2);
            lca_map[node_2].insert(node_1);
        }
    }
    /*
    for(auto map_pair: query_type_max)
    {
        pair< ll, ll > pair_node = map_pair.second;
        lca_map.insert(make_pair(pair_node.first, pair_node.second));
        lca_map.insert(make_pair(pair_node.second, pair_node.first));
    }
    */
    iota(union_find_parent.begin(), (union_find_parent.begin() + node_count + 1), 0);
    iota(max_child_vec.begin(), (max_child_vec.begin() + node_count + 1), 0);
    ll max_height = dfs(1);
    // cout << "max_height: " << max_height << "\n";
    hld(1);
    cout << "Total chains: " << chain_number << "\n";
    create_fenwick_tree_chains();
    for(ll i = 0; i < queries; i++)
    {
        if(query_type_add.find(i) != query_type_add.end())
        {
            // cout << "add_node: " << query_type_add[i].first << " value: " << query_type_add[i].second << "\n";
            updates(query_type_add[i].first, query_type_add[i].second);
        }
        else
        {
            // cout << "node_1: " << query_type_max[i].first << " node_2: " << query_type_max[i].second << "\n";
            ll max_value = query_for_max(query_type_max[i].first, query_type_max[i].second);
            // cout << max_value << "\n";
        }
    }
}

/*
15
1 2
4 2
3 1
4 5
5 6
5 7
5 8
2 10
10 15
10 11
10 12
15 13
15 14
9 15
1
max 6 11

Total chains: 9
index_1: 6 index_2: 11 lca_value: 2
8 1 1 2
chain_head_index: 6 parent_chain_head_index: 5
6 2 1 2
chain_head_index: 4 parent_chain_head_index: 2
new chain number is same as destination chain number
5 1 1 2
chain_head_index: 11 parent_chain_head_index: 10
new chain number is same as destination chain number
*/