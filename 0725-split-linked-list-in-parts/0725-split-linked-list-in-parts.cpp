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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;
        while (curr) {
            cnt++;
            curr = curr->next;
        }
        int each = cnt/k;
        int rem = cnt%k;

        vector<ListNode*> v(k, NULL);

        curr = head;
        ListNode* prev = NULL;

        for (int i = 0 ; curr != NULL && i < k ; i++) {
            v[i] = curr;

            for (int j = 1 ; j <= each + (rem > 0 ? 1 : 0) ; j++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            rem--;
        }
        return v;
    }
};