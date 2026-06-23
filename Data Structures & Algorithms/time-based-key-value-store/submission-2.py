import bisect

class TimeMap:

    def __init__(self):
        self.kv = defaultdict(list)
        self.ts = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.kv[key].append(value)
        self.ts[key].append(timestamp)

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.ts:
            return ""
        indx = bisect.bisect_right(self.ts[key], timestamp)
        if indx > 0:
            return self.kv[key][indx - 1]
        return ""
