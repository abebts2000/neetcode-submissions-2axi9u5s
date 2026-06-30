class Solution:
    def isPathCrossing(self, path: str) -> bool:
        st = set()
        x, y = 0, 0
        st.add((x, y))
        for c in path:
            if c == 'N': y += 1
            elif c == 'S': y -= 1
            elif c == 'E': x += 1
            elif c == 'W': x -= 1
            
            if (x, y) in st:
                return True
            st.add((x, y))
        return False