/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* old, unordered_map<int,Node*>&dict)
    {
        if(!old)
            return nullptr;
        if(dict.find(old->val) != dict.end())
        {
            return dict[old->val];
        }
        dict[old->val] = new Node(old->val);
        for(auto e:old->neighbors)
        {
            dict[old->val]->neighbors.push_back(clone(e,dict));
        }
        return dict[old->val];
        
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*>dict;
        return clone(node,dict);
    }
};
