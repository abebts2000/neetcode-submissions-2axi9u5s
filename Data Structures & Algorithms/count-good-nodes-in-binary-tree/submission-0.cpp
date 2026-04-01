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
    void goodNodes(TreeNode* root, int mx, int& total) {
        if(!root)
            return;
        if(root->val >= mx)
            total +=1;
            mx= max(root->val,mx);
        goodNodes(root->left,mx,total);
        goodNodes(root->right,mx,total);

    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int total =0;
        goodNodes(root,root->val,total);
        return total;
    }
};
