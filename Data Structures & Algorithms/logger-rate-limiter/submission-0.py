class Logger:

    def __init__(self):
        self.rate = defaultdict(list)
        

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message in self.rate:
            if timestamp < self.rate[message][0] + 10:
                return False
            self.rate[message] = [timestamp]
            return True
        else:
            self.rate[message] = [timestamp]
            return True