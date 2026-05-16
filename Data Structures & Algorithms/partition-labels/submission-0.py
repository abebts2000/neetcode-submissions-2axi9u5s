class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        dict = {}
        for i, ch in enumerate(s):
            if ch not in dict:
                dict[ch] = (i,i)
            else:
                first,last = dict[ch]
                dict[ch] = (first,i)
        res = []
        st = 0
        end = 0
        for i, ch in enumerate(s):
            if ch in dict:
                first,last = dict[ch]
                if last > end:
                    end = last
            if i == end:
                res.append(end - st + 1)
                st = i + 1
        return res