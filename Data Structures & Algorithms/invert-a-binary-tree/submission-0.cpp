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
    void invertTree2(TreeNode* root) {
        if(!root)
            return ;
        auto left = root->left;
        root->left = root->right;
        root->right = left;
        invertTree2(root->left);
        invertTree2(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTree2(root);
        return root;
    }
};
