class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        parent = {}
        rank = {}
        seen = set()
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x,y):
            px = find(x)
            py = find(y)
            if px != py:
                if rank[px]<rank[py]:
                    parent[px] = py
                    rank[py]+=rank[px]
                else:
                    parent[py] = px
                    rank[px]+=rank[py]
        def dfs(i,j):
            if i>=0 and j >=0 and i< len(grid) and j < len(grid[0]):
                seen.add((i,j))
            for d in dir:
                x2,y2=i+d[0],j+d[1]
                if x2>=0 and y2 >=0 and x2< len(grid) and y2 < len(grid[0]) and grid[x2][y2]==1 and (x2,y2) not in seen:
                    parent[(x2,y2)] = (x2,y2)
                    rank[(x2,y2)] = 1
                    union((i,j),(x2,y2))
                    dfs(x2,y2)

        dir = [[-1,0],[0,-1],[1,0],[0,1]]
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j] == 1 and (i,j) not in seen:
                    parent[(i,j)] = (i,j)
                    rank[(i,j)] = 1
                    dfs(i,j)
        mx = 0
        for values in rank.values():
            mx = max(mx,values)
        return mx
        
        

        