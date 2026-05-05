class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValid(r,c):
            for i in range(c+1,len(board[0])):
                if board[r][i] != "." and board[r][i] == board[r][c]:
                    return False
            for j in range(r+1,len(board)):
                 if board[j][c] != "." and board[j][c] == board[r][c]:
                    return False
            cellx,celly = 3*(r//3),3*(c//3)
            for i in range(cellx,cellx+3):
                for j in range(celly,celly+3):
                    if board[i][j] != "." and board[i][j] == board[r][c]:
                        if i ==r and j ==c:
                            continue;
                        return False
            return True

        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == ".":
                    continue
                if isValid(r,c) is False:
                    return False;
        return True;

                

        