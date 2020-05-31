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
    unordered_map<int, int> res;
    int maxi;
    int maxLevelSum(TreeNode* root) {
        maxi = 1;
        solve(root, 1);
        int ans = 1;
        for(int i=2;i<=maxi;i++)
            if(res[i]>res[ans])
                ans = i;
        return ans;
    }
    void solve(TreeNode *root, int level)
    {
        if(!root)
            return;

        res[level]+=root->val;
        maxi = max(maxi, level);
        solve(root->left, level+1);
        solve(root->right, level+1);
    }
};

// space can be improved to O(1) using a BFS traversal.
