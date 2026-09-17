class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set()
        for num in nums:
            st.add(num)
        c = 0
        for num in nums:
            if num-1 in st:
                continue
            else:
                nn = num
                cn =0
                while nn in st:
                    cn+=1
                    nn+=1
                c = max(c,cn)
        return c
                    