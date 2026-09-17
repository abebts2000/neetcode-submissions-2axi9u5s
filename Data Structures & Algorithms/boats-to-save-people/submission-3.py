class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people = sorted(people)
        l,r,c = 0,len(people)-1,0
        while l <=r:
            if people[l]+people[r] <= limit:
                l,r = l+1,r-1
            else:
                r-=1
            c+=1
        return c
        