/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *ptr = dummy;

        while(ptr)
        {
            ListNode *nextGroupStart, *ptrNextGroup;
            ListNode *tmp = ptr;

            for(int i=0;i<k && tmp;i++)
            {
                tmp = tmp->next;
            }

            if(!tmp)
                break;

            nextGroupStart = tmp->next;
            tmp->next = NULL;

            ptr->next = reverseList(ptr->next, nextGroupStart);

            for(int i=0;i<k;i++)
            {ptr = ptr->next;cout<<ptr->val<<" ";}
        }

        return dummy->next;
    }

    ListNode* reverseList(ListNode *head, ListNode *prev)
    {
        ListNode *next;

        while(head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// Modularization and thinking systematically step by step helped solve considering all cases.
