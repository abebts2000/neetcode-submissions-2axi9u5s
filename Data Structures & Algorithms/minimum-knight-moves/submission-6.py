class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        x, y = abs(x), abs(y)
        q=deque()
        q.append((0,0,0))
        st = set()
        dir =[[-2,1],[-1,2],[1,2],[2,1],[2,-1],[1,-2],[-1,-2],[-2,-1]]
        st.add((0,0))

        while q:
            r,c,l = q.popleft()
            if r== x and c == y:
                return l
            for d in dir:
                x1,y1 = r+d[0],c+d[1]
                if x1 >= -2 and y1 >= -2 and x1 <= x + 2 and y1 <= y + 2 and (x1,y1) not in st:
                    q.append((x1,y1,l+1))
                    st.add((x1,y1))
        return -1

    
        