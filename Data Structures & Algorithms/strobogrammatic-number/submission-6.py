class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        nums = {'1':'1','6':'9','0':'0','8':'8','9':'6'}
        st,end = 0,len(num)-1
        while st <= end:
            if num[st] not in nums or nums[num[st]] != num[end]:
                return False
            st+=1
            end-=1
        return True
