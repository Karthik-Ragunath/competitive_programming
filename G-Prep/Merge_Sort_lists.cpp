/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
        ListNode* merge_sort(int left, int right, vector< ListNode* > &lists)
        {
            if(left == right)
            {
                return lists[left];
            }
            int mid = (left + right) / 2;
            ListNode *left_merged_list_pointer = merge_sort(left, mid, lists);
            ListNode *right_merged_list_pointer = merge_sort(mid + 1, right, lists);
            if(not left_merged_list_pointer and not right_merged_list_pointer)
            {
                return NULL;
            }
            ListNode *merged_pointer_head = new ListNode(0);
            ListNode *merged_pointer_cursor = merged_pointer_head;
            // cout << "initial vals: " << left_merged_list_pointer -> val << " " << right_merged_list_pointer -> val << "\n";

            while(left_merged_list_pointer and right_merged_list_pointer)
            {
                if(left_merged_list_pointer -> val < right_merged_list_pointer -> val)
                {
                    merged_pointer_cursor -> val = left_merged_list_pointer -> val;
                    left_merged_list_pointer = left_merged_list_pointer -> next;
                    merged_pointer_cursor -> next = new ListNode(0);
                    merged_pointer_cursor = merged_pointer_cursor -> next;
                }
                else
                {
                    merged_pointer_cursor -> val = right_merged_list_pointer -> val;
                    right_merged_list_pointer = right_merged_list_pointer -> next;
                    merged_pointer_cursor -> next = new ListNode(0);
                    merged_pointer_cursor = merged_pointer_cursor -> next;
                }
            }
            ListNode *unfinished_traversal = new ListNode(0);
            if(left_merged_list_pointer)
            {
                unfinished_traversal = left_merged_list_pointer;
            }
            else 
            {
                unfinished_traversal = right_merged_list_pointer;
            }
            while(unfinished_traversal)
            {
                merged_pointer_cursor -> val = unfinished_traversal -> val;
                // cout << unfinished_traversal -> val << "\n";
                unfinished_traversal = unfinished_traversal -> next;
                if(unfinished_traversal)
                {
                    merged_pointer_cursor -> next = new ListNode(0);
                }
                merged_pointer_cursor = merged_pointer_cursor -> next;
            }
            merged_pointer_cursor = NULL;// To handle case when both left and right are empty
            return merged_pointer_head;
        }

        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            if(not lists.empty())
            {
                ListNode *sorted_pointer_head = merge_sort(0, lists.size() - 1, lists);
                return sorted_pointer_head;
            }
            else
            {
                return NULL;
            }
        }
};