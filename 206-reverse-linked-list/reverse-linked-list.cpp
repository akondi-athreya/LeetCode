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
    ListNode* reverseList(ListNode* head) {
        ListNode* cpy = head;
        if(head==NULL){
            return 0;
        }
        ListNode* temp = new ListNode(cpy->val);
        cpy=cpy->next;

        ListNode* BC;
        while(cpy!=NULL){
            BC = new ListNode(cpy->val);
            BC->next = temp;
            temp = BC;
            cpy = cpy->next;
        }
        return temp;
    }
};