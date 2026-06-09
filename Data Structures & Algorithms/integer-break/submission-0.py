class Solution:
    def integerBreak(self, n: int) -> int:
        # cache = {}
        # def dfs(num,k):
        #     if k < 0:
        #         return "-infinity"
        #     if k == 0:
        #         return 1
        #     if (num,k) not in cache:
        #         mx = int("-infinity")
        #         for i in range(1,num):
        #             mx = max(mx,i*dfs(num-i,k-1))
        #         cache[(num,k)] = mx
        #     return cache[(num,k)]
        # return dfs()
        candidates = [num for num in range(1,n+1)]

        mx = 0
        for num in range(1, n):
            # dp[i] is the max product for sum i
            dp = [0] * (n + 1)
            dp[0] = 1
            for i in range(1, n + 1):
                for j in range(1, i + 1):
                    dp[i] = max(dp[i], dp[i-j] * j)
            
        # Correcting logic to follow the mathematical pattern of 3s
        if n == 2: return 1
        if n == 3: return 2
        res = 1
        while n > 4:
            res *= 3
            n -= 3
        return res * n