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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode* cpy1 = head;
        ListNode* cpy2 = cpy1->next;
        ListNode* prev = cpy2;
        while(cpy1->next!=NULL && cpy2->next!=NULL){
            cpy1->next = cpy1->next->next;
            cpy2->next = cpy2->next->next;
            cpy1=cpy1->next;
            cpy2=cpy2->next;
        }
        if(cpy1->next==NULL || cpy2->next==NULL){
            cpy1->next = prev;
        }
        return head;
    }
};