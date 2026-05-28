class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.isV1 = True
        self.v1indx = 0
        self.v2indx = 0
        self.v1 = v1
        self.v2 = v2

    def next(self) -> int:
        ans = -1
        if self.hasNext():
            if (self.isV1 and self.v1indx < len(self.v1)) or self.v2indx == len(self.v2):
                ans = self.v1[self.v1indx]
                self.v1indx += 1
                self.isV1 = False
            else:
                ans = self.v2[self.v2indx]
                self.v2indx += 1
                self.isV1 = True
            return ans       

    def hasNext(self) -> bool:
        if self.v1indx == len(self.v1) and self.v2indx == len(self.v2):
            return False
        return True
        

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
