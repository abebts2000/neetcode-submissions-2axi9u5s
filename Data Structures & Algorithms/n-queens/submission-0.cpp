class Solution {
public:

    void isValid(vector<string>grid, int r, vector<vector<string>>&res)
    {
        if(r == grid.size())
        {
            res.push_back(grid);
            return;
        }
        
        for(int c = 0; c < grid.size(); c++) {
            bool possible = true;
            for(int i = 0; i < r; i++)
            {
                if(grid[i][c] == 'Q')
                    possible = false;
            }
            int i = r-1, j = c-1;
            while(i >= 0 && j >= 0)
            {
               if(grid[i][j] == 'Q')
                    possible = false; 
                i--, j--;
            }
            i = r-1, j = c+1;
            while(i >= 0 && j < grid.size())
            {
               if(grid[i][j] == 'Q')
                    possible = false; 
                i--, j++;
            }

            if(possible) {
                grid[r][c] = 'Q';
                isValid(grid, r + 1, res);
                grid[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> res;
        isValid(grid, 0, res);
        return res;
    }
};