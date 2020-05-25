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
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
    vector<TreeNode*> solve(int l, int r)
    {
        if(l>r)
            return {};
        if(l == r)
            return {new TreeNode(l)};

        vector<TreeNode*> ans;

        for(int i=l;i<=r;i++)
        {
            vector<TreeNode*> leftans, rightans;
            leftans = solve(l,i-1);
            rightans = solve(i+1,r);

            if(rightans.size()==0)
            for(auto itr = leftans.begin();itr!=leftans.end();itr++)
            {
                TreeNode *tmp = new TreeNode(i);
                tmp->left = *itr;
                ans.push_back(tmp);
            }

            if(leftans.size()==0)
            for(auto itr = rightans.begin();itr!=rightans.end();itr++)
            {
                TreeNode *tmp = new TreeNode(i);
                tmp->right = *itr;
                ans.push_back(tmp);
            }
            for(auto itr1 = leftans.begin();itr1!=leftans.end();itr1++)
            {
                for(auto itr2 = rightans.begin();itr2!=rightans.end();itr2++)
                {   TreeNode *tmp = new TreeNode(i);
                    tmp->left = *itr1;
                    tmp->right = *itr2;
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
