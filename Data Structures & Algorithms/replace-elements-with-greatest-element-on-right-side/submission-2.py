class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        res = [-1]*len(arr)
        mx = arr[len(arr)-1]
        for i in range(len(arr)-2,-1,-1):
            res[i] = mx
            mx = max(mx,arr[i])
            
        return res


        