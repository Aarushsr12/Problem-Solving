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
    int length(ListNode *head){
        int count=0;
        while(head != NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode *temp = head;
        int len = length(temp);
        if(len == n){
            return temp->next;
        }
        int skip = 1;
        while(temp != NULL && skip <len-n){
            skip++;
            temp = temp->next;
        }
        ListNode *a = temp->next;
        temp->next = a->next;
        delete a;
        return head;
    }
};