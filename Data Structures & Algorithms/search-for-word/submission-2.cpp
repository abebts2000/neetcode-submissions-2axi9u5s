class Solution {
public:
    bool DFS(const vector<vector<char>>& board, int r, int c, string sofar, string word, unordered_set<int>&st)
    {
        if(sofar.length() > word.length())
            return false;
        if(sofar == word)
            return true;
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto e:dir)
        {
            int x = r+e[0];
            int y = c+e[1];
            int cell = x*board[0].size()+y;
            if(x<0 || y < 0 || x>=board.size() || y >= board[0].size() || st.find(cell) != st.end())
                continue;
            sofar += board[x][y];
            st.insert(cell);
            if(DFS(board,x,y,sofar,word,st))
                return true;
            sofar.pop_back();
            st.erase(cell);
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();i++)
        {
            for(int j =0;j<board[0].size();j++)
            {
                unordered_set<int>st = {i*board[0].size()+j};
                string sofar="";
                if(DFS(board,i,j,sofar+board[i][j],word,st))
                    return true;
            }
        } 
        return false;
    }
};
