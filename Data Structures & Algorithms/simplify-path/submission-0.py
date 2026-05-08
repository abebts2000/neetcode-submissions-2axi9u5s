class Solution:
    def simplifyPath(self, path: str) -> str:
        stk = []
        paths = path.split("/")
        print(paths)
        for cur in paths:
            if cur == "..":
                if stk:
                    stk.pop()
            elif cur != "" and cur != ".":
                stk.append(cur)
        return "/"+"/".join(stk)
        