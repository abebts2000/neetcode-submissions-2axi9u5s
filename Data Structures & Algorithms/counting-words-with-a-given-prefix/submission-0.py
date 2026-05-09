class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        c =0
        for word in words:
            if len(word)>= len(pref) and word[0:len(pref)] == pref:
                c+=1
        return c
        