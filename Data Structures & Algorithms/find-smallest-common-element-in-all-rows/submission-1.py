class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        def binarysearch(arr,val):
            l,h=0,len(arr)-1
            while l<=h:
                mid = l+(h-l)//2
                if arr[mid] < val:
                    l=mid+1
                elif arr[mid] > val:
                    h=mid-1
                else:
                    return mid
            return -1
        for num in mat[0]:
            found = True
            for indx in range(1,len(mat)):
                if binarysearch(mat[indx],num) == -1:
                    found=False
                    break
            if found:
                return num
        return -1