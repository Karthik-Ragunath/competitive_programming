/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void print_vec(vector< int > &solution_vec)
	{
		for(int i = 0; i < solution_vec.size(); i++)
		{
			cout << solution_vec[i] << " ";
		}
		cout << "\n";
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        /*
        vector< ll > list_indices(lists.size());
        iota(list_indices.begin(), list_indices.begin() + lists.size(), 0);
        unordered_set< int > active_set(list_indixes.begin(), list_indices.end());
        */
        // vector< int > solution_vec;
        unordered_set< int > active_set;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
        	    active_set.insert(i);
            }
        }
        int test_index = 0;
        if(!active_set.empty())
        {
            ListNode *solution_node = new ListNode(0);
            ListNode *iterator_node = solution_node;
            while(!active_set.empty() and test_index < 2)
            {
                bool is_first_val = true;
                int min_value = -1;
                int min_val_index = -1;
                for(auto iter = active_set.begin(); iter != active_set.end(); iter++)
                {
                    ListNode *list_node = lists[*iter];
                    // cout << "index: " << *iter << " val: " << list_node -> val << "\n";
                    if(is_first_val)
                    {
                        min_value = list_node -> val;
                        is_first_val = false;
                        min_val_index = *iter;
                    }
                    else
                    {
                        int val = list_node -> val;
                        if(val < min_value)
                        {
                            min_value = val;
                            min_val_index = *iter;
                        }
                    }
                }
                // solution_vec.push_back(min_value);
                lists[min_val_index] = lists[min_val_index] -> next;
                if(lists[min_val_index] == NULL)
                {
                    active_set.erase(min_val_index);
                }
                iterator_node -> val = min_value;
                if(!active_set.empty())
                {
                    iterator_node -> next = new ListNode(0);
                    iterator_node = iterator_node -> next;
                }
            }
            // print_vec(solution_vec);
            return solution_node;
        }
        else
        {
            return NULL;
        }
    }
};