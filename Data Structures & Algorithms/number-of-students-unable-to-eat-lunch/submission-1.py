class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        q = deque(students)
        n= len(students)
        res = n
        for sd in sandwiches:
            cn =0
            while cn < n and q[0] != sd:
                cur = q.popleft()
                q.append(cur)
                cn +=1
            if q[0] == sd:
                q.popleft()
                res -=1
            else:
                break
        return res




        

        