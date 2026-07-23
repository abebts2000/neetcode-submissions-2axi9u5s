class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        newh = ListNode()
        temp = newh
        while head:
            if head.val == val:
                head = head.next
            else:
                temp.next = head
                temp = temp.next
                head = head.next
        temp.next = None
        return newh.next