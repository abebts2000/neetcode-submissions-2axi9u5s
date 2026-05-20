class Solution:
    def getSum(self, a: int, b: int) -> int:
        c = 0
        sum = 0
        mask = 0xFFFFFFFF
        for i in range(32):
            sum |= (a&(1<<i)) ^ (b&(1<<i)) ^ (c&(1<<i))
            c = (((a&(1<<i)) & (b&(1<<i))) | ((b&(1<<i)) & (c&(1<<i))) | ((a&(1<<i)) & (c&(1<<i)))) << (1)
        
        if sum > 0x7FFFFFFF:
            return ~(sum ^ mask)
        return sum