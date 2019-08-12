#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll maximum = 10000000000000;

ll build_segment_tree(ll left, ll right, ll position, vector< ll > &min_vals, vector< ll > &segment_tree, vector< ll > &lazy_segment_tree)
{
	if(left == right)
	{
		segment_tree[position] = min_vals[left];
		lazy_segment_tree[position] = 0;
		return segment_tree[position];
	}
	ll mid = (left + right) / 2;
	ll left_val = build_segment_tree(left, mid, 2 * position + 1, min_vals, segment_tree, lazy_segment_tree);
	ll right_val = build_segment_tree(mid + 1, right, 2 * position + 2, min_vals, segment_tree, lazy_segment_tree);
	segment_tree[position] = left_val < right_val ? left_val : right_val; 
	return min(left_val, right_val);
}

ll update_segment_tree(ll left, ll right, ll range_left, ll range_right, ll update_val, ll position, vector< ll > &segment_tree, vector< ll > &lazy_segment_tree)
{
	if(lazy_segment_tree[position] != 0)
	{
		segment_tree[position] += lazy_segment_tree[position];
		lazy_segment_tree[2 * position + 1] += lazy_segment_tree[position];
		lazy_segment_tree[2 * position + 2] += lazy_segment_tree[position];
		lazy_segment_tree[position] = 0;
	}
	
	if(range_right < left or range_left > right)
	{
		return segment_tree[position];
	}
	
	if(left == right)
	{
		segment_tree[position] += update_val;
		return segment_tree[position];
	}

	if(range_left <= left and range_right >= right)
	{
		segment_tree[position] += update_val;
		lazy_segment_tree[2 * position + 1] += update_val;
		lazy_segment_tree[2 * position + 2] += update_val;
		return segment_tree[position];
	}

	ll mid = (left + right) / 2;
	ll left_val = update_segment_tree(left, mid, range_left, range_right, update_val, 2 * position + 1, segment_tree, lazy_segment_tree);
	ll right_val = update_segment_tree(mid + 1, right, range_left, range_right, update_val, 2 * position + 2, segment_tree, lazy_segment_tree);
	return min(left_val, right_val);
}

ll range_query(ll left, ll right, ll range_left, ll range_right, ll position, vector< ll > &segment_tree, vector< ll > &lazy_segment_tree)
{
	if(lazy_segment_tree[position] != 0)
	{
		segment_tree[position] += lazy_segment_tree[position];
		lazy_segment_tree[2 * position + 1] += lazy_segment_tree[position];
		lazy_segment_tree[2 * position + 2] += lazy_segment_tree[position];
		lazy_segment_tree[position] = 0; 
	}
	
	if(range_right < left or range_left > right)
	{
		return maximum;
	}
	
	if(left == right)
	{
		return segment_tree[position];
	}

	if(range_left <= left and range_right >= right)
	{
		return segment_tree[position];
	}

	ll mid = (left + right) / 2;
	ll left_val = range_query(left, mid, range_left, range_right, 2 * position + 1, segment_tree, lazy_segment_tree);
	ll right_val = range_query(mid + 1, right, range_left, range_right, 2 * position + 2, segment_tree, lazy_segment_tree);
	return min(left_val, right_val);
}

int main()
{
	vector< ll > min_vals{-1, 2, 4, 1, 7, 1, 3, 2};
	vector< ll > segment_tree(4 * min_vals.size() + 1);
	vector< ll > lazy_segment_tree(4 * min_vals.size() + 1);
	build_segment_tree(0, min_vals.size() - 1, 0, min_vals, segment_tree, lazy_segment_tree);
	update_segment_tree(0, min_vals.size() - 1, 0, 3, 3, 0, segment_tree, lazy_segment_tree);
	update_segment_tree(0, min_vals.size() - 1, 0, 3, 1, 0, segment_tree, lazy_segment_tree);
	update_segment_tree(0, min_vals.size() - 1, 0, 0, 2, 0, segment_tree, lazy_segment_tree);
	update_segment_tree(0, min_vals.size() - 1, 4, 5, 3, 0, segment_tree, lazy_segment_tree);
	ll min_val = range_query(0, min_vals.size() - 1, 3, 5, 0, segment_tree, lazy_segment_tree);
	cout << min_val << "\n";
	return 0;
}