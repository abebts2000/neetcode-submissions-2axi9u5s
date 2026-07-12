class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        bldgs = []
        total_dist = defaultdict(int)
        reach_count = defaultdict(int)
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    bldgs.append((r, c))
        
        for r, c in bldgs:
            q = deque([(r, c, 0)])
            visited = set([(r, c)])
            dirs = [(-1, 0), (0, -1), (0, 1), (1, 0)]
            while q:
                curr_r, curr_c, dist = q.popleft()
                if grid[curr_r][curr_c] == 0:
                    total_dist[(curr_r,curr_c)] += dist
                    reach_count[(curr_r,curr_c)] += 1
                
                for dx, dy in dirs:
                    x, y = curr_r + dx, curr_c + dy
                    if 0 <= x < rows and 0 <= y < cols and grid[x][y] == 0 and (x, y) not in visited:
                        visited.add((x, y))
                        q.append((x, y, dist + 1))
        
        min_dist = float('inf')
        for [r,c],count in reach_count.items():
            if count == len(bldgs):
                min_dist = min(min_dist, total_dist[(r,c)])
        
        return min_dist if min_dist != float('inf') else -1