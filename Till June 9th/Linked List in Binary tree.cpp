/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    ListNode *start;
    unordered_map<pair<ListNode*, TreeNode*>, bool, hash_pair> mp;
    bool isSubPath(ListNode* head, TreeNode* root) {
        start = head;
        return isSubPathi(head, root);
    }
    bool isSubPathi(ListNode* head, TreeNode* root) {
        if(!head)
            return true;
        if(!root && head)
            return false;
        if(mp.find({head, root})!=mp.end())
            return mp[{head, root}];

        bool res1=false, res2=false;
        res1 = isSubPathi(start, root->left) | isSubPathi(start, root->right);
        if(head->val == root->val)
        res2 = isSubPathi(head->next, root->left) | isSubPathi(head->next, root->right);

        return mp[{head, root}] = res1 | res2;
    }
};

// Made a logical error while calculating res1, the head ppinter needs to go back to it's 0th pos i.e start ptr in that case.
