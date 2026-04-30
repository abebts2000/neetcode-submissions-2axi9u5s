class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr = [1]*len(nums)
        sum = 1
        for i in range(len(nums)):
            arr[i] = sum
            sum *= nums[i]
        sum2 = 1
        for i in range(len(nums) - 1, -1, -1):
            arr[i] = sum2 * arr[i]
            sum2 *= nums[i]
        return arr