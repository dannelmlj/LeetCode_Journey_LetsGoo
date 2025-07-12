/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* traverseL1 = l1;
        ListNode* traverseL2 = l2;

        int carryOver = 0;
        int digit = 0;
        if (traverseL1->val + traverseL2->val + carryOver >= 10){
            digit = traverseL1->val + traverseL2->val + carryOver - 10;
            carryOver = 1;
        } else {
            digit = traverseL1->val + traverseL2->val + carryOver;
            carryOver = 0;
        }
        ListNode *head = new ListNode(digit);

        ListNode *traverseAnswer = head;

        traverseL1 = traverseL1->next;
        traverseL2 = traverseL2->next;

        while (traverseL1 != NULL || traverseL2 != NULL){
            if (traverseL1 != NULL && traverseL2 != NULL){
                if (traverseL1->val + traverseL2->val + carryOver >= 10){
                    digit = traverseL1->val + traverseL2->val + carryOver - 10;
                    carryOver = 1;
                } else {
                    digit = traverseL1->val + traverseL2->val + carryOver;
                    carryOver = 0;
                }
                traverseL1 = traverseL1->next;
                traverseL2 = traverseL2->next;
                
            } else if (traverseL1 == NULL && traverseL2 != NULL){
                if (traverseL2->val + carryOver >= 10){
                    digit = traverseL2->val + carryOver - 10;
                    carryOver = 1;
                } else {
                    digit = traverseL2->val + carryOver;
                    carryOver = 0;
                }
                traverseL2 = traverseL2->next;
                
            } else {
                if (traverseL1->val + carryOver >= 10){
                    digit = traverseL1->val + carryOver - 10;
                    carryOver = 1;
                } else {
                    digit = traverseL1->val + carryOver;
                    carryOver = 0;
                }
                traverseL1 = traverseL1->next;

            }
            traverseAnswer->next = new ListNode(digit);
            traverseAnswer = traverseAnswer->next;
        }
        if (carryOver){
            traverseAnswer->next = new ListNode(1);
        }

        return head;

    }
};