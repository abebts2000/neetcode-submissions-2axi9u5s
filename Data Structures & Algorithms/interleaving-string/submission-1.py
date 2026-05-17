class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        cache = {}
        def dfs(i,j,k):
            if k==len(s3):
                return True
            if (i,j) not in cache:
                valid = False
                for l in range(len(s1)-i):
                    if s1[i:i+l+1] == s3[k:k+l+1]:
                        valid = valid or dfs(i+l+1,j,k+l+1)
                    else:
                        break
                for l in range(len(s2)-j):
                    if s2[j:j+l+1] == s3[k:k+l+1]:
                        valid = valid or dfs(i,j+l+1,k+l+1)
                    else:
                        break
                cache[(i,j)] = valid
            return cache[(i,j)]
        return dfs(0,0,0)
            # check s1 subsring(s) till it matchs
                
            # check s2 substring till it matches


        