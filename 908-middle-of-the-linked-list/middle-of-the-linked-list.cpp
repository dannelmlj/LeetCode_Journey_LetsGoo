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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> myVec;
        while (head->next != NULL){
            myVec.push_back(head);
            head = head->next;
        }
        myVec.push_back(head);
        int mid = myVec.size()/2;

        return myVec[mid];
    }
};