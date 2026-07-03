class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefix = [0]*len(nums)

        for i in range(1, len(nums)):
            prefix[i]= prefix[i-1]+nums[i-1]
        
        total_sum = sum(nums)
        for i in range(len(nums)):
            right_sum = total_sum - prefix[i] - nums[i]
            if prefix[i] == right_sum:
                return i
        return -1