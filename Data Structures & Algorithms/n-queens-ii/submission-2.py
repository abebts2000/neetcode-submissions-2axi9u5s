class Solution:
    def totalNQueens(self, n: int) -> int:
        grid = [[0]*n for _ in range(n)]
        self.count = 0
        def check(r,c):
            #check row
            for i in range(n):
                if grid[r][i] == 1 and i != c:
                    return False
            #check column
            for i in range(n):
                if grid[i][c] == 1 and i != r:
                    return False
            #check diagonals
            dirs = [(1,-1), (-1,1), (-1,-1), (1,1)]
            for dr, dc in dirs:
                i, j = r + dr, c + dc
                while 0 <= i < n and 0 <= j < n:
                    if grid[i][j] == 1:
                        return False
                    i += dr
                    j += dc
            return True
        def solve(r):
            if r == n:
                self.count += 1
                return
            for j in range(n):
                grid[r][j] = 1
                if check(r, j):
                    solve(r + 1)
                grid[r][j] = 0
        solve(0)
        return self.count