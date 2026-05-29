class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.width = width
        self.height = height
        self.food = food
        self.food_idx = 0
        self.score = 0
        self.snake = collections.deque([[0, 0]])
        self.snake_set = {(0, 0)}
        self.dirs = {'D': (1, 0), 'R': (0, 1), 'L': (0, -1), 'U': (-1, 0)}

    def move(self, direction: str) -> int:
        head_r, head_c = self.snake[0]
        dr, dc = self.dirs[direction]
        new_r, new_c = head_r + dr, head_c + dc

        if new_r < 0 or new_r >= self.height or new_c < 0 or new_c >= self.width:
            return -1

        if self.food_idx < len(self.food) and [new_r, new_c] == self.food[self.food_idx]:
            self.food_idx += 1
            self.score += 1
        else:
            tail = self.snake.pop()
            self.snake_set.remove(tuple(tail))

        if (new_r, new_c) in self.snake_set:
            return -1

        self.snake.appendleft([new_r, new_c])
        self.snake_set.add((new_r, new_c))
        return self.score