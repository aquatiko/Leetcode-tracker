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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;

        ListNode *ptr = dummy;

        while(ptr->next && ptr->next->next)
        {
            ListNode* first = ptr->next;
            ListNode* second = ptr->next->next;

            ptr->next = second;
            first->next = second->next;
            second->next = first;

            ptr = ptr->next->next;
        }
        return dummy->next;
    }
};
