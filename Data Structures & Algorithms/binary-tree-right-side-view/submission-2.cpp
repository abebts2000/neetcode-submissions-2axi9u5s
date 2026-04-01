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
    void rightSideView(TreeNode* root, vector<int>&res)
    {
        if(!root)
            return;
        res.push_back(root->val);
        if(root->right)
            rightSideView(root->right,res);
        else
           rightSideView(root->left,res); 
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int>res;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty())
        {
            auto [level, top] = q.front();
            res.push_back(top->val);
            while(!q.empty() && q.front().first == level)
            {
                auto node = q.front().second;
                q.pop();
                if(node->right)
                    q.push({level+1,node->right});
                if(node->left)
                    q.push({level+1,node->left});
            }
        }


        return res;
    }
};
