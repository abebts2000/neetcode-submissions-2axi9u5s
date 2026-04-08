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
    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder, int l, int r, int& indx,
                        unordered_map<int,pair<int,int>>&mp) {
                            if(l > r)
                                return nullptr;
                            
                            int rootVal = preorder[indx++];
                            TreeNode* node = new TreeNode(rootVal);
                            int mid = mp[rootVal].second;
                            
                            node->left = buildTree2(preorder, inorder, l, mid - 1, indx, mp);
                            node->right = buildTree2(preorder, inorder, mid + 1, r, indx, mp);
                            return node;
                        }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,pair<int,int>>mp;
        //{preorder,inorder}
        for(int i =0;i<preorder.size();i++)
        {
            mp[preorder[i]].first = i;
            mp[inorder[i]].second = i;
        }
        int indx = 0;
        return buildTree2(preorder, inorder, 0, (int)preorder.size() - 1, indx, mp);
    }
};
