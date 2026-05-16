class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        cache = defaultdict(int)
        def findways(indx,remain):
            if indx == len(nums):
                return 1 if remain ==0 else 0
            if (indx,remain) not in cache:
                ways = findways(indx+1,remain-nums[indx])+findways(indx+1,remain+nums[indx])
                cache[(indx,remain)] = ways
            return cache[(indx,remain)]
        return findways(0,target)

        