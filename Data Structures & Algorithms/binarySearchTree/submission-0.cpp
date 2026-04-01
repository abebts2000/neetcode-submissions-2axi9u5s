struct TreeNode
{
    TreeNode*left,*right;
    pair<int,int>val;
    TreeNode(pair<int,int>val): val(val),left(nullptr),right(nullptr) {}
};

class TreeMap {
    TreeNode *tree = nullptr;
public:
    TreeMap() {
        
    }
    void inserthelper(int key, int val, TreeNode*root)
    {
        if(root->val.first > key)
        {
            if(!root->left)
                root->left = new TreeNode({key,val});
            else
                inserthelper(key,val,root->left);
        }
        else if(root->val.first < key)
        {
            if(!root->right)
                root->right = new TreeNode({key,val});
            else
                inserthelper(key,val,root->right);
        }
        else
            root->val.second = val;
        

    }
    void insert(int key, int val) {

        if(!tree)
            tree = new TreeNode({key,val});
        else
            inserthelper(key,val,tree);
    }

    int get(int key, TreeNode*root) {
        if(!root)
            return -1;
        if(root->val.first == key)
            return root->val.second;
        if(root->val.first > key)
            return get(key,root->left);
        return get(key,root->right);
    }
    
    int get(int key) {
        return get(key,tree);
    }

     int getMin(TreeNode*root) {
        if(!root) return -1;
        if(root->left)
            return getMin(root->left);
        return root->val.second;
        
    }

    int getMin() {
        return getMin(tree);
    }
    int getMax(TreeNode*root) {
     if(!root) return -1;
     if(root->right)
            return getMax(root->right);
        return root->val.second;
    }
    int getMax() {
        return getMax(tree);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    TreeNode* remove(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val.first) root->left = remove(root->left, key);
        else if (key > root->val.first) root->right = remove(root->right, key);
        else {
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root; return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = remove(root->right, temp->val.first);
        }
        return root;
    }

    void remove(int key) {
        tree = remove(tree, key);
    }

     void getInorderKeys(TreeNode*root, std::vector<int>&res) {
        if(!root)
            return;
        getInorderKeys(root->left,res);
        res.push_back(root->val.first);
        getInorderKeys(root->right,res);
    
    }


    std::vector<int> getInorderKeys() {
        std::vector<int>res;
        getInorderKeys(tree,res);
        return res;
    
    }
};
