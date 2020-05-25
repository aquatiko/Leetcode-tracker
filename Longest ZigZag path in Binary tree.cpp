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
    int ans;
    int longestZigZag(TreeNode* root) {
        ans = 0;
        pair<int,int> res = solve(root);
        ans = max(ans, max(res.first, res.second));
        return ans;
    }
    pair<int,int> solve(TreeNode* root)
    {
        if(!root)
            return {-1,-1};
        if(!root->left && !root->right)
            return {0,0};

        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        ans = max(ans, max(left.first, max(left.second, max(right.first, right.second))));
        return {1+left.second, 1+right.first};
    }
};
