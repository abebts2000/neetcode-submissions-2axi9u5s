class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        st = set()
        def dfs(i,j):
            if (i,j) in st:
                return 0
            if i<0 or j < 0 or i>=len(grid) or j >= len(grid[0]) :
                return 1
            if grid[i][j] == 0:
                return 1
            st.add((i,j))
            return dfs(i+1,j)+dfs(i-1,j)+dfs(i,j-1)+dfs(i,j+1)
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return dfs(i,j)
        

            

        