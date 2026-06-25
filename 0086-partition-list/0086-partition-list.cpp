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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);
        ListNode* sp = l1;
        ListNode* lp = l2;

        while (head != NULL) {
            if (head->val < x) {
                sp->next = head;
                sp = sp->next;
            }
            else {
                lp->next = head;
                lp = lp->next;
            }
            head = head->next;
        }
        sp->next = l2->next;
        lp->next = NULL;
        return l1->next;
    }
};