class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return len([ int(senior[11:13]) for senior in details if (int(senior[11:13]))>60])
        