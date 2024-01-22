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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cpy = head;
        int cnt=0;
        while(cpy!=NULL){
            cnt++;
            cpy=cpy->next;
        }
        int pos = cnt-n;
        cpy=head;
        if(head==NULL){
            return 0;
        }
        if(cnt==1){
            return 0;
        }
        if(pos==0){
            cpy=cpy->next;
            return cpy;
        }
        
        while(pos-1!=0 && cpy->next!=NULL){
            pos-=1;
            cpy = cpy->next;
        }
        if(cpy->next!=NULL)
            cpy->next = cpy->next->next;
        return head;
    }
};