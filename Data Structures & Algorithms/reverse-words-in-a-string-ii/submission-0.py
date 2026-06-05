class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def reverse(l, r):
            while l < r:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1

        # Step 1: Reverse the entire array
        reverse(0, len(s) - 1)

        # Step 2: Reverse each word individually
        start = 0
        for end in range(len(s) + 1):
            if end == len(s) or s[end] == ' ':
                reverse(start, end - 1)
                start = end + 1