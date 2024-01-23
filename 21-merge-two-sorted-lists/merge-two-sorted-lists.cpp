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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cpy1 = list1;
        ListNode* cpy2 = list2;
        
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }

        int flag = 0;
        ListNode* temp1 ;
        ListNode* temp2 ;
        int i=0;
        while(cpy1!=NULL && cpy2!=NULL){
            if(cpy1->next==NULL){
                flag = 1;
            }
            else if (cpy2->next==NULL)
            {
                flag = 2;
            }
            
            if(cpy1->val<=cpy2->val){
                int x = cpy1->val;
                if(i==0){
                    temp1 = new ListNode(x);
                    temp2 = temp1;
                    i+=1;
                }
                else{
                    ListNode* BC = new ListNode(x);
                    temp2->next=BC;
                    temp2=temp2->next;
                }
                cpy1 = cpy1->next;
            }
            else{
                int x = cpy2->val;
                if(i==0){
                    temp1 = new ListNode(x);
                    temp2 = temp1;
                    i+=1;
                }
                else{
                    ListNode* BC = new ListNode(x);
                    temp2->next=BC;
                    temp2=temp2->next;
                }
                cpy2 = cpy2->next;
            }
            if(cpy1==NULL){
                flag = 1;
                break;
            }
            else if(cpy2==NULL){
                flag = 2;
                break;
            }
        }
        if(flag==1){
            temp2->next = cpy2;
        }
        else if(flag==2){
            temp2->next = cpy1;
        }
        return temp1;
    }
};