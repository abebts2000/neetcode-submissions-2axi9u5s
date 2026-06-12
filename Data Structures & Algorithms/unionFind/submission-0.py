class UnionFind:
    
    def __init__(self, n: int):
        self.parent = {i:i for i in range(n)}
        self.edges = defaultdict(list)
        self.rank = {i:1 for i in range(n)}

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def isSameComponent(self, x: int, y: int) -> bool:
        p1 = self.find(x)
        p2=self.find(y)
        if p1 ==p2:
            return True
        return False

    def union(self, x: int, y: int) -> bool:
        p1 = self.find(x)
        p2=self.find(y)
        if p1 ==p2:
            return False
        if self.rank[p1] >= self.rank[p2]:
            self.parent[p2] = p1
            self.rank[p2]+= self.rank[p1]
            return True
        return False

    def getNumComponents(self) -> int:
        c=0
        for id,p in self.parent.items():
            if id ==p:
                c+=1
        return c

