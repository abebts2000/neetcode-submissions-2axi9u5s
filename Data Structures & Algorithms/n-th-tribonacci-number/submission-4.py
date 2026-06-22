class Solution:
    def tribonacci(self, n: int) -> int:
        cache = {}
        def dfs(x):
            if x == 0:
                return 0
            if x < 3:
                return 1
            if x not in cache:
                cache[x] = dfs(x-1)+dfs(x-2)+dfs(x-3)
            return cache[x]
        return dfs(n)
            
        