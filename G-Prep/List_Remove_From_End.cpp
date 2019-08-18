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
    ListNode* recurse_and_remove(ListNode *head, int n, int size_from_beginning, int &size_from_end)
    {
        size_from_beginning += 1;
        ListNode *next_head = NULL;
        if(head -> next)
        {            
            next_head = recurse_and_remove(head -> next, n, size_from_beginning, size_from_end);
        }
        if(size_from_end == n)
        {
            head -> next = next_head -> next;
            next_head = NULL;
        }
        size_from_end += 1;
        if(size_from_end == n and size_from_beginning == 1)
        {
            if(next_head)
            {
                head = next_head;
            }
            else
            {
                head = NULL;
            }
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int size_from_end = 0;
        int size_from_beginning = 0;
        head = recurse_and_remove(head, n, size_from_beginning, size_from_end);
        return head;
    }
};