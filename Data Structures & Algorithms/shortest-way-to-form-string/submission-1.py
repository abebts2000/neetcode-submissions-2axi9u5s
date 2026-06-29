class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        res = 0
        t_idx = 0
        while t_idx < len(target):
            res += 1
            prev_idx = t_idx
            for char in source:
                if t_idx < len(target) and char == target[t_idx]:
                    t_idx += 1
            if t_idx == prev_idx:
                return -1
        return res