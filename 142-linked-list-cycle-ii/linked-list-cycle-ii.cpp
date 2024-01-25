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
    ListNode *detectCycle(ListNode *head) {
        ListNode* cpy = head;
        if(head==NULL){
            return NULL;
        }
        if(cpy->next==NULL){
            return 0;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        if(fast->next==NULL || fast->next->next==NULL){
            return NULL;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(fast->next==NULL || fast->next->next==NULL){
            return NULL;
        }
        while(cpy!=NULL){
            if(slow==cpy){
                return slow;
            }
            cpy=cpy->next;
            slow=slow->next;
        }
        return NULL;
    }
};