class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        mp = defaultdict(list)
        for (src,dest) in sorted(tickets):
            mp[src].append(dest)
        total = len(tickets)
        res = []
        def dfs(src,ticket, path):
            if ticket == total:
                res.append(list(path))
                return True
            for i in range(len(mp[src])):
                dest = mp[src].pop(i)
                path.append(dest)
                if dfs(dest,ticket+1,path):
                    return True
                path.pop()
                mp[src].insert(i, dest)
            return False
        dfs("JFK",0,["JFK"])
        return res[0]
