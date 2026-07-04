class Solution:
    def confusingNumber(self, n: int) -> bool:
        mapping = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
        s = str(n)
        rotated = []
        
        for char in reversed(s):
            if char not in mapping:
                return False
            rotated.append(mapping[char])
            
        return int("".join(rotated)) != n