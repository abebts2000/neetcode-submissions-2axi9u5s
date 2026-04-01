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
    int diameterOfBinaryTree(TreeNode* root, int& mx) {
        if(!root)
            return 0;
        int left = diameterOfBinaryTree(root->left,mx);
        int right = diameterOfBinaryTree(root->right,mx);
        int cur = 1+left+right;
        mx = max(mx,cur);
        if(left >= right)
            return 1+left;
        return  1+ right ;
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx =0;
        diameterOfBinaryTree(root,mx);
        return mx-1;
        
    }
};
