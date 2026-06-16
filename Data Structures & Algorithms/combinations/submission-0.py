class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def dfs(i,sofar):
            if len(sofar) == k:
                res.append(list(sofar))
                return
            if i>=n:
                return
            for nex in range(i,n):
                sofar.append(nex+1)
                dfs(nex+1,sofar)
                sofar.pop()
        dfs(0,[])
        return res
        