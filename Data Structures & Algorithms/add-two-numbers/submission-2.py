# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        head = res
        c=0
        while l1 or l2 or c:
            sum = c
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2= l2.next
            c = sum//10
            res.next = ListNode(sum%10)
            res = res.next
        return head.next
        
        

        