class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1,nums2 = nums2,nums1
        L1,L2 = len(nums1),len(nums2)
        l1, h1 = 0, L1
        half_len = (L1 + L2 + 1) // 2
        while l1 <= h1:
            mid1 = (l1 + h1) // 2
            mid2 = half_len - mid1
            
            maxLeft1 = nums1[mid1-1] if mid1 > 0 else float('-inf')
            minRight1 = nums1[mid1] if mid1 < L1 else float('inf')
            
            maxLeft2 = nums2[mid2-1] if mid2 > 0 else float('-inf')
            minRight2 = nums2[mid2] if mid2 < L2 else float('inf')

            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                if (L1 + L2) % 2 == 1:
                    return float(max(maxLeft1, maxLeft2))
                else:
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0
            elif maxLeft1 > minRight2:
                h1 = mid1 - 1
            else:
                l1 = mid1 + 1
        return 0.0