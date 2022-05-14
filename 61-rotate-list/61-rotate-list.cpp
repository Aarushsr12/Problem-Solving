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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int len = 1;
        while(temp->next){
            temp = temp ->next;
            len++;
        }
        temp->next = head;
        ListNode* temp1 = NULL;
        k = k % len;
        k = len - k;

        while(k>=0){
            temp1 = temp;
            temp = temp->next;
            k--;
        }
        temp1->next = NULL;
        return temp;
    }
};