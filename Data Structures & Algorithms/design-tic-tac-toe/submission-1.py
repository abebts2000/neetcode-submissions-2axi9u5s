class TicTacToe:

    def __init__(self, n: int):
        self.n = n
        self.grid =[[' ']*n for _ in range(n)]
        self.players = {1:'X',2:'O'}
        self.moves = 0

    def isplayerWinner(self, col, row, player) -> int:
        char = self.players[player]
        # Check row
        if all(self.grid[row][c] == char for c in range(self.n)):
            return player
        # Check column
        if all(self.grid[r][col] == char for r in range(self.n)):
            return player
        # Check main diagonal
        if row == col:
            if all(self.grid[i][i] == char for i in range(self.n)):
                return player
        # Check anti-diagonal
        if row + col == self.n - 1:
            if all(self.grid[i][self.n - 1 - i] == char for i in range(self.n)):
                return player
        return 0

    def tie(self):
        return True if self.moves == self.n * self.n else False

    def move(self, row: int, col: int, player: int) -> int:
        self.grid[row][col] = self.players[player]
        self.moves += 1
        return self.isplayerWinner(col, row, player)