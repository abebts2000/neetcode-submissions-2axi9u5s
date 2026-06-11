class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        memo = {}
        def dfs(s,t,i,j):
            if j == len(t):
                return 1
            if j < len(t) and i == len(s):
                return 0
            if (i,j) not in memo:
                total = dfs(s,t,i+1,j)
                if s[i] == t[j]:
                    total += dfs(s,t,i+1,j+1)
                memo[(i,j)] = total
            return memo[(i,j)]
        return dfs(s,t,0,0)


            