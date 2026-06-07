class Solution:
    def countElements(self, arr: List[int]) -> int:
        mp = Counter(arr)
        c =0
        for keys in mp:
            if keys+1 in mp:
                c+=mp[keys]
        return c

        