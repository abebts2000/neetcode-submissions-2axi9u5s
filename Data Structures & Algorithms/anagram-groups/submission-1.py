class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}
        for word in strs:
            sortedword = tuple(sorted(word))
            if sortedword not in anagrams:
                anagrams[sortedword] = []
            anagrams[sortedword].append(word)
        return list(anagrams.values())