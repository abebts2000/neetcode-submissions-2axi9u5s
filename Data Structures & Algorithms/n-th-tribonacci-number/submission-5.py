class Solution:
    def tribonacci(self, n: int) -> int:
        cache = {}
        def dfs(n):
            if n == 0:
                return 0
            if n < 3:
                return 1
            if n not in cache:
                cache[n] = dfs(n-1)+dfs(n-2)+dfs(n-3)
            return cache[n]
        return dfs(n)
            
        