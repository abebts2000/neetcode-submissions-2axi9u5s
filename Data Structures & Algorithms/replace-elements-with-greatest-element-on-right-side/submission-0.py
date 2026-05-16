class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        hp = []
        res = []
        for i,val in enumerate(arr):
            heapq.heappush(hp,(-val,i))
        for i in range(len(arr)):
            while hp and hp[0][1] <= i:
                heapq.heappop(hp)
            if hp:
                res.append(-hp[0][0])
            else:
                res.append(-1)
        return res