class Solution:
    def reorganizeString(self, s: str) -> str:
        mp = defaultdict(int)
        mxr = 0
        for c in s:
            mp[c] += 1
            mxr = max(mxr, mp[c])
        if len(s) + 1 < 2 * mxr:
            return ""
        hp = []
        for c, count in mp.items():
            heapq.heappush(hp, (-count, c))
        ans = [''] * len(s)
        i = 0
        while hp:
            neg_count, c = heapq.heappop(hp)
            count = -neg_count
            for _ in range(count):
                if i >= len(ans): 
                    i = 1
                ans[i] = c
                i += 2
        return "".join(ans)
