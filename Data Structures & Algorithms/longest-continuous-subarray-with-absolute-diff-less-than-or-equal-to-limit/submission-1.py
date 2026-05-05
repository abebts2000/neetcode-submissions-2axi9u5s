class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        max_q = deque()
        min_q = deque()
        st = 0
        res = 0
        for i in range(len(nums)):
            while max_q and nums[max_q[-1]] < nums[i]:
                max_q.pop()
            max_q.append(i)
            while min_q and nums[min_q[-1]] > nums[i]:
                min_q.pop()
            min_q.append(i)
            
            while nums[max_q[0]] - nums[min_q[0]] > limit:
                st += 1
                if max_q[0] < st:
                    max_q.popleft()
                if min_q[0] < st:
                    min_q.popleft()
            res = max(res, i - st + 1)
        return res