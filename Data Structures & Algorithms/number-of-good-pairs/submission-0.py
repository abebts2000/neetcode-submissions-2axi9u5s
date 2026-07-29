class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        dc = Counter(nums)
        total = 0
        for val in dc.values():
            if val > 1:
                total += (val)*(val-1)//2

        return total

        