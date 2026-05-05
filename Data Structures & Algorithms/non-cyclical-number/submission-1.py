class Solution:
    def isHappy(self, n: int) -> bool:
        def sumsquare(num: int) -> int:
            sum = 0
            while num > 0:
                sum = sum + (num%10) * (num%10)
                num //= 10
            print(sum)
            return sum
        st = set()
        st.add(n)
        while n != 1:
            n = sumsquare(n)
            if n in st:
                return False;
            if n == 1:
                return True;
            st.add(n)
        return True

