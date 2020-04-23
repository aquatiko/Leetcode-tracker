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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for(int i=0;i<n;i++)
            fast = fast->next;

        while(fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(!fast)
            return head->next;

        if(slow->next && slow->next->next)
            slow->next = slow->next->next;
        else
            slow->next = NULL;

        return head;
    }
};

// Writng lean code while covering all the test cases is the essence of this question.
