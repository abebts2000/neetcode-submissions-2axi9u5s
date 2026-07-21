class Solution:
    def longestPalindrome(self, s: str) -> int:
        mp = defaultdict(int)
        for c in s:
            mp[c]+=1
        l =0
        extra =0
        for ch,count in mp.items():
            l+=2*(count//2)
            extra += count%2
        if extra !=0:
            l+=1
        return l

        