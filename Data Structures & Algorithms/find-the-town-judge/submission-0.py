class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        town = defaultdict(set)
        st = set(i for i in range(1,n+1))
        for a,b in trust:
            town[a].add(b)
            if a in st:
                st.remove(a)
        if len(town) != n-1 or len(st) != 1:
            return -1
        judge = -1
        for s in st:
            judge = s
        for e in town:
            if judge not in town[e]:
                return -1
        return judge
        
        

        