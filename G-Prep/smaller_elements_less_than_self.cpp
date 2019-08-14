class Solution {
public:
    void update_fenwick_tree(vector< int > &fenwick_tree, int index)
    {
        int fenwick_tree_size = fenwick_tree.size();
        while(index <= fenwick_tree_size)
        {
            fenwick_tree[index] += 1;
            index += (index & (-index));
        }
    }
    
    int query_fenwick_tree(vector< int > &fenwick_tree, int index)
    {
        int solution = 0;
        while(index > 0)
        {
            solution += fenwick_tree[index];
            index -= (index & (-index));
        }
        return solution;
    }
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        int nums_size = nums.size();
        vector< int > fenwick_tree(100000);
        int half_of_fen_size = 100000 / 2;
        vector< int > solution_vec(nums_size);
        for(int i = nums_size - 1; i >= 0; i--)
        {
            nums[i] = nums[i] + half_of_fen_size;
            int solution = query_fenwick_tree(fenwick_tree, (nums[i] - 1));
            solution_vec[i] = solution;
            update_fenwick_tree(fenwick_tree, nums[i]);
        }
        return solution_vec;
    }
};