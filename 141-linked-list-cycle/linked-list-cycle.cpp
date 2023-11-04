/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL ){
            return false;
        }
        ListNode *fastPointer = head->next;

        while (true){
            if (fastPointer == NULL || fastPointer->next == NULL || fastPointer->next->next == NULL){
                return false;
            }
            if (fastPointer == head){
                return true;
            }
            head = head->next;
            fastPointer = fastPointer->next->next;
        }
    }
};