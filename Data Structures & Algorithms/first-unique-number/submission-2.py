class FirstUnique:

    def __init__(self, nums: List[int]):
        self.numbers = nums
        self.firstIndx = -1
        self.duplicates = set()
        self.unique = set()
        
        dic = Counter(self.numbers)
        self.duplicates = {key for key, value in dic.items() if value > 1}
        self.unique = {key for key, value in dic.items() if value == 1}
        for i, num in enumerate(self.numbers):
            if num in self.unique:
                self.firstIndx = i
                break

    def showFirstUnique(self) -> int:
        return self.numbers[self.firstIndx] if self.firstIndx != -1 else -1

    def add(self, value: int) -> None:
        self.numbers.append(value)
        if value in self.duplicates:
            return
        if value in self.unique:
            self.unique.remove(value)
            self.duplicates.add(value)
        else:
            self.unique.add(value)
            
        if self.firstIndx == -1 or self.numbers[self.firstIndx] == value:
            for i in range(max(0, self.firstIndx), len(self.numbers)):
                if self.numbers[i] in self.unique:
                    self.firstIndx = i
                    return
            self.firstIndx = -1