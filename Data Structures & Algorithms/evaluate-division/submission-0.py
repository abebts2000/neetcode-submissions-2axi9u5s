class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        edges = collections.defaultdict(list)
        for (num, den), val in zip(equations, values):
            edges[num].append((den, val))
            edges[den].append((num, 1.0 / val))
        
        def dfs(curr, target, visited):
            if curr not in edges or target not in edges:
                return -1.0
            if curr == target:
                return 1.0
            visited.add(curr)
            for neighbor, val in edges[curr]:
                if neighbor not in visited:
                    res = dfs(neighbor, target, visited)
                    if res != -1.0:
                        return val * res
            return -1.0

        return [dfs(q[0], q[1], set()) for q in queries]