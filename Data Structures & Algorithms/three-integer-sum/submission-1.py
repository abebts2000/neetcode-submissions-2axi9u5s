class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort();
        res = []
        for i in range(0,len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            k,l =i+1,len(nums)-1
            while k<l:
                if nums[i]+nums[k]+nums[l] < 0:
                    k+=1
                elif nums[i]+nums[k]+nums[l] > 0:
                    l-=1
                else:
                    res.append([nums[i],nums[k],nums[l]])
                    while k < l and nums[k] == nums[k+1]:
                        k += 1
                    while k < l and nums[l] == nums[l-1]:
                        l -= 1
                    k += 1
                    l -= 1
        return res
        