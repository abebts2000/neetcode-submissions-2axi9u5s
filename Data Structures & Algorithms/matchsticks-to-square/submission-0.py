class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        total_sum = 0
        for matchstick in matchsticks:
            total_sum += matchstick
        if total_sum % 4 != 0:
            return False
        target = total_sum // 4
        matchsticks.sort(reverse=True)
        
        sides = [0] * 4
        
        def backtrack(index):
            if index == len(matchsticks):
                return sides[0] == sides[1] == sides[2] == target
            
            for i in range(4):
                if sides[i] + matchsticks[index] <= target:
                    sides[i] += matchsticks[index]
                    if backtrack(index + 1):
                        return True
                    sides[i] -= matchsticks[index]
                if sides[i] == 0:
                    break
            return False
        
        return backtrack(0)