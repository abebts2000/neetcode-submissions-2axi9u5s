# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        st = set()
        l1 = headA
        while l1:
            st.add(l1)
            l1 = l1.next
        l2 = headB
        while l2:
            if l2 in st:
                return l2
            l2 = l2.next
        return None
