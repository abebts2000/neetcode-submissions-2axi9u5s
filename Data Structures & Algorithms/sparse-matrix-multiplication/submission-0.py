class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        m, k, n = len(mat1), len(mat1[0]), len(mat2[0])
        res = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for p in range(k):
                if mat1[i][p] != 0:
                    for j in range(n):
                        if mat2[p][j] != 0:
                            res[i][j] += mat1[i][p] * mat2[p][j]
        return res