class Solution {
public:
    void mark(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O')
            return;
        board[r][c] = 'T';
        mark(board, r + 1, c);
        mark(board, r - 1, c);
        mark(board, r, c + 1);
        mark(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            mark(board, i, 0);
            mark(board, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            mark(board, 0, j);
            mark(board, rows - 1, j);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};