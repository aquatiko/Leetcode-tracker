/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* a) {
    vector<vector<int>> ans;
    queue<pair<TreeNode*,int>> q;
    q.push({a, 0});

    while(q.size())
    {
        pair<TreeNode*, int> top = q.front();
        q.pop();
        if(ans.size()>top.second)
            ans[top.second].push_back(top.first->val);
        else
        ans.push_back({top.first->val});

        if(top.first->left)
        q.push({top.first->left, top.second+1});

        if(top.first->right)
        q.push({top.first->right, top.second+1});
    }
    a
    return ans;
}
