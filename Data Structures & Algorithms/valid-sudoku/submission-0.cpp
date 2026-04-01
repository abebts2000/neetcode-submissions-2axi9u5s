class Solution {
public:
    bool isvalidCell(vector<vector<char>>& board, int r, int c)
    {
        for(int i =r+1;i<board.size();i++)
        {
            if(board[i][c] != '.' && board[r][c] == board[i][c])
                return false; 
        }
        for(int j =c+1;j<board[0].size();j++)
        {
            if(board[r][j] != '.'&& board[r][c] == board[r][j])
                return false; 
        }

        int rc = 3*(r/3), cc = 3*(c/3);
        for(int i =rc;i<rc+3;i++)
            for(int j = cc; j<cc+3;j++)
            {
                if(i == r && j == c) continue;
                if(board[i][j] != '.' && board[r][c] == board[i][j])
                    return false;
            }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i =0;i<board.size();i++)
            for(int j = 0; j<board[0].size();j++) 
            {
                if(board[i][j] != '.' && !isvalidCell(board, i, j))
                    return false;
            }
        return true;
        
    }
};