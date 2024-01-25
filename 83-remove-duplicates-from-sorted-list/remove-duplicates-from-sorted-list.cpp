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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* res;
        ListNode* cpy = head;
        ListNode* temp;
        int i=0;
        while(cpy!=NULL){
            if(i==0){
                res = new ListNode(cpy->val);
                temp = res;
                i+=1;
            }
            else{
                if(cpy->val>temp->val){
                    ListNode* BC = new ListNode(cpy->val);
                    temp->next = BC;
                    temp = temp->next;
                }
            }
            cpy=cpy->next;
        }
        return res;
    }
};