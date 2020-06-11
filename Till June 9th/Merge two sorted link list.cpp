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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode* ptr = dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }

        while(l1)
        {
            ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
        }

        while(l2)
        {
             ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
        }

        return dummy->next;
    }
};
