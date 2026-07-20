class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        chars = defaultdict(lambda: [0] * len(words))
        for i,word in enumerate(words):
            for ch in word:
                chars[ch][i]+=1
        res = []
        for key,value in chars.items():
            min_count = min(value)
            for _ in range(min_count):
                res.append(key)
        return res
