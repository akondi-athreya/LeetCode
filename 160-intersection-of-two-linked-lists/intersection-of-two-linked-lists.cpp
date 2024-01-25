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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int cnt1 = 0 , cnt2 = 0;
        while(t1!=NULL){
            cnt1++;
            t1=t1->next;
        }
        while(t2!=NULL){
            cnt2++;
            t2=t2->next;
        }
        int diff;
        t1 = headA;
        t2 = headB;
        if(cnt2>cnt1){
            diff = cnt2-cnt1;
            while(t2!=NULL && diff!=0){
                diff--;
                t2=t2->next;
            }
        }
        else if(cnt2<cnt1){
            diff = cnt1-cnt2;
            while(t1!=NULL && diff!=0){
                diff--;
                t1=t1->next;
            }
        }
        while(t1!=NULL && t2!=NULL){
            if(t1==t2){
                return t1;
            }
            else if(t1->next==t2->next){
                return t1->next;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return 0;
    }
};