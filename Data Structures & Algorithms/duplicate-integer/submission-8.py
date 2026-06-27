class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        st = set(nums)
        return len(st) != len(nums)
