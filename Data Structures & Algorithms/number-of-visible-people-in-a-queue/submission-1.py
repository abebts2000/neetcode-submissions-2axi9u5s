class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        res = [0]*len(heights)
        stk = []
        for i in range(len(heights)-1,-1,-1):
            while stk and stk[-1] < heights[i]:
                res[i]+=1
                stk.pop()
            if stk:
                res[i]+=1
            stk.append(heights[i])
        return res
        