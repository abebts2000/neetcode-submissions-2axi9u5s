class Solution:

    def encode(self, strs: List[str]) -> str:
        return "".join([ f"{len(word)}#{word}" for word in strs])
    def decode(self, s: str) -> List[str]:
        #    3#abc2#vv0#
        # st 0
        #end   1
        st =0
        res = []
        print(s)
        while st < len(s):
            end = st
            while s[end] != '#':
                end +=1
            ln = int(s[st:end])
            res.append(s[end+1:end+ln+1])
            st = end+ln+1
        return res

