class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr = [1]*len(nums)
        arr2 = [1]*len(nums)
        sum = 1
        for i in range(len(nums)-1):
            sum *=nums[i]
            arr[i] = sum
        sum2 = 1
        for i in range(len(nums) - 1, -1, -1):
            if i< len(nums)-1:
                sum2 *= nums[i+1]
            arr2[i] = sum2*arr[i-1]
        return arr2


        