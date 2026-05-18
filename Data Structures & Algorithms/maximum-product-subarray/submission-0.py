class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = nums[0]
        mx = mn = nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            temp_mx = max(num, mx * num, mn * num)
            mn = min(num, mx * num, mn * num)
            mx = temp_mx
            res = max(res, mx)
        return res