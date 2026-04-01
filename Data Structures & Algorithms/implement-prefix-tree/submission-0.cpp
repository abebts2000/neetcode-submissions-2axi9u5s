struct TrieNode
{
    unordered_map<char, TrieNode*>childs;
    bool isWord = false;
};

class PrefixTree {
    TrieNode*trie = new TrieNode();
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        auto root = trie;
        for(auto e:word)
        {
            if(root->childs.find(e) == root->childs.end())
                root->childs[e] = new TrieNode();
            root = root->childs[e];            
        }
        root->isWord = true;

        
    }
    
    bool search(string word) {
       auto root = trie; 
       for(auto e:word)
        {
            if(root->childs.find(e) == root->childs.end())
                return false;   
            root = root->childs[e];     
        }
        return root->isWord;
    }
    
    bool startsWith(string prefix) {

         auto root = trie; 
       for(auto e:prefix)
        {
            if(root->childs.find(e) == root->childs.end())
                return false;   
            root = root->childs[e];     
        }
        return true;
    }
};
