struct TrieNode
{
    char ch;
    bool isWord = false;
    unordered_map<char,TrieNode*>childs;
    TrieNode(char c):ch(c){}
    TrieNode(){}
};

class WordDictionary {
    TrieNode*trie = new TrieNode();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
      auto root = trie;
      for(auto e:word)
       {
        if(root->childs.find(e) == root->childs.end())
            root->childs[e] = new TrieNode(e);
        root = root->childs[e];
       } 
       root->isWord = true;
    }
    
    bool search2(string word, int indx, TrieNode*root)
    {
        if(indx == word.length())
            return root->isWord;
        if(word[indx]=='.')
        {
            for(auto e:root->childs)
            {
                if(search2(word,indx+1,e.second))
                    return true;
            }
            return false;
        }
        else
        {
            if(root->childs.find(word[indx]) == root->childs.end())
                return false;
            if(search2(word,indx+1,root->childs[word[indx]]))
                return true;
        }
        return false;
    }

    bool search(string word) {
        return search2(word,0,trie);
        
    }
};
