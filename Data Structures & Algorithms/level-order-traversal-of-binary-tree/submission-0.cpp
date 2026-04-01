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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>res;
        q.push({root,0});
        while(!q.empty())
        {
            auto [node, level] = q.front();
            vector<int>curLevel;
            while(!q.empty() && q.front().second == level)
            {
                auto top = q.front().first;
                curLevel.push_back(top->val);
                q.pop();
                if(top->left)
                    q.push({top->left,level+1});
                if(top->right)
                    q.push({top->right,level+1});

            }
            if(curLevel.size()>0)
            {
                res.push_back(curLevel);
            }
        }
        return res;
        
    }
};
