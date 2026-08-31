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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pv=0;
        int cv=0;
        int nv=0;
        int mind = INT_MAX;
        int fc=0;
        int pc=0;
        int i=0;
        vector<int> v = {-1,-1};
        while(head != NULL){
            pv = cv;
            cv = nv;
            nv = head->val;
            if(pv != 0 && cv!=0 && nv!=0 && ((pv>cv && cv<nv) || (pv<cv && cv>nv))){
                if(fc == 0) fc = i;
                else{
                    mind = min(mind , i-pc);
                    v = {mind , i-fc};
                }
                pc = i;
            }
            i++;
            head = head->next;
        }
        return v;
    }
};