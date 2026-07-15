class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        def isvalid(word):
            if len(word)==0:
                return 0
            if word[0] in "aeiou" and word[-1] in "aeiou":
                return 1
            return 0
        prefix = [0]+[0]*len(words)
        for i,word in enumerate(words):
            prefix[i+1] = prefix[i]+isvalid(word)
        res = []
        for query in queries:
            res.append(prefix[query[1]+1]-prefix[query[0]])
        return res


        