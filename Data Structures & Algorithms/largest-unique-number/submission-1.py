class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        return max([key for key, value in Counter(nums).items() if value == 1] or [-1])