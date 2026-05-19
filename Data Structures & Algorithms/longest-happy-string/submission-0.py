class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res = []
        counts = [['a', a], ['b', b], ['c', c]]
        
        while True:
            counts.sort(key=lambda x: x[1], reverse=True)
            found = False
            for i in range(3):
                char, count = counts[i]
                if count > 0:
                    if len(res) >= 2 and res[-1] == char and res[-2] == char:
                        continue
                    res.append(char)
                    counts[i][1] -= 1
                    found = True
                    break
            if not found:
                break
        return "".join(res)