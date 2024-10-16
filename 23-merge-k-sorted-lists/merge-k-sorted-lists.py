# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        min_heap=[]
        output = ListNode()
        for listnodes in lists:
            while listnodes is not None:
                try:
                    heapq.heappush(min_heap, listnodes.val)
                    listnodes =listnodes.next
                except:
                    print("err")
        if len(min_heap)> 0:
            output = ListNode(heapq.heappop(min_heap))
            output_tail =output
        elif len(min_heap) == 0:
            return None
        for i in range(len(min_heap)):
            output_tail.next = ListNode(heapq.heappop(min_heap))
            output_tail =output_tail.next
        return output
        