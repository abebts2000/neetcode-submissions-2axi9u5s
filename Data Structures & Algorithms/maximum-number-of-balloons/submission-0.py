class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        mp = {key: value for key, value in Counter(text).items() if key in 'balon'}
        c=0
        while True:
            if mp.get('b', 0)<1 or mp.get('a', 0)<1 or mp.get('l', 0)<2 or mp.get('o', 0)<2 or mp.get('n', 0)<1:
                return c
            mp['b']-=1
            mp['a']-=1
            mp['l']-=2
            mp['o']-=2
            mp['n']-=1
            c+=1
        return c