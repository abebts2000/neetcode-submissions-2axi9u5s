class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        dic = Counter(arr)
        res =[]
        for key,value in dic.items():
            if value == 1:
                res.append(key)
        return res[k-1] if k <= len(res) else ""
        

        