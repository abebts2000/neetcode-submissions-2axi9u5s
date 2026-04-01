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
    pair<pair<int,int>,bool> height(TreeNode* root)
    {
        if(!root)
            return {{0,0},true};
        auto left = height(root->left);
        if(!left.second)
            return left;
        auto right = height(root->right);
        if(!right.second)
            return right;
        bool cmp = abs(max(left.first.first,left.first.second)-max(right.first.first,right.first.second))<=1;
        return {{1+max(left.first.first,left.first.second),1+max(right.first.first,right.first.second)},cmp};
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        auto res = height(root);
        return res.second;
    }
};
