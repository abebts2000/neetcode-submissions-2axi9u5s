class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        mx=0
        i=0
        while i<len(s):
            if s[i] !=' ':
                ln =0
                while i<len(s) and s[i] != ' ':
                    ln+=1
                    i+=1
                mx = ln
            else:
                i+=1
                continue
        return mx