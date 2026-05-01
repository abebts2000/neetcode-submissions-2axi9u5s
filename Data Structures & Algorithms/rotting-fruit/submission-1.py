class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        q = deque()
        fresh = 0
        c   = 0
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j] == 2:
                    q.append([i,j])
                if grid[i][j] == 1:
                    fresh+=1
        dir = [[-1,0],[0,-1],[1,0],[0,1]]
        while q and fresh > 0:
            l = len(q)
            while l >0:
                l-=1
                x,y = q.popleft()
                for d in dir:
                    x2,y2 = x+d[0],y+d[1]
                    if x2 >=0 and y2 >=0 and x2 <len(grid) and y2 < len(grid[0]) and grid[x2][y2] ==1:
                        fresh-=1
                        grid[x2][y2] = 2
                        q.append([x2,y2])
            c+=1
        return c if fresh ==0 else -1

