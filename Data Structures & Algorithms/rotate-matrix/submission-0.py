class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        #(1,0) => (0,1)
        #(0,1) --> (1,2)
        n = len(matrix)
        for i in range(n // 2):
            for j in range(i, n - 1 - i):
                # Save top-left
                temp = matrix[i][j]
                # Bottom-left to top-left
                matrix[i][j] = matrix[n - 1 - j][i]
                # Bottom-right to bottom-left
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
                # Top-right to bottom-right
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
                # Top-left to top-right
                matrix[j][n - 1 - i] = temp