class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        res = []
        for i in range(len(nums)):
            if nums[i] not in mp: mp[nums[i]] = []
            mp[nums[i]].append(i)
        for key, val in mp.items():
            if target-key == key and len(mp[key])>1:
                for indx in range(len(mp[key])):
                    if indx != 0:
                        res = [mp[key][0],mp[key][indx]]
            elif target-key in mp and target-key != key:
                for indx in range(len(mp[key])):
                    for nxt in range(len(mp[target-key])):
                        res = [mp[key][indx],mp[target-key][nxt]]
            
        return sorted(res)