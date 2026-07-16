class Solution: 
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        st = 0
        wait = 0
        for customer in customers:
            arrival, time = customer[0], customer[1]
            st = max(st, arrival) + time
            wait += st - arrival
        return wait/len(customers)