class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        letters = defaultdict(int)
        for word in words:
            for ch in word:
                letters[ch]+=1
        ln = len(words)
        for key,value in letters.items():
            if value%ln !=0:
                return False
        return True
        