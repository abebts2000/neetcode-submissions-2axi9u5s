class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        res = []
        hsorted =sorted(heights)
        for i in range(len(heights)):
            if hsorted[i] != heights[i]:
                res.append(i)
        return len(res)

        