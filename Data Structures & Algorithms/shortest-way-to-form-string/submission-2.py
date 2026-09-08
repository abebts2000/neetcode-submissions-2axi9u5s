import bisect

class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        dic = defaultdict(list)
        for i in range(len(source)):
            dic[source[i]].append(i)
        curIndx = 0
        res = 1
        for i in range(len(target)):
            ch = target[i]
            if ch not in dic:
                return -1
            idx = bisect.bisect_left(dic[ch], curIndx)
            if idx < len(dic[ch]):
                curIndx = dic[ch][idx] + 1
            else:
                res += 1
                curIndx = dic[ch][0] + 1
        return res