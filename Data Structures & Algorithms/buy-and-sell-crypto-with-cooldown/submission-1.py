from functools import lru_cache

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @lru_cache(None)
        def dfs(i,buying):
            if i>=len(prices):
                return 0
            ans = dfs(i+1,buying)
            if buying:
                buy = dfs(i+1, not buying)-prices[i]
                ans = max(buy,ans)
            else:
                sell = dfs(i+2, not buying) + prices[i]
                ans = max(sell,ans)
            return ans
        return dfs(0,True)