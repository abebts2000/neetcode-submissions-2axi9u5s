class Solution:
    def getSum(self, a: int, b: int) -> int:
        c = 0
        sum = 0
        mask = 0xFFFFFFFF
        for i in range(32):
            bit_a = (a & (1<<i))
            bit_b = (b & (1<<i))
            bit_c = (c & (1<<i))
            sum |= (bit_a ^ bit_b ^ bit_c)
            c = ((bit_a & bit_b) | (bit_b & bit_c) | (bit_a & bit_c)) << (1)
        
        if sum > 0x7FFFFFFF:
            return ~(sum ^ mask)
        return sum