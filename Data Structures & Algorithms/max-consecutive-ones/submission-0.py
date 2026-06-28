class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        mx =0
        c=0
        for num in nums:
            if num !=1:
                mx = max(mx,c)
                c=0
            else:
                c+=1
                mx = max(mx,c)
        return mx