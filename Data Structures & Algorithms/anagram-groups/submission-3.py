class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = defaultdict(list)
        for word in strs:
            sorted_ = f"{sorted(word)}"
            result[sorted_].append(word)
        return [word for word in result.values()]
