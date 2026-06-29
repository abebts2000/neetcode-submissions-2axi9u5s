class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mag = defaultdict(int)
        rans = defaultdict(int)

        for r in ransomNote:
            rans[r]+=1
        for m in magazine:
            mag[m]+=1
        for r in rans:
            if mag[r] < rans[r]:
                return False
        return True

        
        