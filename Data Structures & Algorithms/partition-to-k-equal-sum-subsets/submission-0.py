class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total_sum = sum(nums)
        if total_sum % k != 0:
            return False
        
        target = total_sum // k
        nums.sort(reverse=True)
        used = [False] * len(nums)
        
        memo = {}

        def backtrack(index, current_sum, k_remaining):
            if k_remaining == 0:
                return True
            
            state = (tuple(used), k_remaining)
            if state in memo:
                return memo[state]
            
            if current_sum == target:
                res = backtrack(0, 0, k_remaining - 1)
                memo[state] = res
                return res
            
            for i in range(index, len(nums)):
                if not used[i] and current_sum + nums[i] <= target:
                    used[i] = True
                    if backtrack(i + 1, current_sum + nums[i], k_remaining):
                        return True
                    used[i] = False
                    
                    # Optimization: if current_sum is 0 and we failed, we can't place nums[i] anywhere
                    if current_sum == 0: break
            
            memo[state] = False
            return False

        return backtrack(0, 0, k)