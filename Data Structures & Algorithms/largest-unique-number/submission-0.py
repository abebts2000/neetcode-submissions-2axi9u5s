class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        duplicate = set()
        unique = set()

        for num in nums:
            if num in duplicate:
                continue
            elif num in unique:
                duplicate.add(num)
                unique.remove(num)
            else:
                unique.add(num)
        mx = -1
        for num in unique:
            mx = max(num,mx)
        return mx
        