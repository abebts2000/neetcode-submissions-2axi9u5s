# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        l1,l2 = headA,headB
        c1,c2 = 0,0
        while l1:
            c1+=1
            l1 = l1.next
        while l2:
            c2+=1
            l2 = l2.next
        diff = abs(c1-c2)
        l1,l2 = headA,headB
        while c1 > c2:
            l1 = l1.next
            c1-=1
        while c2 > c1:
            l2 = l2.next
            c2-=1
        while l1 and l2:
            if l1 == l2:
                return l1
            l1 = l1.next
            l2 = l2.next
        return None

