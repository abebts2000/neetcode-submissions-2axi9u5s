class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        for i,num in enumerate(nums2):
            mp[num]=i
        res =[]
        for num in nums1:
            res.append(mp[num])
        return res

        