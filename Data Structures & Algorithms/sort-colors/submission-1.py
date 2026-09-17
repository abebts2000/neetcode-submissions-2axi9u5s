class Solution:
    def sortColors(self, nums: List[int]) -> None:
        mp = {0:0,1:0,2:0}
        for num in nums:
            mp[num]+=1
        indx =0
        for i in range(3):
            for c in range(mp[i]):
                nums[indx] = i
                indx+=1
        
        