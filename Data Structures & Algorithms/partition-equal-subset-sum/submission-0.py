class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums)%2:
            return False
        half = sum(nums)//2
        cache = {}
        def dfs(i,remaining):
            if remaining == 0:
                return True
            if i==len(nums):
                return False
            if (i,remaining) not in cache:
                cache[(i,remaining)] = dfs(i+1,remaining) or dfs(i+1,remaining-nums[i])
            return cache[(i,remaining)]
        return dfs(0,half)

        