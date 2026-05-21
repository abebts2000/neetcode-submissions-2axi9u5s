class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l,h = 0,len(nums)-1
        ans = len(nums)
        while l <=h:
            mid = l+(h-l)//2
            if nums[mid] == target:
                return mid
            if nums[mid] >target:
                h=mid-1
                ans = mid
            elif nums[mid] < target:
                l= mid+1
                ans = l
        return ans
