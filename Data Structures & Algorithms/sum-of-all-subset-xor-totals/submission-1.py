class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def dfs(indx,xor_sofar):
            if indx == len(nums):
                return xor_sofar
            return dfs(indx+1,nums[indx]^xor_sofar)+dfs(indx+1,xor_sofar)
        return dfs(0,0)
        