class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        mp = collections.defaultdict(int)
        for ch in s:
            mp[ch] += 1
        for ch in t:
            mp[ch] -= 1;
            if mp[ch] == 0:
                del mp[ch]
        return len(mp) == 0