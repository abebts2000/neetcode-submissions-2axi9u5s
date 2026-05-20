class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        # visited = set()
        startcol = image[sr][sc]
        if startcol == color:
            return image
        def dfs(i,j):
            if i < 0 or j < 0 or i >= len(image) or  j >= len(image[0]):
                return
            if image[i][j] != startcol:
                return
            prev = image[i][j]
            image[i][j] = color
            dir = [[-1,0],[0,-1],[1,0],[0,1]]
            for dx,dy in dir:
                x,y = i+dx,j+dy
                dfs(x,y)
        dfs(sr,sc)
        return image

        