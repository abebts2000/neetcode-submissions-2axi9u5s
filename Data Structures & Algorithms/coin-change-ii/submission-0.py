class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [[0]*(amount+1) for _ in range(len(coins))]
        for c in range(0,len(coins)):
            for i in range(0,amount+1):
                if i == 0:
                    dp[c][i] = 1
                elif i < coins[c]:
                    dp[c][i] = dp[c-1][i] if c>0 else 0
                else:
                    dp[c][i] = dp[c][i-coins[c]] + (dp[c-1][i] if c>0 else 0)
        return dp[len(coins)-1][amount] if coins else (1 if amount == 0 else 0)