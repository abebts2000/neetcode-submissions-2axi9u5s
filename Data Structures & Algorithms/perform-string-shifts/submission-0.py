class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        left,right = 0,0
        for sh in shift:
            if sh[0] == 0:
                left+=sh[1]
            else:
                right +=sh[1]
        n = len(s)
        if left > right:
            move = (left - right) % n
            return s[move:] + s[:move]
        else:
            move = (right - left) % n
            return s[n-move:] + s[:n-move]