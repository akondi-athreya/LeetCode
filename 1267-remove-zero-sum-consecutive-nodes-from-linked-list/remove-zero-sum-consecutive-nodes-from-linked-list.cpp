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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> M;
        M[0] = NULL;
        int preSum = 0;
        auto ptr = head;
        while (ptr)
        {
            preSum += ptr->val;
            if (M.count(preSum) == 0)
            {
                M[preSum] = ptr;
                ptr = ptr->next;
                continue;
            }
            if (M[preSum] == NULL)
            {
                head = ptr->next;
                ptr = ptr->next;
                M.clear();
                M[0] = NULL;
                continue;
            }
            auto x = M[preSum];
            int currSum = preSum;
            while (x->next != ptr)
            {
                x = x->next;
                currSum += x->val;
                M.erase(currSum);
            }
            M[preSum]->next = ptr->next;
            ptr = ptr->next;
        }
        return head;
    }
};