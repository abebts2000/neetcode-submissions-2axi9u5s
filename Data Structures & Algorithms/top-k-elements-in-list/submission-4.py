class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = defaultdict(int)
        res = []
        for num in nums:
            mp[num]+=1
        pq = []
        for key,value in mp.items():
            heapq.heappush(pq,[value,key])
            if len(pq) > k:
                heapq.heappop(pq)
        while pq:
            res.append(heapq.heappop(pq)[1])
        return res
        