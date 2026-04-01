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

    bool isValidBST(TreeNode* root,int mn, int mx) {
        if(!root)
            return true;
        return (root->val > mn && root->val < mx)&& isValidBST(root->left, mn,root->val) && isValidBST(root->right, root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,numeric_limits<int>::min(),numeric_limits<int>::max());
    }
};
