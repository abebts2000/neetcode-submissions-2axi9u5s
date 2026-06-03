# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        memo = {}
        def rob2(root: Optional[TreeNode], skip):
            if not root:
                return 0
            state = (root, skip)
            if state in memo:
                return memo[state]
            if skip:
                res = rob2(root.left, False) + rob2(root.right, False)
            else:
                rob_current = root.val + rob2(root.left, True) + rob2(root.right, True)
                skip_current = rob2(root.left, False) + rob2(root.right, False)
                res = max(rob_current, skip_current)
            memo[state] = res
            return res
        return rob2(root, False)