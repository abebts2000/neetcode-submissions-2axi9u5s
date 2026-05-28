class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        c=0
        if len(s) == len(t):
            for i in range(len(s)):
                if s[i] != t[i]:
                    c+=1
            return c == 1
        else:
            if abs(len(s) - len(t)) != 1:
                return False
            if len(s) > len(t):
                s,t = t,s
            i,j = 0,0

            while i < len(t):
                if j < len(s) and s[j] == t[i]:
                    j+=1
                    i+=1

                else:

                    c+=1
                    i+=1
            return c == 1