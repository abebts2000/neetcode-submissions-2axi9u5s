class CountSquares:

    def __init__(self):
        self.grid = []
        self.mp ={}

    def add(self, point: List[int]) -> None:
        point_tuple = tuple(point)
        if point_tuple in self.mp:
            self.mp[point_tuple] += 1
        else:
            self.mp[point_tuple] = 1
            self.grid.append(point_tuple)

    def count(self, point: List[int]) -> int:
        x1, y1 = point
        ans = 0
        for x2, y2 in self.grid:
            if x1 == x2 or abs(x1 - x2) != abs(y1 - y2):
                continue
            if (x1, y2) in self.mp and (x2, y1) in self.mp:
                ans += self.mp[(x1, y2)] * self.mp[(x2, y1)] * self.mp[(x2, y2)]
        return ans