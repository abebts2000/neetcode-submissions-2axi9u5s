class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set()
        mxcount =0
        for num in nums:
            st.add(num)
        for num in nums:
            if num-1 in st:
                continue;
            newst = num
            c=0
            while newst in st:
                c+=1
                newst+=1
            mxcount = max(mxcount,c)
        return mxcount

        