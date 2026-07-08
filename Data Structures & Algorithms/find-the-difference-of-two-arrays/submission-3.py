class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        st1,st2 = set(nums1),set(nums2)

        res1,res2 = [],[]
        for s in st1:
            if s not in st2:
                res1.append(s)
        for s in st2:
            if s not in st1:
                res2.append(s)

        return [res1,res2]
                         