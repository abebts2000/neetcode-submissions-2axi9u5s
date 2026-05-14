"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def count1and0(r,c,length):
            c0,c1=0,0
            for i in range(r,r+length):
                for j in range(c,c+length):
                    if grid[i][j]==0:
                        c0+=1
                    else:
                        c1+=1
            if c0==length*length:
                return 0,True
            elif c1 ==length*length:
                return 1,True
            else:
                return None,False


        def helper(r,c,length):
            val,isleaf = count1and0(r,c,length)
            if isleaf:
                return Node(val == 1, True, None, None, None, None)
            node = Node(True, False)
            node.topLeft = helper(r,c,length//2)
            node.topRight = helper(r,c+length//2,length//2)
            node.bottomLeft = helper(r+length//2,c,length//2)
            node.bottomRight = helper(r+length//2,c+length//2,length//2)
            return node
        return helper(0,0,len(grid))

        