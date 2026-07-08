class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        st1 = set(nums1)
        st2 = set(nums2)

        res = [[],[]]
        for s in st1:
            if s not in st2:
                res[0].append(s)
        for s in st2:
            if s not in st1:
                res[1].append(s)

        return res
                         