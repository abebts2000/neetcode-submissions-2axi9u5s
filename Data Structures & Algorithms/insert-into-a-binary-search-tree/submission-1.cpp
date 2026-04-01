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
    void insertIntoBST2(TreeNode* root, int val) {
        if(!root)
            return;
        if(root->val > val)
        {
            if(root->left)
                insertIntoBST2(root->left,val);
            else
            {
                root->left = new TreeNode(val);
                return;
            }
        }
        else if(root->val < val)
        {
            if(root->right)
                insertIntoBST2(root->right,val);
            else
            {
                root->right = new TreeNode(val);
                return;
            }
        }

    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto head = root;
        if(!root)
            return new TreeNode(val);
        insertIntoBST2(root,val);
        return head;
    }
};