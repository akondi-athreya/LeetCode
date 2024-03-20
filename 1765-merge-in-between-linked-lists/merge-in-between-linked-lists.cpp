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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* slow = list1;
        ListNode* fast = list1;
        while(a!=1){
            slow = slow->next;
            fast = fast->next;
            a--;
            b--;
        }
        while(b--){
            fast = fast->next;
        }
        fast = fast->next;
        slow->next = list2;
        while(slow->next != NULL){
            slow = slow->next;
        }
        slow->next = fast;
        return list1;
    }
};