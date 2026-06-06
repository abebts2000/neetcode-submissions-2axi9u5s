class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        mp = {}
        for i,ch in enumerate(order):
            mp[ch] = i
        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i + 1]
            for c1, c2 in zip(word1, word2):
                if mp[c1] > mp[c2]:
                    return False
                if mp[c1] < mp[c2]:
                    break
            else:
                if len(word1) > len(word2):
                    return False
        return True