class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = defaultdict(list)

        for src, dest, length in times:
            edges[src].append((dest, length))

        # min-heap of (time_so_far, node)
        pq = [(0, k)]
        visited = set()
        t = 0

        while pq:
            time, node = heapq.heappop(pq)

            if node in visited:
                continue

            visited.add(node)
            t = time

            for nei, weight in edges[node]:
                if nei not in visited:
                    heapq.heappush(pq, (time + weight, nei))

        return t if len(visited) == n else -1
        