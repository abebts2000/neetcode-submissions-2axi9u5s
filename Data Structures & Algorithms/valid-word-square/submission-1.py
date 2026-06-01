class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        n = len(words)
        for r in range(n):
            for c in range(len(words[r])):
                # Check if the column index is within range of the list of words
                # AND if the row index is within range of that specific column's word string
                if c >= n or r >= len(words[c]) or words[r][c] != words[c][r]:
                    return False
        return True