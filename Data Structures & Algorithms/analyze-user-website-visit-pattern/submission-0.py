class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        data = []
        for u, t, w in zip(username, timestamp, website):
            data.append((t, u, w))
        data.sort()
        
        user_history = defaultdict(list)
        for t, u, w in data:
            user_history[u].append(w)
            
        pattern_counts = defaultdict(int)
        for u in user_history:
            history = user_history[u]
            if len(history) < 3:
                continue
            user_patterns = set(combinations(history, 3))
            for p in user_patterns:
                pattern_counts[p] += 1
        
        max_score = 0
        res = ()
        for pattern, count in pattern_counts.items():
            if count > max_score:
                max_score = count
                res = pattern
            elif count == max_score:
                if not res or pattern < res:
                    res = pattern
        return list(res)