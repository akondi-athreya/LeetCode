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
    ListNode* fun(ListNode* head , ListNode*x){
        if(head==NULL) return x;
        
        ListNode*next=head->next;
        head->next=x;
        x=head;
        return fun(next,x);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* x=NULL;
        return fun(head,x);
    }
};