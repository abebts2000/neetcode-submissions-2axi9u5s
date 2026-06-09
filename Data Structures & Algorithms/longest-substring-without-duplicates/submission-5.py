class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = {}
        st,end =0,0
        ln =0
        for i,c in enumerate(s):
            if c in mp and mp[c] >= st:
                st = mp[c]+1
            mp[c] = i
            ln = max(ln,i-st+1)
        return ln
