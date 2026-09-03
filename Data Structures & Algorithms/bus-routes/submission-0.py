class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target: return 0
        look_up = collections.defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                look_up[stop].append(i)
        
        q = deque()
        visited_buses = set()
        visited_stops = {source}
        
        for bus_idx in look_up[source]:
            q.append((bus_idx, 1))
            visited_buses.add(bus_idx)
            
        while q:
            bus_idx, count = q.popleft()
            for stop in routes[bus_idx]:
                if stop == target: return count
                if stop not in visited_stops:
                    visited_stops.add(stop)
                    for next_bus in look_up[stop]:
                        if next_bus not in visited_buses:
                            visited_buses.add(next_bus)
                            q.append((next_bus, count + 1))
        return -1