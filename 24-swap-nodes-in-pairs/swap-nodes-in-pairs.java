/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0,head);
        ListNode prev = dummy, cur = head;

        while (cur != null && cur.next != null){
            ListNode temp = cur.next.next;
            ListNode temp2 = cur.next;

            temp2.next = cur;
            cur.next = temp;
            prev.next = temp2;

            prev = cur;
            cur = temp;
        }
        return dummy.next;

    }
}

