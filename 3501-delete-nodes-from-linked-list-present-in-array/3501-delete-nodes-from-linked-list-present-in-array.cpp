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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (st.count(cur->val)) {
                prev->next = cur->next;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};