class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.sumPrefix = [[0]*(len(matrix[0])+1) for _ in range(len(matrix)+1)]

        for r in range(len(matrix)):
            pref = 0
            for c in range(len(matrix[0])):
                pref += matrix[r][c]
                above = self.sumPrefix[r][c+1]
                self.sumPrefix[r+1][c+1] = pref + above
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row1,col1,row2,col2 = row1+1,col1+1,row2+1,col2+1
        br = self.sumPrefix[row2][col2]
        ab = self.sumPrefix[row1-1][col2]
        lft = self.sumPrefix[row2][col1-1]
        tl = self.sumPrefix[row1-1][col1-1]

        return br-ab-lft+tl
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)