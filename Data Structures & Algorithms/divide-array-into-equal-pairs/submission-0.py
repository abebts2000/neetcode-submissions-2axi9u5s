class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        return False if len([key for key,value in Counter(nums).items() if value%2 !=0])>0 else True