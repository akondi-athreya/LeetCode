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
    ListNode* middleNode(ListNode* head) {
        ListNode *cpy = head;
        int cnt = 0;
        while (cpy != NULL)
        {
            cnt += 1;
            cpy = cpy->next;
        }
        int k = cnt / 2;
        cpy = head;
        while (cpy != NULL)
        {
            if (k != 0)
            {
                k -= 1;
                cpy = cpy->next;
            }
            else{
                break;
            }
        }
        return cpy;
    }
};