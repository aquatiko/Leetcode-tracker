/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *head = new TreeNode(preorder[0]);

        for(int i=1;i<preorder.size();i++)
            placeElement(preorder[i],head);

        return head;
    }

    void placeElement(int element, TreeNode *head)
    {
        if(!head)
            return;

        if(element<head->val)
        {
            if(!head->left)
            {
                head->left = new TreeNode(element);
                return;
            }
            else
                placeElement(element, head->left);
        }
        else
        {
            if(!head->right)
            {
                head->right = new TreeNode(element);
                return;
            }
            else
                placeElement(element, head->right);
        }

    }
};
