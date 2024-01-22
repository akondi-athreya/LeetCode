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
    ListNode* removeNodes(ListNode* head) {
        ListNode* cpy = head;
        ListNode* temp = new ListNode(cpy->val);
        cpy=cpy->next;
        ListNode* BC;
        while(cpy!=NULL){
            BC = new ListNode(cpy->val);
            BC->next = temp;
            temp = BC;
            cpy = cpy->next;
        }
        cpy = temp;
        int max = cpy->val;
        
        while(cpy->next!=NULL){
            if((cpy->next->val)>max){
                max = cpy->next->val;
                cpy=cpy->next;
            }
            else if((cpy->next->val)<max){
                cpy->next = cpy->next->next;
            }
            else{
                cpy = cpy->next;
            }
        }
        cpy = temp;
        ListNode* temp1 = new ListNode(cpy->val);
        cpy=cpy->next;
        while(cpy!=NULL){
            BC = new ListNode(cpy->val);
            BC->next = temp1;
            temp1 = BC;
            cpy = cpy->next;
        }
        return temp1;
    }
};