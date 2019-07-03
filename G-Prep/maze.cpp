// https://www.codechef.com/problems/MAZE
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// struct HASH
// {
//     size_t operator()(const pair< ll, ll > &pair_node) const
//     {
//         return hash< ll >()(pair_node.first ^ (pair_node.second << 32));
//     }
// };

// struct HASH_PAIR
// {
//     size_t operator()(const pair< pair< ll, ll >, pair< ll, ll > > &pair_node) const
//     {
//         return hash< ll >()(pair_node.first.first ^ pair_node.first.second ^ pair_node.second.first ^ (pair_node.second.second << 32));
//     }
// };

// unordered_set< pair< pair< ll, ll >, pair< ll, ll > >, HASH_PAIR > pair_nodes_set;
// unordered_set< pair< ll, ll >, HASH > nodes;
// unordered_map< pair< ll, ll >, ll, HASH > nodes_index_map;

set< pair< pair< ll, ll >, pair< ll, ll > > > pair_nodes_set;
set< pair< ll, ll > > nodes;
map< pair< ll, ll >, ll > nodes_index_map;
vector< ll > connections_parent(1000000);

ll find_parent(ll index_id)
{
    if(connections_parent[index_id] == index_id)
    {
        return index_id;
    }
    ll parent_index = find_parent(connections_parent[index_id]);
    connections_parent[index_id] = parent_index;
    return parent_index;
}

ll index_number(ll x, ll y, ll row_length, ll column_length, bool should_add = false)
{
    if(x == 0 || y == 0 || x == row_length || y == column_length)
    {
        x = 0;
        y = 0;
    }
    else
    {
        auto nodes_iter = nodes.find(make_pair(x, y));
        if(nodes_iter == nodes.end())
        {
            if(should_add)
            {
                ll size = nodes_index_map.size();
                nodes_index_map.insert(make_pair(make_pair(x, y), size));
            }
            else
            {
                return -1;
            }
        }
    }
    return nodes_index_map[make_pair(x, y)]; // default value is zero when no match found, also used in cases boundary edges.
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    for(ll k = 0; k < testcases; k++)
    {
        // cout << "mile 1" << "\n";
        pair_nodes_set.clear();
        nodes.clear();
        nodes_index_map.clear();
        // cout << "mile 2" << "\n";
        nodes_index_map.insert(make_pair(make_pair(0, 0), 0));
        ll rows, columns, connections;
        cin >> rows >> columns >> connections;
        ll solution = -1;
        for(ll i = 0; i <= connections * 2; i++)
        {
            connections_parent[i] = i;
        }
        for(ll i = 0; i < connections; i++)
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            if(x1 == x2)
            {
                x1 = x2 + 1;
                y1 = y2;
            }
            else
            {
                x1 = x2;
                y1 = y2 + 1;
            }
            ll index_id_1 = index_number(x1, y1, rows, columns, true);
            ll index_id_2 = index_number(x2, y2, rows, columns, true);
            ll parent_set_1 = find_parent(index_id_1);
            ll parent_set_2 = find_parent(index_id_2);
            // cout << "x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 << " index_id_1: " << index_id_1 << " index_id_2: " << index_id_2 << " parent_set_1: " << parent_set_1 << " parent_set_2: " << parent_set_2 << "\n";
            if(parent_set_1 == parent_set_2)
            {
                // cout << "0 sol" << "\n";
                solution = 0;
                break;
            }
            else if(parent_set_1 < parent_set_2)
            {
                connections_parent[parent_set_2] = parent_set_1;
            }
            else
            {
                connections_parent[parent_set_1] = parent_set_2;
            }
            nodes.insert(make_pair(x1, y1));
            nodes.insert(make_pair(x2, y2));
            pair_nodes_set.insert(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
            pair_nodes_set.insert(make_pair(make_pair(x2, y2), make_pair(x1, y1)));
        }
        ll df_x_arr[4] = {1, 0, -1, 0};
        ll df_y_arr[4] = {0, 1, 0, -1};
        if(solution == 0)
        {
            cout << solution << endl;
        }
        else
        {
            for(auto nodes_iter = nodes.begin(); nodes_iter != nodes.end(); nodes_iter++)
            {
                ll x = nodes_iter -> first;
                ll y = nodes_iter -> second;
                if(x == 0 || y == 0 || x == rows || y == columns)
                {
                    continue;
                }
                else
                {
                    for(ll i = 0; i < 4; i++)
                    {
                        ll df_x = x + df_x_arr[i];
                        ll df_y = y + df_y_arr[i];
                        auto find_iter = pair_nodes_set.find(make_pair(make_pair(x, y), make_pair(df_x, df_y)));
                        if(find_iter == pair_nodes_set.end())
                        {
                            // cout << "x: " << x << " y: " << y << " df_x: " << df_x << " df_y: " << df_y << "\n";
                            ll index_x_y = nodes_index_map[make_pair(x, y)];
                            ll index_dfx_dfy = index_number(df_x, df_y, rows, columns, false);
                            if(index_dfx_dfy >= 0)
                            {
                                ll parent_x_y = find_parent(index_x_y);
                                ll parent_dfx_dfY = find_parent(index_dfx_dfy);
                                if(parent_x_y == parent_dfx_dfY)
                                {
                                    // cout << "index_x_y: " << index_x_y << " index_dfx_dfy: " << index_dfx_dfy << " parent_x_y: " << parent_x_y << " parent_dfx_dfy: " << parent_dfx_dfY << endl;
                                    // cout << "1 sol" << "\n";
                                    solution = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(solution != -1)
                {
                    break;
                }
            }
            if(solution == -1)
            {
                cout << 2 << "\n";
            }
            else
            {
                cout << solution << "\n";
            }
        }
    }
    return 0;
}