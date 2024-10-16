# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        if head.next is None:
            return head
        output = ListNode(0, head)
        prev,cur = output,head

        while cur and cur.next:
            temp = cur.next.next
            temp2 = cur.next
            
            temp2.next = cur
            cur.next = temp
            prev.next = temp2

            prev = cur
            cur = temp

        return(output.next)