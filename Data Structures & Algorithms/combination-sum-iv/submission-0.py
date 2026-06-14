class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        
        for n in range(1, target + 1):
            for num in nums:
                if n >= num:
                    dp[n] += dp[n - num]
                    
        return dp[target]