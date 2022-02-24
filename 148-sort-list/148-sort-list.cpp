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
    ListNode *merge(ListNode *head1,ListNode *head2){
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        ListNode *fhead;
        if(head1->val > head2->val){
            fhead = head2;
            fhead->next = merge(head1,head2->next);
        }
        else{
            fhead = head1;
            fhead->next = merge(head1->next,head2);
        }
        return fhead;
    }
    int length(ListNode *head){
        int count=0;
        while(head!= NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* sortList(ListNode* head) {
        //merge sort
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *temp = head;
        int len = length(temp);
        int mid = len/2;
        while(mid>1){
            temp = temp->next;
            mid--;
        }
        ListNode *part1 = head;
        ListNode *part2 = temp->next;
        temp->next = NULL;
        part1 = sortList(part1);
        part2 = sortList(part2);
        return merge(part1,part2);
    }
};