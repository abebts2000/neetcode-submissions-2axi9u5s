class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        majority = len(nums)//3
        nums.sort()
        prev = nums[0]
        res = []
        c =0
        for num in nums:
            if num != prev:
                if c >majority:
                    res.append(prev)
                prev = num
                c =1
            else:
                c+=1
        if c >majority:
            res.append(prev)
        return res


        