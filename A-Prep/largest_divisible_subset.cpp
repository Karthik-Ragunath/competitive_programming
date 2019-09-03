class Node
{
    public:
        int val;
        Node *next;
        Node(int x) : val(x), next(NULL) {}
};

class Solution 
{
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) 
        {
            if(nums.empty())
            {
                return nums;
            }
            sort(nums.begin(), nums.end());
            unordered_map< int, Node* > num_memory_maps;
            unordered_map< int, int > max_sub_set_size;
            int global_max_sub_set_size = 0;
            int global_max_sub_set_index = -1;
            for(int i = 0; i < nums.size(); i++)
            {
                Node *node = new Node(nums[i]);
                int local_max_sub_set_size = 0;
                int local_max_index = -1;
                for(int k = 0; k < i; k++)
                {
                    if(nums[i] % nums[k] == 0)
                    {
                        if(max_sub_set_size[k] > local_max_sub_set_size)
                        {
                            local_max_sub_set_size = max_sub_set_size[k];
                            local_max_index = k;
                            // cout << "Index: " << local_max_index << " Max sub set size: " << local_max_sub_set_size << "\n";
                        }
                    }
                }
                if(local_max_index == -1)
                {
                    num_memory_maps[i] = node;
                }
                else
                {
                    // cout << "milestone 1" << "\n";
                    Node *temp_node = num_memory_maps[local_max_index];
                    node -> next = temp_node;
                    num_memory_maps[i] = node;
                }
                local_max_sub_set_size += 1;
                max_sub_set_size[i] = local_max_sub_set_size;
                if(local_max_sub_set_size > global_max_sub_set_size)
                {
                    global_max_sub_set_index = i;
                    global_max_sub_set_size = local_max_sub_set_size;
                }
            }
            Node *solution = num_memory_maps[global_max_sub_set_index];
            vector< int > solution_vec;
            while(solution)
            {
                solution_vec.push_back(solution -> val);
                solution = solution -> next;
            }
            return solution_vec;
        }
};