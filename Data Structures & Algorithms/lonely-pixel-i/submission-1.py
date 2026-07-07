class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        if not picture or not picture[0]:
            return 0
        
        rows, cols = len(picture), len(picture[0])
        row_count = [0] * rows
        col_count = [0] * cols
        
        for r in range(rows):
            for c in range(cols):
                if picture[r][c] == 'B':
                    row_count[r] += 1
                    col_count[c] += 1
        
        lonely_pixels = 0
        for r in range(rows):
            for c in range(cols):
                if picture[r][c] == 'B' and row_count[r] == 1 and col_count[c] == 1:
                    lonely_pixels += 1
                    
        return lonely_pixels