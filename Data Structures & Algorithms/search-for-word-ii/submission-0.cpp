struct TrieNode
{
    unordered_map<char,TrieNode*>childs;
    bool isWord = false;
};

struct Trie
{
    TrieNode*root = new TrieNode();
    void insert(string s)
    {
        auto temp = root;
        for(auto e:s)
        {
            if(temp->childs.find(e) == temp->childs.end())
                temp->childs[e] = new TrieNode();
            temp = temp->childs[e];
        }
        temp->isWord = true;
    }

    bool isPrefix(string s)
    {
        auto temp = root;
        for(auto e:s)
        {
            if(temp->childs.find(e) == temp->childs.end())
                return false;
            temp = temp->childs[e];
        }
        return true;
    }
    bool search(string s)
    {
        auto temp = root;
        for(auto e:s)
        {
            if(temp->childs.find(e) == temp->childs.end())
                return false;
            temp = temp->childs[e];
        }
        return temp->isWord;
    }
};

class Solution {
public:
    void findWords(vector<vector<char>>& board, Trie trie, int r, int c, unordered_set<int>st, string sofar, unordered_set<string>&res)
    {
        int cell = r*board[0].size()+c;
        if(r < 0 || c < 0 || r>= board.size() || c >= board[0].size() || 
            st.find(cell) != st.end())
            return;
        sofar += board[r][c];
        if(!trie.isPrefix(sofar))
            return;
        if(trie.search(sofar))
            res.insert(sofar);
        st.insert(cell);
        //vector<vector<int>>dir = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto e:dir)
        {
            int i = r+e[0];
            int j = c+e[1];
            findWords(board,trie,i,j,st,sofar,res);
        }

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie  trie;
        for(auto e:words)
        {
            trie.insert(e);
        }

        unordered_set<string>res;
        for(int i =0;i<board.size();i++)
            for(int j =0;j<board[0].size();j++)
            {
                unordered_set<int>st;
                findWords(board,trie,i,j,st,"",res);
            }
        return vector<string>{res.begin(),res.end()};
    }
};
