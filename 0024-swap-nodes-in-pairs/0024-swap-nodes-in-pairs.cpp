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
    ListNode* swapPairs(ListNode* head) {
        //iterative
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        ListNode *curr = head;
        dummy->next = head;
        while(curr != NULL && curr->next != NULL){
            prev->next = curr->next;
            curr->next = curr->next->next;
            
            // now 2 - > 1
            //prev->next = 2
            prev->next->next = curr;
            //now update the curr & prev values
            curr = curr->next;
            prev = prev->next->next;
        }
        return dummy->next;
    }
};