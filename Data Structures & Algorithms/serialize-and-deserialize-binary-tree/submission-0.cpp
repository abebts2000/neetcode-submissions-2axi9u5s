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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#,";
        return std::to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int indx = 0;
        vector<string> nodes;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        if (nodes.empty()) return nullptr;
        return deserialize(nodes, indx);
    }

    TreeNode* deserialize(vector<string>& data, int& indx) {
        if (indx >= data.size() || data[indx] == "#") {
            return nullptr;
        }
        TreeNode*newNode = new TreeNode(std::stoi(data[indx]));
        indx = indx+1;
        newNode->left = deserialize(data, indx);
        indx = indx+1;
        newNode->right = deserialize(data, indx);
        return newNode;
    }
};
