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
    int maxPathSumHelper(TreeNode* root, int &mx) 
    {
        if(!root)
            return numeric_limits<int>::min();
        auto left = std::max(0,maxPathSumHelper(root->left, mx));
        auto right = std::max(0,maxPathSumHelper(root->right, mx));

        mx = std::max(root->val+left+right,mx);
        return std::max(0,std::max(root->val+left, root->val+right));

    }
    int maxPathSum(TreeNode* root) {
        //if left sum <=0, return 0
        //if right sum <=0, return 0
        //then return root + max(left,right) to parent. 
        //Also compare if the left+root+right  is max or not
        int mx = numeric_limits<int>::min();
        maxPathSumHelper(root,mx);
        return mx;

    }
};
