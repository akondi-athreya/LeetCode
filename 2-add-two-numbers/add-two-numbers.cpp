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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cpy1 = l1;
        ListNode* cpy2 = l2;
        ListNode* res;
        ListNode* temp;
        int i=0;
        int x =0, y =0, carry=0;
        while(cpy1!=NULL || cpy2!=NULL || carry!=0){
            x =0, y =0;
            if(cpy1!=NULL) 
            {
                x = cpy1->val;
                cpy1=cpy1->next;
            }
            if(cpy2!=NULL){
                y = cpy2->val;
                cpy2 = cpy2->next;
            }
            int z = (carry+x+y)%10;
            carry = (x+y+carry)/10;
            if(i==0){
                res = new ListNode(z);
                temp = res;
                i+=1;
            }
            else{
                ListNode* BC = new ListNode(z);
                temp->next=BC;
                temp=temp->next;
            }  
        }
        if(carry>0){
            ListNode* BC = new ListNode(1);
            temp->next=BC;
            temp=temp->next;
        }
        return res;
    }
};