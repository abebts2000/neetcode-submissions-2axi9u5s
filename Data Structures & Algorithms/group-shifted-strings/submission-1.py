class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        def gethash(s):
            shift = ord(s[0]) - ord('a')
            res = []
            for ch in s:
                res.append((ord(ch) - ord('a') - shift + 26) % 26)
            return tuple(res)
        dict = defaultdict(list)
        for ss in strings:
            dict[gethash(ss)].append(ss)
        res = [ss for ss in dict.values()]
        return res;
