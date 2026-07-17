class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        mp = defaultdict(int)
        for i,ch in enumerate(keyboard):
            mp[ch] = i
        cur =0
        total =0
        for ch in word:
            total += abs(mp[ch]-cur)
            cur = mp[ch]
        return total


        