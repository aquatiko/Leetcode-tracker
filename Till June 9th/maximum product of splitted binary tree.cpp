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
class Solution {
public:
    long ans;
    unordered_map<TreeNode*, int> mp;
    int maxProduct(TreeNode* root) {
        ans = 0;
        precompute(root);
        solve(root, root->val);
        return ans%1000000007;
    }
    int precompute(TreeNode *root)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return  mp[root] = root->val;

        int leftsum = precompute(root->left);
        int rightsum = precompute(root->right);

        int res = leftsum + rightsum + root->val;
        mp[root] = res;
        return res;
    }

    void solve(TreeNode* root, int upper_sum)
    {
        if(!root)
            return;
        if(root->left)
        ans = max(ans, (long)(mp[root->left])*(root->right? upper_sum + mp[root->right] : upper_sum));

        if(root->right)
        ans = max(ans, (long)(mp[root->right])*(root->left? upper_sum + mp[root->left] : upper_sum));

        if(root->left)
        solve(root->left, upper_sum + root->left->val + (root->right? mp[root->right] : 0));
        if(root->right)
        solve(root->right, upper_sum + root->right->val + (root->left? mp[root->left] : 0));
    }
};
