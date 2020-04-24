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
class compare
{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> heap;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                heap.push(lists[i]);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *ptr= dummy;

        while(heap.size()>0)
        {
            ptr->next = heap.top();
            ptr = ptr->next;

            ListNode *tmp = (heap.top())->next;
            heap.pop();
            if(tmp)
                heap.push(tmp);
        }
        return dummy->next;
    }
};

// using comparator in a priority_queue implementation is key concept here.
