class Solution:
    def isPalindrome(self, s: str) -> bool:
        def isalphanum(c):
            return (ord('A') <= ord(c) <= ord('Z') or 
            ord('a') <= ord(c) <= ord('z') or
            ord('0') <= ord(c) <= ord('9'))

        i,e=0,len(s)-1
        while i<e:
            while i<e and not isalphanum(s[i]):
                i+=1
            while e>i and not isalphanum(s[e]):
                e-=1
            if s[i].lower() != s[e].lower():
                return False
            i,e = i+1, e-1
        return True
        